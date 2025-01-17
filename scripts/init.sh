#!/usr/bin/bash

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
cd $DIR

set -u
set -e
set -x

BASE_DIR=$DIR"/../"
cd $BASE_DIR

git submodule update --init --recursive
