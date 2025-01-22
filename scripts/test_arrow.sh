#!/usr/bin/bash

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
cd $DIR

set -u
set -e
set -x

BASE_DIR=$DIR"/.."
ARROW_LIB_DIR=$BASE_DIR"/external/arrow/cpp/install/lib"
BUILD_DIR=$BASE_DIR"/build"
UNITTEST_DIR=$BUILD_DIR"/unittest"

cd $UNITTEST_DIR

./arrow_data_structure
./arrow_file_io
./arrow_compute
