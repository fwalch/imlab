# Imlab

Main Memory Database Lab Course

## Available Branches

  * string-dictionary
    * String values stored within a string dictionary for each column
    * Short strings are stored in a data structure within the table
  * string-dictionary_nostr
    * All string values (even with short length) are stored within a string dictionary for each column
  * string-vector
    * String values are stored in character vectors - strings are padded to the maximum length specified in SQL i.e. `{VAR}CHAR(X)`)

This branch uses a string vector implementation and executes transactions (OLTP) and queries (OLAP) in parallel.

[![Build Status](https://secure.travis-ci.org/fwalch/imlab.png?branch=master)](http://travis-ci.org/fwalch/imlab)

## File Structure

    bin/              Helper scripts to get sample data etc.
    CodeGenerator/    SQL -> C++ code generator; output is in "gen/"
    data/             Sample data ("./bin/fetch.sh")
    gen/              Generated source code ("./bin/generate-sql-classes.sh")
    obj/              Build output ("make")
    src/              Source code
    test/             Test source code

## Quickstart

 1. Run `./bin/fetch.sh` to get the sample schema/data to populate the database with.
 2. (Optional) Regenerate the C++ classes for the SQL schema with `./bin/generate-sql-classes.sh`.
 3. (Optional) Regenerate the C++ classes for the example SQL queries with `./bin/generate-sql-queries.sh`.
 4. (Optional) Run `make release=true test` to run unit tests.
 5. Run `make release=true` to build.
 6. Execute `./obj/fakedb` (or use `make release=true run`).

Tested with Clang 3.2 on Arch Linux x86_64.

## Prerequisites

 * cURL or Wget to fetch sample data
 * Clang (or GCC) to compile
 * googletest to run tests (available as `libgtest-dev` package on Ubuntu, `gtest` AUR PKGBUILD for Arch Linux)
   * cmake to build googletest
 * For code generator prerequisites, see [`CodeGenerator/README.md`](CodeGenerator/README.md)
