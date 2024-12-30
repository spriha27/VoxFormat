cmake_minimum_required(VERSION 3.16)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

# Platform-specific settings
# Make necessary changes here to make it work for your platform
if(WIN32)
    # Windows-specific settings
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_WINDOWS")
elseif(APPLE)
    # macOS-specific settings
    set(CMAKE_OSX_SYSROOT "/Library/Developer/CommandLineTools/SDKs/MacOSX15.2.sdk")
    include_directories("/Library/Developer/CommandLineTools/SDKs/MacOSX15.2.sdk/usr/include/c++/v1")
elseif(UNIX)
    # Linux-specific settings
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_LINUX")
endif()

add_executable(voxformat src/main.cpp
        src/transcription/EventHandler.h
        src/transcription/Formatter.h
        src/transcription/SpeechProcessor.h
        tests/FormatterTests.cpp
        tests/SpeechProcessorTests.cpp
        gui/MainWindow.cpp
        gui/MainWindow.h
)