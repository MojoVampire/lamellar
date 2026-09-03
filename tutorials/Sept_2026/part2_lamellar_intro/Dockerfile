# syntax=docker/dockerfile:1

FROM rust:1-bookworm

LABEL description="Lamellar tutorial image: sept2026-part2"

RUN apt-get update \
    && DEBIAN_FRONTEND=noninteractive apt-get install -y \
        build-essential clang libclang-dev cmake perl flex pkg-config ca-certificates \
        libhwloc-dev libibverbs-dev librdmacm-dev patchelf \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /tutorial
COPY . .

RUN cargo fetch --locked
# Vendored UCX's autotools build defaults its submake -j to nproc; on
# high-core-count hosts, cargo's own -j (also nproc by default) runs several
# native sys-crate builds concurrently, each spawning their own -j4 submake —
# the combined fan-out can outrun the open-file-descriptor limit. Cap both.
ENV MAKEFLAGS=-j4
ENV CARGO_BUILD_JOBS=8
# src/main_*.rs are intentionally-broken exercises fixed live during the
# tutorial; only build the working solutions/*.rs reference bins plus hello.
RUN cargo build --locked --release \
    --bin hello \
    --bin solution_main \
    --bin solution_main_array_basics \
    --bin solution_main_am_deep_dive \
    --bin solution_main_array_types \
    --bin solution_main_capstone

# pmix-sys/lamellar-ucx-sys/lamellar-ucc-sys's rpath-emitting build.rs only
# propagates to the final binary when it's a direct dep of the top-level
# crate (as in lamellar-runtime's own image); here they're transitive deps
# behind the `lamellar` git dep, so a direct exec of the built binary fails
# with "cannot open shared object file". Not fixed here: `cargo run` avoids
# it (Cargo sets LD_LIBRARY_PATH from the native sys-crates' build-script
# link-search dirs when running the binary) and lamellar_main's hpc_launch
# self-heal (needs `patchelf`, installed above) then patches the on-disk
# RPATH in place on that first `cargo run` — see TUTORIAL_README.md's "run
# via cargo run once" note, which is how attendees are told to use this image.

RUN chmod -R a+rX /tutorial /usr/local/cargo

ENV PRTE_ALLOW_RUN_AS_ROOT=1
ENV PRTE_ALLOW_RUN_AS_ROOT_CONFIRM=1

WORKDIR /tutorial
