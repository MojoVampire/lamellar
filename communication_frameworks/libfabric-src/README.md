# libfabric-src

This crate vendors the official [libfabric](https://github.com/ofiwg/libfabric) release tarball (v1.22.0 — the pre-generated "make dist" tarball from GitHub Releases, not a git checkout) under `libfabric/`, copies it into `OUT_DIR`, and invokes Autotools to build the chosen configuration (shared or static) while honoring an optional `OFI_DIR` override. Because the vendored tree came from the tarball, `configure` is already generated, so no `autogen.sh`/`autoreconf` step is run and no Flex/Autoconf/Automake/Libtool toolchain is required on the build machine. The build helper also bundles wrapper generation for inline functions so the Rust bindings in `libfabric-sys` can link to them.

Unlike PMIx/PRRTE's Sphinx docs bundle, this crate does **not** strip the tarball's `man/` pages: they're wired as an unconditional prerequisite of the generated `install` target with no configure-time opt-out, so removing them would break `make install`.

**One deviation from the pristine tarball**: `libfabric/configure.ac` has a small Lamellar-added `AM_MAINTAINER_MODE` macro (see the `dnl Lamellar addition` comment right after `AM_INIT_AUTOMAKE`), and `aclocal.m4`/`configure`/`config.h.in`/every `Makefile.in` were regenerated once locally (via `autoreconf -ivf`, using this machine's autoconf/automake/libtool/flex) to bake that guard in. Without it, libfabric's generated Makefile unconditionally re-invokes the exact `aclocal`/`automake` version the release was built with whenever any file's mtime looks "stale" — which vendoring into git guarantees, since checkout/copy doesn't preserve the original tarball's relative timestamps. Every other file is untouched upstream content.

## Usage

`libfabric-sys` and other downstream crates depend on this helper indirectly through the build script. No direct dependency is necessary: cargo sets `libfabric-src` as a build dependency, and it prints the `include`/`lib` paths for upstream binding generation.


STATUS
------
Libfabric-src has been developed as part of the Lamellar project and is still under development, thus not all intended features are yet
implemented.

CONTACTS
--------

Current Team Members

Ryan Friese           - ryan.friese@pnnl.gov 

Past Team Members

Polykarpos Thomadakis

## License

This project is licensed under the BSD License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

This work was supported by the High Performance Data Analytics (HPDA) Program at Pacific Northwest National Laboratory (PNNL),
a multi-program DOE laboratory operated by Battelle.