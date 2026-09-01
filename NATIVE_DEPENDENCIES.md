# Native dependencies

Lamellar is a Rust library, but distributed backends build and link native
communication and process-management libraries. This guide lists the packages
needed to build an application, and explains when Lamellar builds a bundled
copy instead of using a system installation.

For an ordinary single-node application using the `local` or `shmem` backend,
no transport library is needed.

## Quick start

All builds need a Rust toolchain, a C compiler/linker, GNU Make, CMake, Perl,
and Clang with the `libclang` development library (used by `bindgen`). Package
names vary by distribution; on Linux, the relevant packages are commonly named
`clang`, `libclang-dev`, `gcc`/`build-essential`, `make`, `cmake`, and `perl`.

The default Lamellar feature set builds the required PMIx/PRRTE launch stack
from vendored sources. It normally discovers a system **hwloc** installation
through `pkg-config`; install both the hwloc development package and
`pkg-config` (or `pkgconf`).

To use a distributed transport, enable one feature in your application's
`Cargo.toml`:

```toml
[dependencies]
lamellar = { version = "…", features = ["enable-libfabric"] }
# Or: "enable-ucx" or "enable-rofi-c"
```

## Build prerequisites

| Requirement | Needed for | Notes |
| --- | --- | --- |
| Rust (`rustc`, Cargo) | Every build | Lamellar does not currently declare a minimum Rust version in its manifest. |
| C compiler and linker | Native bindings and all vendored libraries | A standard GCC or Clang toolchain is sufficient. |
| GNU Make | Any vendored native library | Runs the generated Makefiles after configuration. |
| CMake | Default vendored libevent build | The transitive `libevent-sys` bundled build uses CMake. |
| Perl | Default vendored libevent build | Bundled libevent enables bundled OpenSSL; OpenSSL's source build runs Perl. |
| Clang and libclang development files | `*-sys` crates | Required by `bindgen` to generate Rust FFI bindings. |
| `pkg-config` / `pkgconf` | System hwloc/libevent discovery | Also useful when a system PMIx or PRRTE installation is used. |
| hwloc development files | Default launcher configuration | Normally found through `pkg-config`; see the version guidance below. |
| RDMA development files (`libibverbs`, `librdmacm`) | libfabric, UCX, and ROFI | Required by Lamellar's current native link directives. |
| `libnuma`, `libuuid`, `libatomic` development files | libfabric and ROFI | Required by Lamellar's current native link directives. |

You do **not** need Git, Autoconf, Automake, Libtool, or Flex for the default
Lamellar vendored build. Lamellar's checked-in native sources use generated
configuration files, with their maintainer-mode regeneration rules disabled by
default. The default vendored libevent/OpenSSL dependency chain still requires
CMake and Perl, as listed above.

The optional `vendored-hwloc` feature is an exception: on Unix,
the transitive `hwlocality-sys` crate runs `autoreconf -ivf` before building
hwloc. Enable it only with Autoconf, Automake, and Libtool installed. On
Windows, that crate uses CMake instead. Its vendored mode downloads an hwloc
release during the build, so it also needs network access. These Autotools
programs are otherwise only needed when regenerating or refreshing a vendored
source archive.

## Backend dependencies

| Lamellar feature | Native transport libraries | Process-management layer | Bundled when a system prefix is not provided |
| --- | --- | --- | --- |
| `local`, `shmem` | None | None | N/A |
| `enable-libfabric`, `enable-libfabric-sys`, `enable-libfabric-async` | libfabric / OFI | PMI-1, PMI-2, or PMIx (PMIx by default) | libfabric and the selected PMI implementation |
| `enable-ucx` | UCX and UCC | PMI-1, PMI-2, or PMIx (PMIx by default) | UCX, UCC, and the selected PMI implementation |
| `enable-rofi-c`, `enable-rofi-c-shared` | ROFI and libfabric / OFI | PMIx | ROFI, libfabric, and PMIx |

The `enable-rofi-rust` feature currently does not activate a native dependency
by itself.

## Choosing a process manager

The distributed transports use Lamellar's `pmi` abstraction. Choose the
provider that matches your cluster's launcher:

