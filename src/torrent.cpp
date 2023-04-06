#include "torrent.h"
#include <stdlib.h>

#include <iostream>
#include <fstream>
#include <vector>

Torrent::Torrent(std::string filename) {
    this->filename = filename;
    this->name = std::string("");
    this->hash = std::string("");
    this->trackers = std::vector<std::string>();
}

void Torrent::parseTorrent() {
    // Read file contents into string buffer
    std::ifstream file(this->filename, std::ios::binary);
    std::stringstream buffer;
    buffer << file.rdbuf();

    // Find info section
    std::string fileContent = buffer.str();
    std::size_t infoStartPos = fileContent.find("4:info") + 6;
    std::size_t infoEndPos = fileContent.find("e", infoStartPos) + 1;
    std::string infoContent = fileContent.substr(infoStartPos, infoEndPos - infoStartPos);

    // Parse torrent name
    std::size_t nameStartPos = infoContent.find("4:name") + 6;
    std::size_t nameEndPos = infoContent.find("e", nameStartPos);
    this->name = infoContent.substr(nameStartPos, nameEndPos - nameStartPos);

    // Parse torrent hash
    std::size_t hashStartPos = infoContent.find("20:") + 3;
    std::size_t hashEndPos = hashStartPos + 20;
    this->hash = infoContent.substr(hashStartPos, hashEndPos - hashStartPos);

    // Find torrent tracker section
    std::size_t trackersStartPos = infoContent.find("13:announce-list") + 17;
    std::size_t trackersEndPos = infoContent.find("e", trackersStartPos);
    std::string trackersContent = infoContent.substr(trackersStartPos, trackersEndPos - trackersStartPos);
    
    // Parse torrent trackers
    std::vector<std::string> trackers;
    std::size_t trackerStartPos = 0;
    while (trackerStartPos < trackersContent.length()) {
        std::size_t trackerEndPos = trackersContent.find(":", trackerStartPos);
        int trackerLength = std::stoi(trackersContent.substr(trackerStartPos, trackerEndPos - trackerStartPos));
        std::string tracker = trackersContent.substr(trackerEndPos + 1, trackerLength);
        this->trackers.push_back(tracker);
        trackerStartPos = trackerEndPos + 1 + trackerLength;
    }
}

std::string Torrent::toString(){
    return this->name + this->hash + std::string(this->trackers.begin(), this->trackers.end());
}