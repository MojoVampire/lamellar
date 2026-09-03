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

The default Lamellar feature set (`with-pmix`, `vendored-pmi`,
`enable-lamellar-main`, `enable-numa-detect`, `vendored-libevent`,
`vendored-pmix`) builds the required PMIx/PRRTE launch stack — PMIx, PRRTE,
and libevent — from vendored sources. hwloc is the exception: it's linked
from a system install by default, normally discovered through `pkg-config`;
install both the hwloc development package and `pkg-config` (or `pkgconf`).
Enable `vendored-hwloc` instead if no suitable system hwloc is available (see
[Build prerequisites](#build-prerequisites) for what that needs).

To use a distributed transport, enable one feature in your application's
`Cargo.toml`:

```toml
[dependencies]
lamellar = { version = "…", features = ["enable-libfabric"] }
# Or: "enable-ucx", "enable-rofi-c", or "enable-rofi-c-pmix"
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
| `pkg-config` / `pkgconf` | Default system hwloc discovery | Also useful when a system PMIx or PRRTE installation is used. |
| hwloc development files | Default launcher configuration | Normally found through `pkg-config`; see the version guidance below. |
| RDMA development files (`libibverbs`, `librdmacm`) | libfabric, UCX, and ROFI | Required by Lamellar's current native link directives. |
| `libnuma`, `libuuid`, `libatomic` development files | libfabric and ROFI | Required by Lamellar's current native link directives. |

You do **not** need Git, Autoconf, Automake, Libtool, or Flex for the default
Lamellar vendored build. Lamellar's checked-in native sources use generated
configuration files, with their maintainer-mode regeneration rules disabled by
default. The default vendored libevent/OpenSSL dependency chain still requires
CMake and Perl, as listed above.

The optional `vendored-hwloc` feature is an exception: on Unix,
the transitive `hwlocality` crate runs `autoreconf -ivf` before building
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
| `enable-rofi-c`, `enable-rofi-c-shared` | ROFI and libfabric / OFI | ROFI's own PMI-1 client (`simple_pmi.c`); no PMIx | ROFI and libfabric |
| `enable-rofi-c-pmix`, `enable-rofi-c-shared-pmix` | ROFI and libfabric / OFI | PMIx (only; not selectable) | ROFI, libfabric, and PMIx |

The `enable-rofi-rust` feature currently does not activate a native dependency
by itself.

`enable-rofi-c`/`enable-rofi-c-shared` build ROFI against its own bundled
PMI-1 client — no PMIx, and nothing routed through Lamellar's `pmi`
process-management abstraction, so there's nothing to vendor beyond ROFI and
libfabric themselves. Layer `enable-rofi-c-pmix`/`enable-rofi-c-shared-pmix`
on top to switch ROFI's process management to PMIx instead: this turns on
`rofi-sys`'s own `pmix` Cargo feature, which passes ROFI's C-library
`configure` step a `--with-pmix` pointing at `pmix-sys` (see [rofi-sys's
README](communication_frameworks/rofi-sys/README.md)). ROFI has no PMI-2
client, so PMI-1/PMIx are the only two options.

`rofi-sys` itself separates using PMIx from vendoring it: `pmix` just turns
on PMIx support, and a separate `vendored-pmix` feature
(`pmix-sys?/openpmix-src`) is what vendors it. Lamellar's own
`enable-rofi-c-pmix`/`enable-rofi-c-shared-pmix` features only turn on
`rofisys/pmix` — vendoring is left to Lamellar's top-level `vendored-pmix`
feature (on by default, and already wired to `rofisys?/vendored-pmix`).
Drop `vendored-pmix` and set `PMIX_LIB_DIR`/`PMIX_INCLUDE_DIR` to link a
system PMIx for ROFI through the `lamellar` crate directly — no need to
depend on `rofisys` yourself.

## Choosing a process manager

The distributed transports use Lamellar's `pmi` abstraction. Choose the
provider that matches your cluster's launcher:

| Feature | Native library | System-library variables | Vendored source |
| --- | --- | --- | --- |
| `with-pmi1` | `libpmi` | `PMI_LIB_DIR`, `PMI_INCLUDE_DIR` | MPICH `libpmi` 5.0.0 |
| `with-pmi2` | `libpmi2` | `PMI2_LIB_DIR`, `PMI2_INCLUDE_DIR` | MPICH `libpmi` 5.0.0 |
| `with-pmix` (default) | `libpmix` | `PMIX_LIB_DIR`, `PMIX_INCLUDE_DIR` | OpenPMIx 5.0.9 |
| `enable-lamellar-main` (default) | `libprrte`, `prterun` | `PRRTE_LIB_DIR`, `PRRTE_INCLUDE_DIR`, `PRRTE_BIN_DIR` | PRRTE 3.0.14 |

The default feature set pairs `with-pmix` with a separate `vendored-pmi`
feature to vendor it, rather than a single combined switch — same effect,
just decomposed so vendoring can be dropped independently of picking PMIx.
The same generic `vendored-pmi` toggle pairs with whichever of `with-pmi1`/
`with-pmi2`/`with-pmix` is selected. The `pmi` sub-crate's own per-backend
aliases (`with-pmi1-vendored`, `with-pmi2-vendored`, `with-pmix-vendored`)
aren't all re-exposed at the `lamellar` crate level — only
`with-pmix-vendored` is. Use `with-pmi1`/`with-pmi2` + `vendored-pmi`
instead of guessing at a `with-pmi1-vendored`-style name.

PMIx and PRRTE also need libevent and hwloc. The default features vendor
libevent (`vendored-libevent`) and use a system hwloc. Enable `vendored-hwloc`
if no suitable system hwloc is available.

**Setting the `*_LIB_DIR`/`*_INCLUDE_DIR`/`*_BIN_DIR` variables above is not
enough by itself.** `enable-lamellar-main` always builds PRRTE from its
bundled source (`prrte-sys/prrte-src` is unconditional, independent of the
`vendored-*` toggles), and `pmix-sys`/`openpmix-src` behave the same way once
pulled in. Their build scripts only skip that vendored build and fall back to
the system directories when `PRRTE_NO_VENDORED=1` / `PMIX_NO_VENDORED=1` is
also set. Without those, the vendored source is still compiled even if
`PRRTE_LIB_DIR`/`PMIX_LIB_DIR` etc. are set. This only applies when the
vendored build is actually part of the feature set to begin with:
`enable-lamellar-main` always pulls in `prrte-sys/prrte-src` unconditionally,
so `PRRTE_NO_VENDORED` is always relevant there, but `pmix-sys`'s vendored
build (`openpmix-src`) is gated behind Lamellar's own `vendored-pmix`
feature. Drop `vendored-pmix` (or never select it — e.g. picking `with-pmix`
outside the default launcher stack, as when pairing it with `enable-libfabric`
alone) and `openpmix-src` is never compiled in, so `PMIX_NO_VENDORED` has no
effect either way — setting `PMIX_LIB_DIR`/`PMIX_INCLUDE_DIR` alone is
sufficient in that case. `enable-numa-detect` (hwloc) is
independent of both — it's best-effort NUMA/core-topology detection used by
`#[lamellar::main]`'s PE-placement defaults; without it, that detection falls
back to scanning `/sys` instead of using `hwlocality`. `enable-lamellar-main`
does not require it.

## Full system build of the default launch stack

The default feature set is `with-pmix`, `vendored-pmi`, `enable-lamellar-main`,
`enable-numa-detect`, `vendored-libevent`, `vendored-pmix` — the
`#[lamellar::main]` PMIx/PRRTE launcher, with PMIx/PRRTE/libevent vendored and
hwloc already linked from the system. A `system-pmix-launcher` convenience
alias expands to the same feature set minus the three vendoring features —
use it on a cluster with a system-installed, version-matched PMIx/PRRTE
(and libevent) already on `PKG_CONFIG_PATH` or pointed to via env vars:

```toml
lamellar = { version = "…", default-features = false, features = ["system-pmix-launcher"] }
```

```bash
PMIX_LIB_DIR=/path/to/pmix/lib PMIX_INCLUDE_DIR=/path/to/pmix/include PMIX_NO_VENDORED=1 \
PRRTE_LIB_DIR=/path/to/prrte/lib PRRTE_INCLUDE_DIR=/path/to/prrte/include PRRTE_BIN_DIR=/path/to/prrte/bin PRRTE_NO_VENDORED=1 \
LIBEVENT_DIR=/path/to/libevent \
cargo build
```

`PMIX_NO_VENDORED=1`/`PRRTE_NO_VENDORED=1` are required, not optional — dropping
`vendored-pmix`/`vendored-libevent` only stops those *sub*-dependencies of
PMIx/PRRTE from being vendored; PMIx and PRRTE themselves are still built
from bundled source unless their own `*_NO_VENDORED` variable says otherwise.
`LIBEVENT_DIR` can be omitted if a system libevent is already discoverable
via `pkg-config`. hwloc needs no override here — it's already linked from
the system by default; only set `HWLOC_DIR` (and add
`$HWLOC_DIR/lib/pkgconfig` to `PKG_CONFIG_PATH`) if you'd separately turned on
`vendored-hwloc` and want to opt back out, or if hwloc isn't on the default
`pkg-config` search path.

To vendor only some of the three, restate the default list minus the one
feature you want to drop instead of using `system-pmix-launcher`, e.g. keep
PMIx/PRRTE vendored but link libevent from a system install:

```toml
lamellar = { version = "…", default-features = false, features = ["with-pmix", "vendored-pmi", "enable-lamellar-main", "enable-numa-detect", "vendored-pmix"] }
```

```bash
LIBEVENT_DIR=/path/to/libevent cargo build
```

## Using system installations for the transport libraries

Set an install prefix or include/lib directory before running Cargo. Lamellar
will prefer these values over its bundled source where applicable.

| Library | Configuration |
| --- | --- |
| libfabric | `OFI_DIR=/path/to/prefix` |
| UCX | `UCX_DIR=/path/to/prefix` |
| UCC | `UCC_DIR=/path/to/prefix` |
| ROFI | `ROFI_DIR=/path/to/prefix` |

`enable-rofi-c-pmix`/`enable-rofi-c-shared-pmix` vendor PMIx only through
Lamellar's `vendored-pmix` feature (on by default) — drop it and set
`PMIX_LIB_DIR`/`PMIX_INCLUDE_DIR` to link a system PMIx for ROFI too; see
the note in the backend dependencies table above.

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
- **Build still compiles PMIx/PRRTE from source despite `*_LIB_DIR` being
  set:** also set `PMIX_NO_VENDORED=1`/`PRRTE_NO_VENDORED=1` — the directory
  variables alone don't skip the vendored build.
- **Cluster-provided PMIx or PRRTE is incompatible:** use `system-pmix-launcher`
  (or restate the default list minus the vendoring feature for just the one
  piece that's incompatible) with the env vars above instead of the vendored
  default.

For implementation details and exact feature wiring, see
`lamellar-runtime/Cargo.toml` and the `README.md` files next to each `*-sys`
or `*-src` crate.
