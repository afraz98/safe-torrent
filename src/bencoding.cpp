#include "bencoding.h"
#include <iostream>
#include <fstream>

namespace Bencoding {
    std::string parseString(std::ifstream& target) {
        int length;
        target >> length;
        target.ignore(1, ':'); // ignore the ':' separator
        std::string value(length, ' ');
        target.read(&value[0], length);
        return value;
    }

    int parseInt(std::ifstream& target) {
        char c;
        target >> c; // read in the 'i' character
        int value;
        target >> value;
        target >> c; // read in the 'e' character
        return value;
    }

    std::vector<byte> parseByteString(std::ifstream& target, int numBytes){
        std::vector<byte> bytes(numBytes);
        target.read(reinterpret_cast<char*>(&bytes[0]), numBytes);
        return bytes;
    }

    std::vector<std::string> parseList(std::ifstream& target){
        return std::vector<std::string>();
    }

    std::unordered_map<std::string, std::string> parseDictionary(std::ifstream& target){
        return std::unordered_map<std::string, std::string>();
    }

    std::string encodeInt(int target){
        return std::string("");
    }

    std::string encodeList(std::vector<std::string> target){
        return std::string("");
    }

    std::string encodeString(std::string target){
        return std::string("");
    }

    std::string encodeByteString(std::vector<byte> target){
        return std::string("");
    }

    std::string encodeDictionary(std::unordered_map<std::string, std::string> target){
        return std::string("");
    }
}