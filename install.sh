#!/bin/sh

echo "Installing dependencies"

if [[ $OSTYPE == 'darwin'* ]]; then
    brew install boost
else
    apt-get update
    apt-get install libboost-all-dev
fi
