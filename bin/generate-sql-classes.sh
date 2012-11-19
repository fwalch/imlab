#!/bin/bash

SCHEMA_FILE=data/schema.sql
HINTS_FILE=data/hints.yml
OUTPUT_DIR=gen

cd `dirname $0`/..

echo "Generating C++ code from SQL statements."

mkdir -p $OUTPUT_DIR
cd CodeGenerator && ./bin/generate from-schema ../$SCHEMA_FILE ../$HINTS_FILE ../$OUTPUT_DIR

echo "Done. Now run 'make' to build the C++ code."
