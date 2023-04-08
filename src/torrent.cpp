/*
 * \file torrent.h
 * \brief Implements Torrent class
 * \author Anthony Frazier
 */

#include "torrent.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <sstream>

Torrent::Torrent(std::string filename) {
    this->filename = filename;
    this->name = std::string("");
    this->hash = std::string("");
    this->trackers = std::vector<std::string>();
}

Torrent::~Torrent(){
    // Destructor
}

std::string Torrent::parseString(std::ifstream& file) {
    int length;
    file >> length;
    file.ignore(1, ':'); // ignore the ':' separator
    std::string value(length, ' ');
    file.read(&value[0], length);
    return value;
}

int Torrent::parseInt(std::ifstream& file) {
    char c;
    file >> c; // read in the 'i' character
    int value;
    file >> value;
    file >> c; // read in the 'e' character
    return value;
}

std::vector<byte> Torrent::parseBytes(std::ifstream& file, int numBytes) {
    std::vector<byte> bytes(numBytes);
    file.read(reinterpret_cast<char*>(&bytes[0]), numBytes);
    return bytes;
}

std::vector<byte> Torrent::parseList(std::ifstream &file){
    std::vector<byte> list;

    char c;
    file >> c;

    while (true) {
        // check for end of list
        file >> std::ws; // skip whitespace
        if (file.peek() == 'e') {
            file >> c; // consume 'e'
            break;
        }

        // parse and add item to list
        auto item = parseItem(file);
        list.insert(list.end(), item.begin(), item.end());
    }

    return list;
}

std::vector<byte> Torrent::parseItem(std::ifstream& file) {
    char c;
    file >> c;

    std::cout << "Parsing item" << std::endl;

    switch (c) {
        case 'i': { // integer
            std::cout << "Integer" << std::endl;
            auto value = parseInt(file);
            return std::vector<byte>(value); // integer values are treated as zero-filled bytes
        }
        case 'l': {// list
            std::cout << "List" << std::endl;
            return parseList(file);
        }
        case 'd': {// dictionary
            std::cout << "Dictionary" << std::endl;
            auto dict = parseDictionary(file);
            std::vector<byte> bytes;
            for (auto& item : dict) {
                // add key
                auto key = item.first;
                bytes.insert(bytes.end(), key.begin(), key.end());
                // add value
                auto value = item.second;
                bytes.insert(bytes.end(), value.begin(), value.end());
            }
            return bytes;
        }
        default: { // byte string
            std::cout << "Bytes" << std::endl;
            file.putback(c); // put back the first character
            auto length = parseString(file);
            auto bytes = parseBytes(file, std::stoi(length));
            return bytes;
        }
    }
}


std::unordered_map<std::string, std::vector<byte>> Torrent::parseDictionary(std::ifstream& file) {
    std::unordered_map<std::string, std::vector<byte>> dict;

    char c;
    file >> c;

    while (true) {
        // check for end of dictionary
        file >> std::ws; // skip whitespace
        if (file.peek() == 'e') {
            file >> c; // consume 'e'
            break;
        }

        // read in key and value
        auto key = parseString(file);
        auto value = parseItem(file);

        // add key-value pair to dictionary
        dict[key] = std::move(value);
    }

    return dict;
}

void Torrent::parseTorrent() {
    std::cout << "Parsing torrent file: " << this->filename << std::endl;

    // Create file object
    std::ifstream file(this->filename, std::ios::binary);

    if (!file.is_open()) {
        std::cerr << "Error: Failed to open file: " << this->filename << std::endl;
        return;
    }

    // Parse dictionary
    auto info_dict = parseDictionary(file);
    file.close();    

    std::cout << std::string(info_dict["name"].begin(), info_dict["name"].end()) << std::endl;
 }

std::string Torrent::toString(){
    return std::string("");
}