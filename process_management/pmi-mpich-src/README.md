# pmi-mpich-src

This crate vendors upstream MPICH's official standalone [`libpmi`](https://github.com/pmodels/mpich) release tarball (v5.0.0 — the pre-generated "make dist" tarball, not a full MPICH git checkout) under `libpmi/`. Unlike the full MPICH tree, `libpmi` is self-contained: it embeds its own `mpl` module and needs none of MPICH's other bundled dependencies (hwloc, UCX, libfabric, json-c). The build script copies the `libpmi` tree into `OUT_DIR`, runs Autotools, and exposes the resulting headers and static libraries. Because the vendored tree came from the tarball, `configure` (and `mpl/configure`) is already generated, so no `autogen.sh`/`autoreconf` step is run and no Flex/Autoconf/Automake/Libtool toolchain is required on the build machine.

**One deviation from the pristine tarball**: both `libpmi/configure.ac` and `libpmi/mpl/configure.ac` carry a small Lamellar-added `AM_MAINTAINER_MODE` macro (see the `dnl Lamellar addition` comments), and both packages' `aclocal.m4`/`configure`/`Makefile.in`/`config.h.in` were regenerated once locally (via `autoreconf -ivf`) to bake that guard in. Without it, the generated Makefiles unconditionally re-invoke the exact `aclocal`/`automake` version the release was built with whenever any file's mtime looks "stale" — which vendoring into git guarantees, since checkout/copy doesn't preserve the original tarball's relative timestamps. Every other file is untouched upstream content.

The `pmi.patch` file lives here to tweak the upstream source (reworked for `libpmi`'s flat layout — `include/pmi.h`, `src/pmi_v1.c`, `src/pmi_v2.c`, no `src/pmi/` prefix) so it exposes clean headers and symbols for the Rust bindings. Building this crate is automatic when you enable the `vendored` feature in one of the PMI system crates.


STATUS
------
pmi-mpich-src has been developed as part of the Lamellar project and is still under development, thus not all intended features are yet
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
