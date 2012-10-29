# Imlab

Main Memory Database

    bin/    Helper scripts to get sample data etc.
    data/   Sample data (obtain by executing helper script)
    obj/    Build output
    src/    Source code

## Quickstart

 1. Run `./bin/fetch.sh` to get sample data to populate database with.
 2. Run `make release=true` to build.
 3. Execute `./obj/fakedb` (or use `make run`).

Tested with gcc 4.7.2 on Arch Linux x86_64.
