#!/bin/bash

cd `dirname $0`/..

echo "Generating C++ code from SQL statements."

mkdir -p gen/tpce
mkdir -p gen/tpcc
cd CodeGenerator
NAMESPACE=tpcc ./bin/generate from-schema ../data/schema.sql ../data/tpcc.hints.yml ../gen/tpcc
NAMESPACE=tpce ./bin/generate from-schema ../data/tpce.schema.sql ../data/tpce.hints.yml ../gen/tpce

echo "Done. Now run 'make' to build the C++ code."
