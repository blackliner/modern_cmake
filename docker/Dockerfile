from ubuntu:21.04 as start

run apt-get update && \
    DEBIAN_FRONTEND="noninteractive" \
    apt-get install -y \
    tzdata \
    clang-10 \
    cmake \
    git \
    python3-pip \
    ninja-build && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

run pip3 install conan
