#!/bin/bash

set -e

PROJECT_ROOT="$(cd "$(dirname "$0")/.." && pwd)"

EXECUTABLE="$PROJECT_ROOT/build/avionics_monitor"

echo "======================================"
echo " Starting Avionics Health Monitor"
echo "======================================"

if [ ! -f "$EXECUTABLE" ]; then
    echo "Executable not found."
    echo "Run ./scripts/build.sh first."
    exit 1
fi

"$EXECUTABLE"
