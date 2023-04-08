#ifndef BENCODING_H
#define BENCODING_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>

typedef uint8_t byte;

/*
 * B-encoding is the encoding used by BitTorrent, and if you want to work with the BitTorrent protocol, 
 * it's probably a good idea to implement something like this yourself.
 * 
 * B-Encoding supports the following types:
 * 
 * 1. Byte-strings
 * 2. Integers
 * 3. Lists
 * 4. Dictionaries
 * 
 * For simplicity, I've decided to implement B-encoding parsing through ifstream objects.
 */

namespace Bencoding {
    int parseInt(std::ifstream& target);

    std::string parseString(std::ifstream& target);

    std::vector<std::string> parseList(std::ifstream& target);

    std::unordered_map<std::string, std::string> parseDictionary(std::ifstream& target);

    std::vector<byte> parseByteString(std::ifstream& target);

    std::string encodeInt(int target);

    std::string encodeList(std::vector<std::string> target);

    std::string encodeString(std::string target);

    std::string encodeByteString(std::vector<byte> target);

    std::string encodeDictionary(std::unordered_map<std::string, std::string> target);
}

#endif // BENCODING_H