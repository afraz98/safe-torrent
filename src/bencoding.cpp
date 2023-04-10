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

        // Find string length
        std::string lengthString = "";
        uint64_t length = 0;

        char c;
        while ((c = parseChar()) != ':') { // Iterate until 'e' terminator
            lengthString.push_back(c);
        }

        length = std::stoull(lengthString);

        for (uint64_t i = 0; i < length; ++i) { // Iterate over <length> characters
            result.push_back(parseChar());
        }
        return result;
    }

    uint64_t BencodeParser::parseInt() {
        std::string result;
        char c;

        while ((c = parseChar()) != 'e') { // Iterate until 'e' terminator
            result.push_back(c);
        }
        return std::stoull(result);
    }

    std::vector<std::any> BencodeParser::parseList(std::vector<std::any>& list) {
        char c;

        return list;
    }

    std::vector<byte> BencodeParser::parseBytes() {
        std::vector<byte> bytes;
        return bytes;
    }

    Dictionary BencodeParser::parseDictionary(Dictionary& dict) {
        Dictionary dictionary;
        char c;

        return dictionary;
    }

    std::any BencodeParser::parseItem(){
        char c;
        c = parseChar();

        if(c == 'i'){
            return parseInt();
        } else if(c == 'd'){
            Dictionary dict;
            return parseDictionary(dict);
        } else if (c == 'l'){
            std::vector<std::any> list;
            return parseList(list);
        } else if (isdigit(c)) {
            return parseString();
        }

        return NULL;
    }
}