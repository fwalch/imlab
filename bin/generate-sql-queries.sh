#!/bin/bash

if [ -e $1 ]; then
  QUERY_NAME=builtin
else
  QUERY_NAME=$1
fi

OUTPUT_DIR=gen

cd `dirname $0`/..

echo "Generating C++ code from SQL query expression tree"

mkdir -p $OUTPUT_DIR
cd CodeGenerator && ./bin/generate from-query $QUERY_NAME ../$OUTPUT_DIR

echo "Done. Now run 'make' to build the C++ code."
