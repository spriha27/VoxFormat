#include "transcription/SpeechProcessor.h"
#include "loadWav.h"  // Ensure loadWav.h is available and correctly implemented in src/main/
#include <iostream>
#include <vector>

int main() {
    // Since you removed the config folder, the model is now in external/whisper.cpp/models.
    // When running from the build directory, the relative path should go one level up.
    std::string modelPath = "../external/whisper.cpp/models/ggml-base.en.bin";
    
    SpeechProcessor processor(modelPath);
    
    if (!processor.loadModel()) {
        std::cerr << "Error: Failed to load Whisper model." << std::endl;
        return 1;
    }
    
    int sampleRate = 0, numChannels = 0;
    // Load a sample WAV file from the sample_audio folder.
    // (Make sure the folder is renamed to avoid spaces if needed.)
    std::vector<float> audioData = loadWav("../sample_audio/samplespeech.wav", sampleRate, numChannels);
    if (audioData.empty()) {
        std::cerr << "Error: Failed to load audio file." << std::endl;
        return 1;
    }
    
    std::string transcription = processor.transcribeAudio(audioData, sampleRate);
    std::cout << "Transcription: " << transcription << std::endl;
    
    return 0;
}