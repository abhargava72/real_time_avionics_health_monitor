#!/bin/bash

set -e

PROJECT_ROOT="$(cd "$(dirname "$0")/.." && pwd)"

echo "======================================"
echo " Formatting C++ Source Files"
echo "======================================"

clang-format -i \
    "$PROJECT_ROOT"/src/*.cpp \
    "$PROJECT_ROOT"/include/*.hpp \
    "$PROJECT_ROOT"/tests/*.cpp

echo ""
echo "======================================"
echo " Formatting Complete!"
echo "======================================"
