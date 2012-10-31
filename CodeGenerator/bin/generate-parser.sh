#!/bin/bash

GRAMMAR_FILE=data/SQL.g
OUTPUT_DIR=gen

cd `dirname $0`/..

command -v antlr4ruby >/dev/null 2>&1 || {
  echo >&2 "antlr4ruby not available. Cannot run."
  exit 1
}

echo "Generating Ruby parser code."

antlr4ruby -fo $OUTPUT_DIR $GRAMMAR_FILE

echo "Done."
