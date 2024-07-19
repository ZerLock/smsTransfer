#!/bin/sh

if [ $# -ne 1 ]; then
    echo "Usage: $0 <build_directory>"
    exit 1
fi

build_directory=$1
root_path=$(pwd)
bin="smsTransfer"

test -d $build_directory
if [ $? -ne 0 ]; then
    mkdir $build_directory
fi

cd $build_directory

cmake $root_path
cmake --build .

cp $bin $root_path

echo "Build done"
