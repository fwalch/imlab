#!/bin/bash

OUTPUT_BASE=walch_fakedb

cd `dirname $0`/..

format=tar.gz

if [ $1 ]; then
  branch=$1
else
  branch=master
fi

echo "Creating archive for branch $branch."

file=$OUTPUT_BASE-$branch.$format

git archive --format $format --output=$file $branch

echo "Archive created."
