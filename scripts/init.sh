#!/usr/bin/bash

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
cd $DIR

set -u
set -e
set -x

BASE_DIR=$DIR"/../"
cd $BASE_DIR

git submodule update --init --recursive

sudo apt-get update

sudo apt-get install \
     build-essential \
     ninja-build \
     cmake

ARROW_DIR=$BASE_DIR"/external/arrow/cpp"
cd $ARROW_DIR

rm -rf build
mkdir build
cd build

cmake .. --preset ninja-release 
cmake --build .
cmake --install .
