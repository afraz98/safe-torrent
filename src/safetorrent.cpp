#include "safetorrent.h"
#include "torrent.h"
#include <iostream>

int main(int argc, char* argv[]) {
    if(argc < 2){
        std::cerr << "USAGE: safetorrent <TORRENT_FILE.torrent>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    Torrent torrent = Torrent(std::string(filename));
    torrent.parseTorrent();
    return 0;
}