| Feature | Native library | System-library variables | Vendored source |
| --- | --- | --- | --- |
| `with-pmi1` | `libpmi` | `PMI_LIB_DIR`, `PMI_INCLUDE_DIR` | MPICH `libpmi` 5.0.0 |
| `with-pmi2` | `libpmi2` | `PMI2_LIB_DIR`, `PMI2_INCLUDE_DIR` | MPICH `libpmi` 5.0.0 |
| `with-pmix` (default) | `libpmix` | `PMIX_LIB_DIR`, `PMIX_INCLUDE_DIR` | OpenPMIx 5.0.9 |
| `enable-lamellar-main` | `libprrte`, `prterun` | `PRRTE_LIB_DIR`, `PRRTE_INCLUDE_DIR`, `PRRTE_BIN_DIR` | PRRTE 3.0.14 |

PMIx and PRRTE also need libevent and hwloc. The default features vendor
libevent and use a system hwloc. Enable `vendored-hwloc` if no suitable system
hwloc is available.

## Using system installations

Set an install prefix or include/lib directory before running Cargo. Lamellar
will prefer these values over its bundled source where applicable.

| Library | Configuration |
| --- | --- |
| libfabric | `OFI_DIR=/path/to/prefix` |
| UCX | `UCX_DIR=/path/to/prefix` |
| UCC | `UCC_DIR=/path/to/prefix` |
| ROFI | `ROFI_DIR=/path/to/prefix` |
| PMIx | `PMIX_LIB_DIR=/path/to/lib` and `PMIX_INCLUDE_DIR=/path/to/include`; optionally `PMIX_DIR=/path/to/prefix` for PRRTE configuration |
| PRRTE | `PRRTE_LIB_DIR=/path/to/lib`, `PRRTE_INCLUDE_DIR=/path/to/include`, and `PRRTE_BIN_DIR=/path/to/bin` |
| hwloc | `HWLOC_DIR=/path/to/prefix`; add `$HWLOC_DIR/lib/pkgconfig` to `PKG_CONFIG_PATH` if needed |
| libevent | `LIBEVENT_DIR=/path/to/prefix` |

For a cluster that already supplies a compatible PMIx/PRRTE/libevent stack,
use Lamellar without its default vendoring features:

```toml
lamellar = { version = "…", default-features = false, features = ["system-pmix-launcher"] }
```

## Version guidance

Lamellar validates symbols and headers, not most system-library version
numbers. The bundled versions below are the versions tested by this project.
Versions below a bundled version have **not been tested** and should not be
assumed to work, even where the build does not reject them. They are not
claimed minimum versions for a system installation.

| Component | Version / range |
| --- | --- |
| libfabric | Bundled 1.22.0; no system minimum enforced. |
| UCX | Bundled 1.20.0; no system minimum enforced. |
| UCC | Bundled 1.8.0; no system minimum enforced. |
| ROFI | Bundled from upstream commit `d112544`; no system minimum enforced. |
| OpenPMIx | Bundled 5.0.9. When using a system PMIx with bundled PRRTE: `4.2.4 <= PMIx < 6.0.0`. |
| PRRTE | Bundled 3.0.14; no system minimum enforced. |
| libevent | 2.0.21 or newer, built with pthread support. |
| hwloc | 1.11.0 through 2.x; 3.x is rejected by the bundled PMIx/PRRTE configuration. |

## Optional accelerators and providers

The vendored UCX and UCC configurations disable CUDA and ROCm. CUDA, ROCm,
GDRCopy, XPMEM, KNEM, and similar provider libraries are therefore not needed
for Lamellar's bundled build. They may be required if you point `UCX_DIR`,
`UCC_DIR`, or `OFI_DIR` at a custom system installation built with those
providers enabled.

## Troubleshooting

- **`bindgen` cannot find libclang:** install the libclang development package
  and ensure its library directory is visible to the dynamic loader.
- **hwloc is not found:** install its development package, or set `HWLOC_DIR`
  and `PKG_CONFIG_PATH` as shown above. On macOS, use a system hwloc; the
  vendored hwloc Autotools build may have issues there.
- **Linker errors for `ibverbs`, `rdmacm`, `numa`, or `uuid`:** install the
  matching RDMA/NUMA/UUID development packages for the enabled transport.
- **Cluster-provided PMIx or PRRTE is incompatible:** build with the default
  features to use Lamellar's bundled launch stack, or select the matching
  system PMI backend explicitly.

For implementation details and exact feature wiring, see
`lamellar-runtime/Cargo.toml` and the `README.md` files next to each `*-sys`
or `*-src` crate.
