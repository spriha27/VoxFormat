#ifndef SPEECH_PROCESSOR_H
#define SPEECH_PROCESSOR_H

#include <string>
#include <vector>
#include "whisper.h"

class SpeechProcessor {
public:
    explicit SpeechProcessor(const std::string &modelPath);
    ~SpeechProcessor();

    bool loadModel();
    std::string transcribeAudio(const std::vector<float>& audioData, int sampleRate);

private:
    std::string modelPath;
    struct whisper_context* whisperContext;
};

#endif