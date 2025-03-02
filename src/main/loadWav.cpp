#include "loadWav.h"
#include <iostream>
#include <fstream>
#include <cstdint>
#include <cstring>

struct WavHeader {
    // RIFF Header
    char     riff[4];        // "RIFF"
    uint32_t chunkSize;      // size of the rest of the chunk
    char     wave[4];        // "WAVE"

    // Format Sub-chunk
    char     fmt[4];         // "fmt "
    uint32_t subchunk1Size;  // size of the fmt chunk
    uint16_t audioFormat;    // 1 = PCM
    uint16_t numChannels;    // mono = 1, stereo = 2
    uint32_t sampleRate;     // sampling rate
    uint32_t byteRate;       // sampleRate * numChannels * bitsPerSample/8
    uint16_t blockAlign;     // numChannels * bitsPerSample/8
    uint16_t bitsPerSample;  // bits per sample

    // Data Sub-chunk
    char     data[4];        // "data"
    uint32_t dataSize;       // size of the data section
};

// Loads a 16-bit PCM WAV file into a float vector. Returns an empty vector on error.
std::vector<float> loadWav(const std::string& filename, int &sampleRate, int &numChannels) {
    std::vector<float> audioData;

    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Error: could not open WAV file: " << filename << std::endl;
        return {};
    }

    // Read the WAV header
    WavHeader header;
    file.read(reinterpret_cast<char*>(&header), sizeof(WavHeader));
    if (!file.good()) {
        std::cerr << "Error: failed to read WAV header from: " << filename << std::endl;
        return {};
    }

    // Basic sanity checks
    if (std::strncmp(header.riff, "RIFF", 4) != 0 ||
        std::strncmp(header.wave, "WAVE", 4) != 0 ||
        std::strncmp(header.fmt,  "fmt ", 4) != 0 ||
        std::strncmp(header.data, "data", 4) != 0 ||
        header.audioFormat != 1) // PCM
    {
        std::cerr << "Error: unsupported or invalid WAV file: " << filename << std::endl;
        return {};
    }

    if (header.bitsPerSample != 16) {
        std::cerr << "Error: this example only supports 16-bit PCM WAV files.\n";
        return {};
    }

    // Extract sample rate and channels from header
    sampleRate  = header.sampleRate;
    numChannels = header.numChannels;

    // Calculate how many samples are in the data section
    size_t totalSamples = header.dataSize / (header.bitsPerSample / 8) / header.numChannels;

    // Read sample data
    audioData.resize(totalSamples * header.numChannels);

    for (size_t i = 0; i < totalSamples * header.numChannels; i++) {
        int16_t sampleInt = 0;
        file.read(reinterpret_cast<char*>(&sampleInt), sizeof(int16_t));

        // Convert int16 sample to float in range [-1.0, 1.0]
        audioData[i] = sampleInt / 32768.0f;
    }

    file.close();
    return audioData;
}