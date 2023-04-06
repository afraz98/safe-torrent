#include "safetorrent.h"
#include "torrent.h"

int main()
{
    Torrent torrent = Torrent("/home/toeknee/git-repos/safe-torrent/torrent-files/ubuntu-16.04-desktop-amd64.iso.torrent");
    torrent.parseTorrent();
    std::cout << torrent.toString() << std::endl;
    return 0;
}