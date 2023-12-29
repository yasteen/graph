#!/bin/bash
#
# Get build directory
cd "$(dirname "$0")"
BUILD_DIR="$(pwd)/build"

echo "cmake -B$BUILD_DIR"
cmake "-B$BUILD_DIR"
