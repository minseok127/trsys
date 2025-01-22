#!/usr/bin/bash

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
cd $DIR

set -u
set -e
set -x

BASE_DIR=$DIR"/.."
cd $BASE_DIR

git submodule update --init --recursive

sudo apt-get update

sudo apt-get install \
     build-essential \
     ninja-build \
     cmake

ARROW_DIR=$BASE_DIR"/external/arrow/cpp"
ARROW_BUILD_DIR=$ARROW_DIR"/build"
ARROW_INSTALL_DIR=$ARROW_DIR"/install"

rm -rf $ARROW_BUILD_DIR
rm -rf $ARROW_INSTALL_DIR

mkdir $ARROW_BUILD_DIR
mkdir $ARROW_INSTALL_DIR

cd $ARROW_BUILD_DIR

cmake .. --preset ninja-release -DCMAKE_INSTALL_PREFIX=$ARROW_INSTALL_DIR
cmake --build . -j1
cmake --install . --prefix $ARROW_INSTALL_DIR

