#!/bin/bash

set -e

PROJECT_ROOT="$(cd "$(dirname "$0")/.." && pwd)"
BUILD_DIR="$PROJECT_ROOT/build"

echo "======================================"
echo " Building Avionics Health Monitor"
echo "======================================"

mkdir -p "$BUILD_DIR"

cd "$BUILD_DIR"

cmake ..

cmake --build .

echo ""
echo "======================================"
echo " Build Complete!"
echo " Executable: build/avionics_monitor"
echo "======================================"
