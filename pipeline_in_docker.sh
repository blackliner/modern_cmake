#!/bin/bash

set -euxo pipefail

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

SHORT_GIT_HASH=$(git rev-parse --short HEAD)

DOCKER_TAG=modern_cmake:$SHORT_GIT_HASH

docker build $SCRIPT_DIR/docker --tag $DOCKER_TAG --network host

docker run --volume /tmp/conan_download_cache:/tmp/conan_download_cache:rw --network host $DOCKER_TAG bash -c "git clone https://github.com/blackliner/modern_cmake /tmp/modern_cmake && cd /tmp/modern_cmake && ./pipeline.sh"
