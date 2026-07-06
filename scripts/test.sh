#!/bin/bash

set -e

PROJECT_ROOT="$(cd "$(dirname "$0")/.." && pwd)"
BUILD_DIR="$PROJECT_ROOT/build"

echo "======================================"
echo " Running Unit Tests"
echo "======================================"

cd "$BUILD_DIR"

ctest --output-on-failure

echo ""
echo "======================================"
echo " Tests Complete!"
echo "======================================"
