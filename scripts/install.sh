#!/usr/bin/bash

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
cd $DIR

set -u
set -e
set -x

BUILD=Debug
BASE_DIR=$DIR"/.."
BUILD_DIR=$BASE_DIR"/build"

rm -rf $BUILD_DIR
mkdir -p $BUILD_DIR 
cd $BUILD_DIR

if [ ${BUILD} == "Release" ]
then
	cmake -DCMAKE_BUILD_TYPE=Release \
		-DCMAKE_C_FLAGS="-O2 -march=native -Wall -Wextra" \
		-DCMAKE_CXX_FLAGS="-O2 -march=native -Wall -Wextra" \
		..	
else
	cmake -DCMAKE_BUILD_TYPE=Debug \
		-DCMAKE_C_FLAGS="-ggdb3 -g3 -fno-omit-frame-pointer -Wall -Wextra" \
		-DCMAKE_CXX_FLAGS="-ggdb3 -g3 -fno-omit-frame-pointer -Wall -Wextra" \
		..	
fi

make -j4
