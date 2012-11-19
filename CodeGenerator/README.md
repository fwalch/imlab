# Imlab SQL -> C++ Code Generator

SQL -> C++ Code Generator

    bin/    Helper scripts & code generator executable (`generate`)
    data/   Data files
    lib/    Code generator source code
    spec/   Code generator tests

## Quickstart

 1. (Optional) To regenerate the parser code from the ANTLR grammar:
   1. Run `bundle install --without test` to install necessary gems.
   2. (Optional) To run tests, use `bundle install` and run `bundle exec rake`.
   3. Run `./bin/generate-parser.sh` to regenerate the parser code.
 2. The code generator is now ready for use (see `../bin/generate-sql-classes.sh` for example usage).

Tested with Ruby 1.9.3p286 on Arch Linux x86_64.

## Prerequisites

 * Java to run ANTLR
 * `antlr4ruby` executable (comes with `antlr3` gem) in `PATH`
 * Ruby 1.9 with `bundler` gem installed (`gem install bundler`)

