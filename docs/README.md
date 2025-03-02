# VoxFormat

## Project Idea
Imagine you are a student who loves to take notes on pen and paper instead of virtual documents like Google Docs, Microsoft Word, or iPad drawings. Maintaining so many papers together is difficult, and the paper quality may start deteriorating over the years.

* One option is to scan the pages and save them as PDF files, but sometimes, the scanned pages do not have successful OCR results on handwritten texts, which can be problematic if you want to copy-paste part of your notes somewhere.
* Similarly, taking photos of the pages and compiling them into an album will take more space than a normal text file. In the long run, storage might be an issue.
* The final option is to digitize the text from paper to a virtual document by manually typing everything out. That might take a long time, and it is almost like doing double the work.

To solve this problem, I want to create a C++ library, that people can import and use to transcribe words from speech (audio) to text in real time. There might be speech-to-text engines existing but according to my limited knowledge, they do not tend to possess the ability to do a few things like making the text **bold** or _italics_, or scientific notations like subscripts, superscripts, etc. in their texts. I want to build a library that can take care of all these capabilities and be usable software for people.

**Notes:**
- The Whisper model is stored in `external/whisper.cpp/models/ggml-base.en.bin`.
- When running from the build directory, relative paths in the code assume that the project root is one level up (e.g., model path `"../external/whisper.cpp/models/ggml-base.en.bin"`).

## Prerequisites

Before building VoxFormat, please ensure the following dependencies are installed:

- **CMake**  
  - _macOS_: `brew install cmake`
  - _Linux_: `sudo apt install cmake`
  - _Windows_: Download from [CMake's website](https://cmake.org/download/).

- **Compiler**  
  - _macOS_: Clang (included with Xcode Command Line Tools)
  - _Linux_: GCC or Clang
  - _Windows_: MSVC (Visual Studio) or MinGW/GCC

- **Qt** (for GUI components)  
  - _macOS_: `brew install qt` and add Qt's bin directory (e.g., `/usr/local/opt/qt/bin`) to your PATH.
  - _Linux_: `sudo apt install qt5-qmake qtbase5-dev`
  - _Windows_: Download from [Qt's website](https://www.qt.io/download/).

## Initial Setup

To make VoxFormat plug-and-play, a `setup.sh` script is provided that automates the following steps:

- Cloning and updating the Whisper.cpp repository.
- Building Whisper.cpp.
- Downloading the Whisper model from Hugging Face.

### Using the Setup Script

1. **Make the Script Executable**  
   From the project root, run:
   ```bash
   chmod +x setup.sh
   ```

2. **Run the Script**  
   ```bash
   ./setup.sh
   ```
   This script will:
   - Check if `external/whisper.cpp` exists; if not, it will clone it.
   - Update submodules for Whisper.cpp.
   - Build Whisper.cpp.
   - Download the base English model (`ggml-base.en.bin`) into `external/whisper.cpp/models/`.

## Building VoxFormat

After running the setup script, proceed with building VoxFormat:

1. **Clean and Create a Build Directory, Then Build**  
   ```bash
   cd /Users/sprihamandal/Desktop/voxformat/VoxFormat
   rm -rf build
   mkdir build && cd build
   cmake ..
   make -j$(sysctl -n hw.ncpu)
   cd ..
   ```
   *(The final `cd ..` takes you back to the project root.)*

2. **Run the Executable**  
   ```bash
   cd build
   ./voxformat
   cd ..
   ```

## Usage

- **Model Loading**  
  VoxFormat loads the Whisper model from `../external/whisper.cpp/models/ggml-base.en.bin` relative to the build directory.

- **Audio Transcription**  
  The `SpeechProcessor` class in `src/transcription/` loads the model and transcribes audio data provided (e.g., from a WAV file loaded via `loadWav()`).

- **WAV File Loading**  
  Place your sample WAV files in the `sample_audio/` directory. The example in `main.cpp` loads a file called `samplespeech.wav` from this folder.

## Contributing

Contributions are welcome! To contribute:
1. Fork this repository.
2. Create a feature branch.
3. Commit your changes.
4. Submit a pull request.