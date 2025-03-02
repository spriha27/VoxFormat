# VoxFormat

## Project Idea
Imagine you are a student who loves to take notes on pen and paper instead of virtual documents like Google Docs, Microsoft Word, or iPad drawings. Maintaining so many papers together is difficult, and the paper quality may start deteriorating over the years.

* One option is to scan the pages and save them as PDF files, but sometimes, the scanned pages do not have successful OCR results on handwritten texts, which can be problematic if you want to copy-paste part of your notes somewhere.
* Similarly, taking photos of the pages and compiling them into an album will take more space than a normal text file. In the long run, storage might be an issue.
* The final option is to digitize the text from paper to a virtual document by manually typing everything out. That might take a long time, and it is almost like doing double the work.

To solve this problem, I want to create a C++ library, that people can import and use to transcribe words from speech (audio) to text in real time. There might be speech-to-text engines existing but according to my limited knowledge, they do not tend to possess the ability to do a few things like making the text **bold** or _italics_, or scientific notations like subscripts, superscripts, summations(∑), etc. in their texts. I want to build a library that can take care of all these capabilities and be usable software for people.

## Prerequisites to contribute

Please make sure the following dependencies are installed in your system:
* **CMake**: Available on all platforms.
  * _macOS_: ```brew install cmake```
  * _Linux_: ```sudo apt install cmake```
  * _Windows_: Download the installer from the official [CMake website](https://cmake.org/download/).
* A compatible **compiler**:
  * _macOS_: Clang (comes with Xcode Command Line Tools).
  * _Linux_: GCC or Clang.
  * _Windows_: MSVC (part of Visual Studio) or MinGW/GCC.
* **Dependencies**: This project is dependent on:
  * **Qt**:
    * _macOS_: 
      * ```brew install qt```
      * Add Qt's bin directory to your PATH (usually, it’s /usr/local/opt/qt/bin): ```bash 
      export PATH="/usr/local/opt/qt/bin:$PATH"```
    * _Linux_: ```sudo apt install qt5-qmake qtbase5-dev```
    * _Windows_: Download the Qt Online Installer from the official [Qt website](https://www.qt.io/download).
  * **GoogleTest**:
      * _macOS_:
        * ```brew install googletest```
        * Manually building: 
          ``` bash
          git clone https://github.com/google/googletest.git
          cd googletest
          mkdir build
          cd build cmake ..
          make
          sudo make install
          ```
      * _Linux_: 
        * ```sudo apt install libgtest-dev```
        * Compile it separately using:
          ``` bash
          cd /usr/src/gtest
          sudo cmake CMakeLists.txt
          sudo make
          sudo mv libgtest* /usr/lib
          ```
      * _Windows_: Download the latest release of Google Test from the [GitHub repository](https://github.com/google/googletest).
  * **Doxygen**:
      * _macOS_: ```brew install doxygen```
      * _Linux_: ```sudo apt install doxygen```
      * _Windows_: Download the Doxygen installer from the official [Doxygen website](https://www.doxygen.nl/download.html).

## Build the project

* Clone this repository.
* Open a terminal or IDE with CMake support (e.g. CLion).
* Do OS-Specific Adjustments:
  * _macOS_:
      * (Optional unless errors crop up) Ensure the correct SDK is specified in CMakeLists.txt: \
        ```set(CMAKE_OSX_SYSROOT "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk")```
  * _Linux_:
      * Install GCC/Clang and any required libraries: \
        ```sudo apt install build-essential cmake```
      * No need for CMAKE_OSX_SYSROOT—Linux usually auto-detects paths.
  * Windows:
      * Use Visual Studio:
          * Open the CMakeLists.txt file directly in Visual Studio.
      * Or use MinGW/GCC with:
        ``` bash
        cmake -G "MinGW Makefiles" ..
        cmake --build .
        ```
* Run these commands to create a build directory: 
    ```bash
    mkdir build
    cd build
  ```
* Run CMake:
    ```bash
    cmake ..
    cmake --build .
    ```
* Run the executable:
    ```bash
    ./MyProject   # On Linux/macOS
    MyProject.exe # On Windows
    ```

    