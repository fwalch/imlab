# Imlab

Main Memory Database

    bin/    Helper scripts to get sample data etc.
    data/   Sample data ("./bin/fetch.sh")
    docu/   Documentation output ("make docu")
    obj/    Build output ("make")
    src/    Source code

## Quickstart

 1. Run `./bin/fetch.sh` to get sample data to populate database with.
 2. Run `make release=true` to build.
 3. Execute `./obj/fakedb` (or use `make run`).

Tested with gcc 4.7.2 on Arch Linux x86_64.

## Prerequisites

 * cURL or Wget to fetch sample data
 * GCC (or Clang) to compile
 * Doxygen and Graphviz to build docu
