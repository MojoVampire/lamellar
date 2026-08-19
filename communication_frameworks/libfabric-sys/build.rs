extern crate libfabric_src;

fn main() {
    let out_path = std::path::PathBuf::from(std::env::var("OUT_DIR").unwrap());

    let artifacts = libfabric_src::Build::new().build();
    
    // Generate the rust bindings
    let bindings = bindgen::Builder::default()
        // .clang_arg(format!("-I{}", ofi_include_path.to_str().unwrap()))
        // .header(out_path.to_str().unwrap().to_owned() + "/fabric_sys.h")
        // .blocklist_function("qgcvt")
        // .blocklist_function("qgcvt_r")
        // .blocklist_function("qfcvt")
        // .blocklist_function("qfcvt_r")
        // .blocklist_function("qecvt")
        // .blocklist_function("qecvt_r")
        // .blocklist_function("strtold")
        .header(artifacts.generated_header().to_str().unwrap())
        .clang_arg(format!("-I{}", artifacts.include_dir().to_str().unwrap()))
        .generate()
        .expect("Unable to generate bindings");

    // Write them to the respective file
    bindings
        .write_to_file(out_path.join("bindings.rs"))
        .expect("Couldn't write bindings!");

    // // Link with the libfabric and libinlined libraries to access their symbols.
    // println!("cargo:rustc-link-search={}", ofi_lib_path.display());
    // println!("cargo:rustc-link-search={}", out_path.display());

    // println!("cargo:rustc-link-lib=fabric");
    println!("cargo:rerun-if-changed={}", "build.rs");
    println!("cargo:root={}", artifacts.lib_dir().parent().unwrap_or(artifacts.lib_dir()).display());
    println!("cargo:rustc-link-search={}", artifacts.lib_dir().display());
    if cfg!(feature = "shared") {
        println!("cargo:rustc-link-lib=dylib=fabric");
    } else {
        println!("cargo:rustc-link-lib=static=fabric");
    }
    println!("cargo:rustc-link-lib=rt");
    println!("cargo:rustc-link-lib=rdmacm");
    println!("cargo:rustc-link-lib=ibverbs");
    println!("cargo:rustc-link-lib=atomic");
    println!("cargo:rustc-link-lib=pthread");
    println!("cargo:rustc-link-lib=dl");
    println!("cargo:rustc-link-lib=numa");
    println!("cargo:rustc-link-lib=uuid");
}
