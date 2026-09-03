# syntax=docker/dockerfile:1

FROM rust:1-bookworm

LABEL description="Lamellar tutorial image: july2026-part1"

RUN apt-get update \
    && DEBIAN_FRONTEND=noninteractive apt-get install -y \
        build-essential clang libclang-dev cmake perl flex pkg-config ca-certificates \
        libhwloc-dev libibverbs-dev librdmacm-dev \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /tutorial
COPY . .

RUN cargo fetch --locked
RUN cargo build --locked --release

RUN chmod -R a+rX /tutorial /usr/local/cargo

ENV PRTE_ALLOW_RUN_AS_ROOT=1
ENV PRTE_ALLOW_RUN_AS_ROOT_CONFIRM=1

WORKDIR /tutorial
