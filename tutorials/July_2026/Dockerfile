# syntax=docker/dockerfile:1

FROM rust:1-bookworm

LABEL description="Lamellar tutorial image: july2026"

RUN apt-get update \
    && DEBIAN_FRONTEND=noninteractive apt-get install -y \
        build-essential clang libclang-dev cmake perl flex pkg-config ca-certificates \
        libhwloc-dev libibverbs-dev librdmacm-dev patchelf \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /tutorial
COPY . .

WORKDIR /tutorial/part1_rust_basics
RUN cargo fetch --locked
RUN cargo build --locked --release

WORKDIR /tutorial/part2_lamellar_intro
RUN cargo fetch --locked
# src/main_*.rs are intentionally-broken exercises fixed live during the
# tutorial; only build the working solutions/*.rs reference bins plus hello.
RUN cargo build --locked --profile release-dev \
    --bin hello \
    --bin solution_main \
    --bin solution_main_array_basics \
    --bin solution_main_am_deep_dive \
    --bin solution_main_array_types \
    --bin solution_main_capstone

# A freshly-built binary's on-disk RPATH doesn't yet cover pmix-sys's
# build-output lib dir, so a direct exec fails with "cannot open shared
# object file". Not fixed here: `cargo run` avoids it (Cargo sets
# LD_LIBRARY_PATH from the native sys-crate's build-script link-search dir
# when running the binary) and `#[lamellar::main]` self-heals (via
# `readelf`/`patchelf`, installed above) by patching the on-disk RPATH in
# place on that first `cargo run` — see TUTORIAL_README.md's "run via
# cargo run once" note, which is how attendees are told to use this image.

RUN chmod -R a+rX /tutorial /usr/local/cargo

ENV PRTE_ALLOW_RUN_AS_ROOT=1
ENV PRTE_ALLOW_RUN_AS_ROOT_CONFIRM=1

WORKDIR /tutorial
