
use std::{env, path::PathBuf};
use std::path::Path;

/// Vendored UCC release: unlike UCX/libfabric/MPICH-PMI, upstream has never
/// published an official "make dist" tarball for UCC. This is a Lamellar
/// hand-generated tarball -- a fresh checkout of git tag v1.8.0, `./autogen.sh
/// && ./configure && make dist` run locally -- not an official release
/// artifact. See README.md for the full provenance disclosure. UCC's
/// configure.ac already carries upstream's own AM_MAINTAINER_MODE, so no
/// Lamellar patch was needed there (unlike libfabric/MPICH-PMI).
const UCC_VERSION: &str = "1.8.0";

fn remove_dst_forcibly(dst: &Path) {
    match std::fs::remove_file(dst) {
        Ok(_) => {}
        Err(e) if e.kind() == std::io::ErrorKind::PermissionDenied => {
            #[cfg(unix)]
            {
                use std::os::unix::fs::PermissionsExt;
                if let Ok(mut perms) = std::fs::metadata(dst).map(|m| m.permissions()) {
                    perms.set_mode(0o666);
                    let _ = std::fs::set_permissions(dst, perms);
                }
            }
            let _ = std::fs::remove_file(dst);
        }
        Err(_) => {}
    }
}

fn copy_rec(src: &Path, dst: &Path) -> std::io::Result<()> {
    if src.is_dir() {
        if dst.exists() && !dst.is_dir() {
            remove_dst_forcibly(dst);
        }
        std::fs::create_dir_all(dst)?;
        for entry in std::fs::read_dir(src)? {
            let entry = entry?;
            let src_path = entry.path();
            let dst_path = dst.join(entry.file_name());
            copy_rec(&src_path, &dst_path)?;
        }
    } else {
        if let Some(parent) = dst.parent() {
            std::fs::create_dir_all(parent)?;
        }
        if dst.exists() {
            remove_dst_forcibly(dst);
        }
        std::fs::copy(src, dst)?;
    }
    Ok(())
}

fn build_ucc(out_path: &PathBuf) -> PathBuf {
    println!("cargo:warning=building vendored UCC {}", UCC_VERSION);

    let ucx_root_path = std::env::var("DEP_UCX_ROOT").expect("Could not find UCX installation.");
    let _ucx_lib_path = std::path::PathBuf::from(&ucx_root_path).join("lib");
    let _ucx_include_path = std::path::PathBuf::from(&ucx_root_path).join("include");


    let dest = out_path.clone().join("ucc_src");
    copy_rec(&std::path::PathBuf::from("ucc"), &dest).expect("Failed to copy UCC source files");

    let src_path = std::fs::canonicalize(&dest).unwrap();

    // No autogen.sh / autoreconf here: the vendored tree already ships a
    // pre-generated `configure` (see the provenance note on UCC_VERSION above).
    let path = autotools::Config::new(&src_path)
        .enable_shared()
        .disable_static()
        .with("rocm", Some("no"))
        .with("cuda", Some("no"))
        .enable("optimizations", None)
        .with("ucx", Some(&ucx_root_path))
        .build();
    path
}

fn build_bindings() {
    let out_path = PathBuf::from(env::var("OUT_DIR").unwrap());

    println!("cargo:rerun-if-env-changed=UCC_DIR");
    let ucc_path = match env::var("UCC_DIR") {
        Ok(val) => std::path::PathBuf::from(val),
        Err(_) => {
            let out_dir = PathBuf::from(env::var("OUT_DIR").unwrap());
             println!("cargo:warning=UCC_DIR environment variable not set, building UCC from source. This may take a while. To use a pre-built version of UCC, set the UCC_DIR environment variable to the path of the UCC installation.");
             build_ucc(&out_dir)
        }
    };
    println!("cargo:root={}", ucc_path.display());

    let mut builder = cc::Build::new();
    builder.file("wrapper.c");
    builder.include(&ucc_path.join("./include"));
    builder.compile("wrapper");

    let bindings = bindgen::Builder::default()
        .header("wrapper.h")
        .clang_arg(format!("-I{}", ucc_path.join("include").display()))
        .generate()
        .expect("Unable to generate bindings for UCC");

    bindings
        .write_to_file(out_path.join("bindings.rs"))
        .expect("Couldn't write bindings!");

    let ucc_lib_path = ucc_path.join("lib");
    println!(
        "cargo:rustc-link-arg=-Wl,-rpath,{}",
        ucc_lib_path.display()
    );
    println!("cargo:rustc-link-search={}", ucc_lib_path.display());
    if let Ok(ucx_root_path) = env::var("DEP_UCX_ROOT") {
        let ucx_lib_path = std::path::PathBuf::from(ucx_root_path).join("lib");
        println!(
            "cargo:rustc-link-arg=-Wl,-rpath,{}",
            ucx_lib_path.display()
        );
        println!("cargo:rustc-link-search={}", ucx_lib_path.display());
    }
    println!("cargo:rustc-link-lib=ucc");
    println!("cargo:rustc-link-lib=ucs");
    println!("cargo:rustc-link-lib=ucm");
}


fn main() {
    println!("cargo:rerun-if-changed={}", "build.rs");
    println!("cargo:rerun-if-changed={}", "wrapper.h");
    println!("cargo:rerun-if-changed={}", "wrapper.c");
    build_bindings();
}