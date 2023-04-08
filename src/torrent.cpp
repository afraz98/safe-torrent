/*
 * \file torrent.h
 * \brief Implements Torrent class
 * \author Anthony Frazier
 */

#include "torrent.h"
#include "bencoding.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <sstream>

Torrent::Torrent(std::string filename) {
    this->filename = filename;
}

Torrent::~Torrent(){
    // Destructor
}

void Torrent::parseTorrent() {
    std::cout << "Parsing torrent file: " << this->filename << std::endl;

    // Create file object
    std::ifstream file(this->filename, std::ios::binary);

    if (!file.is_open()) {
        std::cerr << "Error: Failed to open file: " << this->filename << std::endl;
        return;
    }
    
    // Parse information from torrent file
    std::unordered_map<std::string, std::string> info_dict = Bencoding::parseDictionary();
    
    // Close file object
    file.close();    
 }

std::string Torrent::toString(){
    return std::string("");
}