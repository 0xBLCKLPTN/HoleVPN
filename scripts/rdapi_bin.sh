#!/bin/bash

cd ../rdapi && cargo build
if [ -f "../bin/linux/rdapi" ]; then
    echo "Source file exists. Removing..."
    rm -rf ../bin/linux/rdapi
fi
cp target/debug/rdapi ../bin/linux/ --force
