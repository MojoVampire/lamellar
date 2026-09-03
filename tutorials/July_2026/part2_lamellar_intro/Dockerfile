# syntax=docker/dockerfile:1

FROM rust:1-bookworm

LABEL description="Lamellar tutorial image: july2026-part2"

RUN apt-get update \
    && DEBIAN_FRONTEND=noninteractive apt-get install -y \
        build-essential clang libclang-dev cmake perl flex pkg-config ca-certificates \
        libhwloc-dev libibverbs-dev librdmacm-dev \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /tutorial
COPY . .

RUN cargo fetch --locked
# src/main_*.rs are intentionally-broken exercises fixed live during the
# tutorial; only build the working solutions/*.rs reference bins plus hello.
RUN cargo build --locked --release \
    --bin hello \
    --bin solution_main \
    --bin solution_main_array_basics \
    --bin solution_main_am_deep_dive \
    --bin solution_main_array_types \
    --bin solution_main_capstone

# crates.io pmix-sys 0.1.1's build.rs doesn't emit an rpath to the final
# binary (unlike lamellar-runtime's git-patched pmix-sys), so copy the
# built libpmix.so* onto the linker's default search path instead.
RUN find target/release/build/pmix-sys-*/out/lib -name 'libpmix.so*' -exec cp -P {} /usr/local/lib/ \; \
    && ldconfig

RUN chmod -R a+rX /tutorial /usr/local/cargo

ENV PRTE_ALLOW_RUN_AS_ROOT=1
ENV PRTE_ALLOW_RUN_AS_ROOT_CONFIRM=1

WORKDIR /tutorial
