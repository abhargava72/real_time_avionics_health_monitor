#!/bin/bash

set -e

PROJECT_ROOT="$(cd "$(dirname "$0")/.." && pwd)"
BUILD_DIR="$PROJECT_ROOT/build"

echo "======================================"
echo " Cleaning Build Files"
echo "======================================"

if [ -d "$BUILD_DIR" ]; then
    rm -rf "$BUILD_DIR"
    echo "Removed build directory."
else
    echo "Build directory does not exist."
fi

echo ""
echo "======================================"
echo " Cleanup Complete!"
echo "======================================"