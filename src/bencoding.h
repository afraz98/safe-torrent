/*
 * \file torrent.h
 * \brief Defines BencodeParser class
 * \author Anthony Frazier
 */

#ifndef BENCODING_H
#define BENCODING_H

#include <iostream>
#include <vector>
#include <map>
#include <variant>
#include <unordered_map>
#include <fstream>
#include <any>

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
    typedef std::map<std::string, std::any> Dictionary;

    class BencodeParser {
        public:
            BencodeParser(std::ifstream& file);

            uint8_t parseChar();
            
            std::string parseString();
            
            uint64_t parseInt();

            std::vector<std::any> parseList();

            std::vector<byte> parseBytes();

            Dictionary parseDictionary();

        private:
            std::ifstream& m_file;
    };
}

#endif // BENCODING_H