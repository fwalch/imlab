#!/bin/bash

DATA_FILE=http://www-db.in.tum.de/teaching/ws1213/imlab/ex1.tgz
OUTPUT_FILE=ex1.tgz
TARGET_DIR=data

cd `dirname $0`/..

command -v wget >/dev/null 2>&1 || {
  command -v curl >/dev/null 2>&1 || {
    echo >&2 "Neither wget nor curl available. Cannot run."
    exit 1
  }
  dl="curl -C - $DATA_FILE -o $TARGET_DIR/$OUTPUT_FILE"
}

if [ -z "$dl" ]; then
  dl="wget --continue $DATA_FILE -O $TARGET_DIR/$OUTPUT_FILE"
fi

mkdir -p $TARGET_DIR

$dl
tar xfz $TARGET_DIR/$OUTPUT_FILE -C $TARGET_DIR --wildcards '*.tbl'

