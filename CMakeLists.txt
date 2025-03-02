cmake_minimum_required(VERSION 3.16)
project(VoxFormat)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/external/whisper.cpp/include
    ${CMAKE_SOURCE_DIR}/external/whisper.cpp/ggml/include
)
link_directories(${CMAKE_SOURCE_DIR}/external/whisper.cpp/build/src)

add_executable(voxformat
    src/main/main.cpp
    src/main/loadWav.cpp
    src/transcription/SpeechProcessor.cpp
    src/gui/MainWindow.cpp
)
target_link_libraries(voxformat whisper)