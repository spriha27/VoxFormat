#include "SpeechProcessor.h"
#include <iostream>

SpeechProcessor::SpeechProcessor(const std::string &modelPath)
    : modelPath(modelPath), whisperContext(nullptr) {}

SpeechProcessor::~SpeechProcessor() {
    if (whisperContext) {
        whisper_free(whisperContext);
    }
}

bool SpeechProcessor::loadModel() {
    std::cout << "Attempting to load model from: " << modelPath << std::endl;
    whisperContext = whisper_init_from_file_with_params(
        modelPath.c_str(),
        whisper_context_default_params()
    );
    if (!whisperContext) {
        std::cerr << "Failed to load Whisper model: " << modelPath << std::endl;
        return false;
    }
    std::cout << "Whisper model loaded successfully!" << std::endl;
    return true;
}

std::string SpeechProcessor::transcribeAudio(const std::vector<float>& audioData, int sampleRate) {
    if (!whisperContext) {
        return "Model not loaded!";
    }

    whisper_full_params params = whisper_full_default_params(WHISPER_SAMPLING_GREEDY);
    if (whisper_full(whisperContext, params, audioData.data(), audioData.size()) != 0) {
        return "Transcription failed.";
    }

    std::string result;
    int numSegments = whisper_full_n_segments(whisperContext);
    for (int i = 0; i < numSegments; ++i) {
        result += whisper_full_get_segment_text(whisperContext, i);
        result += " ";
    }
    return result;
}