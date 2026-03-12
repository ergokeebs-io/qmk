#!/bin/bash
# QMK Firmware compilation via Docker
# Usage: ./build.sh [charybdis|crkbd|dactyl|all]

set -e

QMK_IMAGE="ghcr.io/qmk/qmk_cli"
DOCKER="docker run --rm -v $(pwd):/qmk_firmware -w /qmk_firmware $QMK_IMAGE"

build_charybdis() {
    echo "Building Charybdis 3x6..."
    $DOCKER qmk compile -kb bastardkb/charybdis/3x6 -km ergokeebs-io
}

build_crkbd() {
    echo "Building Crkbd..."
    $DOCKER qmk compile -kb crkbd -km ergokeebs-io
}

build_dactyl() {
    echo "Building Dactyl Manuform 5x6..."
    $DOCKER qmk compile -kb handwired/dactyl_manuform/5x6 -km ergokeebs-io
}

case "${1:-all}" in
    charybdis) build_charybdis ;;
    crkbd)     build_crkbd ;;
    dactyl)    build_dactyl ;;
    all)
        build_charybdis
        build_crkbd
        build_dactyl
        ;;
    *)
        echo "Usage: $0 [charybdis|crkbd|dactyl|all]"
        exit 1
        ;;
esac

echo "Done! .uf2 files are in the repo root."
