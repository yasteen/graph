#!/bin/bash
#
# Get build directory
cd "$(dirname "$0")"
SRC_DIR="$(pwd)"
BLD_DIR="$SRC_DIR/build"

echo "cmake -B$BLD_DIR"
cmake "-B$BLD_DIR"

if [ ! -f "$BLD_DIR/compile_commands.json" ]; then
    ln -s "$BLD_DIR/compile_commands.json" "$SRC_DIR"
fi
