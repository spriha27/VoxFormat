#ifndef LOAD_WAV_H
#define LOAD_WAV_H

#include <string>
#include <vector>

// Forward-declare the loadWav function
// We'll define it in loadWav.cpp
std::vector<float> loadWav(const std::string &filename, int &sampleRate, int &numChannels);

#endif // LOAD_WAV_H