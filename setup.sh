#!/bin/bash
# setup.sh - Script to set up VoxFormat dependencies

# Exit if any command fails
set -e

echo "=== Setting up VoxFormat ==="

# Step 1: Ensure external/whisper.cpp is cloned
if [ ! -d "external/whisper.cpp" ]; then
    echo "Cloning Whisper.cpp repository..."
    cd external
    git clone https://github.com/ggerganov/whisper.cpp.git
    cd ..
fi

# Step 2: Update submodules for Whisper.cpp
cd external/whisper.cpp
echo "Updating submodules..."
git submodule update --init --recursive

# Step 3: Build Whisper.cpp
echo "Building Whisper.cpp..."
rm -rf build
mkdir build && cd build
cmake ..
make -j$(sysctl -n hw.ncpu)
cd ..

# Step 4: Download the base model
echo "Downloading ggml-base.en.bin model..."
./models/download-ggml-model.sh base.en

cd ../..
echo "Setup complete! You can now build VoxFormat."