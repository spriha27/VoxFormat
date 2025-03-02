# CMakeLists.txt for tests
cmake_minimum_required(VERSION 3.16)

# Add test executable
add_executable(voxformat_tests
    SpeechProcessorTests.cpp
    ../src/transcription/SpeechProcessor.cpp
)

# Link the Whisper library for tests
target_link_libraries(voxformat_tests whisper)