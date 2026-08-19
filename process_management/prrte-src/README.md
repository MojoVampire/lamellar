# prrte-src

This crate vendors the official [PRRTE](https://github.com/openpmix/prrte) release tarball (v3.0.14 — the pre-generated "make dist" tarball from GitHub Releases, not a git checkout) under `prrte/`, copies it into the Cargo build directory, and runs its Autotools build configured with the provided `libevent`, `hwloc`, and PMIx directories. Because the vendored tree came from the tarball, `configure` is already generated, so no `autogen.pl`/`autoreconf` step is run and no Flex/Autoconf/Automake/Libtool toolchain is required on the build machine — that overhead only applies to developer builds from a git clone.

The tarball's pre-built Sphinx docs bundle (`docs/_build`) was stripped from the vendored tree, since no docs are installed — `configure` detects its absence and skips doc install cleanly.

The build helper exposes the produced `include`, `lib`, and `bin` directories via the exported `Artifacts` struct so the `prrte-sys` build script can link against the freshly built libraries.

For `libevent`/`hwloc`/`pmix`, the install prefix is resolved in this order: the `LIBEVENT_DIR`/`HWLOC_DIR`/`PMIX_DIR` env vars (for linking a system install directly), then the `DEP_EVENT_ROOT`/`DEP_HWLOC_ROOT`/`DEP_PMIX_ROOT` build-script metadata (set when those deps are vendored via `libevent-sys`/`hwlocality-sys`/`pmix-sys`), then a fallback derived from `DEP_EVENT_INCLUDE`/`DEP_HWLOC_INCLUDE` (or, for PMIx, omitted entirely so PRRTE's own `./configure` falls through to its built-in pkg-config auto-detection).


STATUS
------
prrte-src has been developed as part of the Lamellar project and is still under development, thus not all intended features are yet
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
