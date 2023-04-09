/*
 * \file torrent.h
 * \brief Implements BencodeParser class
 * \author Anthony Frazier
 */

#include "bencoding.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <any>

namespace Bencoding {
    BencodeParser::BencodeParser(std::ifstream& file) : m_file(file) {}

    uint8_t BencodeParser::parseChar() {
        char c;
        m_file.get(c);
        return static_cast<uint8_t>(c);
    }

    std::string BencodeParser::parseString() {
        std::string result;
        uint64_t length = parseInt();
        for (uint64_t i = 0; i < length; ++i) { // Iterate over <length> characters
            result.push_back(parseChar());
        }
        return result;
    }

    uint64_t BencodeParser::parseInt() {
        std::string result;
        char c;

        if(((c=parseChar()) != 'i')){ // Input is not an integer -- return
            return -999;
        }

        while ((c = parseChar()) != 'e') { // Iterate until 'e' terminator
            result.push_back(c);
        }
        return std::stoull(result);
    }

    std::vector<std::any> BencodeParser::parseList() {
        std::vector<std::any> list;
        
        char c;
        if((c = parseChar()) != 'l'){ // Input is not a list -- return
            return list;
        }

        return list;
    }

    std::vector<byte> BencodeParser::parseBytes() {
        std::vector<byte> bytes;
        return bytes;
    }

    Dictionary BencodeParser::parseDictionary() {
        Dictionary dictionary;

        char c;
        if((c = parseChar()) != 'd'){ // Input is not a dictionary -- return
            return dictionary;
        }

        return dictionary;
    }
}