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

    std::string parseItem(std::ifstream& target){
        char c;
        target >> c;

        switch (c) {
            case 'i': { // integer
                return std::to_string(parseInt(target)); // integer values are treated as zero-filled bytes
            }
            case 'l': { // list
                return std::to_string(parseList(target));
            }
            case 'd': { // dictionary 
                return std::to_string(parseDictionary(target));
            }
            default: { // byte string
                target.putback(c); // put back the first character
                std::string length = parseString(target);
                return std::to_string(parseByteString(target, std::stoi(length)));
            }
        }
    }

    std::unordered_map<std::string, std::string> parseDictionary(std::ifstream& target){
        std::unordered_map<std::string, std::string> dict;

        char c;
        target >> c;

        while (true) {
            // check for end of dictionary
            target >> std::ws; // skip whitespace
            if (target.peek() == 'e') {
                target >> c; // consume 'e'
                break;
            }

            // read in key and value
            std::string key = parseString(target);
            std::string value = parseItem(target);

            // add key-value pair to dictionary
            dict[key] = std::move(value);
        }

        return dict;
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