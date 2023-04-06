/*
    \file torrent.h
    \brief Defines Torrent class
    \author Anthony Frazier
*/

#ifndef TORRENT_H
#define TORRENT_H

#include <iostream>
#include <vector>
#include <stdlib.h>

class Torrent {
    /* Class describing a torrent provided in a .torrent file. 
        For a more formal description, see the following: https://www.bittorrent.org/beps/bep_0003.html?ref=skerritt.blog 
    */
    public:
        /*
         \brief Default constructor
         \param filename Torrent filename
        */
        Torrent(std::string filename);

        ~Torrent();

        void parseTorrent();

        std::string toString();

    private:
        std::string filename;
        std::string name;
        std::string hash;
        std::vector<std::string> trackers;
};


#endif // TORRENT_H