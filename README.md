# Imlab

[![Build Status](https://travis-ci.org/fwalch/imlab.png?branch=string-dictionary)](http://travis-ci.org/fwalch/imlab)

Main Memory Database

    bin/              Helper scripts to get sample data etc.
    CodeGenerator/    SQL -> C++ code generator; output is in "gen/"
    data/             Sample data ("./bin/fetch-tpcc.sh" and "./bin/fetch-yago.sh")
    gen/              Generated source code ("./bin/generate-sql-classes.sh")
    obj/              Build output ("make")
    src/              Source code
    test/             Test source code

## Quickstart

 1. Run `./bin/fetch-tpcc.sh` to get the sample schema/data to populate the database with. To get Yago data, use `./bin/fetch-yago.sh`.
 2. (Optional) Regenerate the C++ classes for the SQL schema with `./bin/generate-sql-classes.sh`.
 3. (Optional) Regenerate the C++ classes for the example SQL queries with `./bin/generate-sql-queries.sh`.
 4. (Optional) Run `make release=true test` to run unit tests.
 5. Run `make release=true` to build.
 6. Execute `./obj/fakedb` (or use `make release=true run`).

Tested with Clang 3.1 on Arch Linux x86_64.

## Prerequisites

 * cURL or Wget to fetch sample data; tar, sed, cut, and 7z command line utilities to process data
 * Clang (or GCC) to compile
 * googletest to run tests (available as `libgtest-dev` package on Ubuntu, `gtest` AUR PKGBUILD for Arch Linux)
   * cmake to build googletest
 * For code generator prerequisites, see `CodeGenerator/README.md`
