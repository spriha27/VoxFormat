#!/bin/bash
set -e

echo "=== Setting up VoxFormat ==="

# 1. Clone Whisper.cpp if it doesn't exist
if [ -d "external/whisper.cpp" ]; then
    rm -rf external/whisper.cpp
fi
echo "Cloning Whisper.cpp repository..."
git clone https://github.com/ggerganov/whisper.cpp.git external/whisper.cpp

# 2. Build Whisper.cpp
echo "Building Whisper.cpp..."
cd external/whisper.cpp || { echo "Cannot cd to external/whisper.cpp"; exit 1; }
rm -rf build
mkdir build && cd build
cmake ..
make -j$(sysctl -n hw.ncpu)
cd ../../..

# 3. Download the Whisper model
echo "Downloading ggml-base.en.bin model..."
cd external/whisper.cpp || exit 1
./models/download-ggml-model.sh base.en
cd ..

echo "Setup complete! You can now build VoxFormat with cmake in the project root."