/*
 * \file torrent.h
 * \brief Defines Torrent class
 * \author Anthony Frazier
 */

#ifndef TORRENT_H
#define TORRENT_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>

typedef uint8_t byte;

class Torrent {
    /* 
     * \class Torrent 
     * \brief Class describing a torrent provided in a .torrent file. 
     * 
     * For a more formal description, see the following: https://www.bittorrent.org/beps/bep_0003.html?ref=skerritt.blog 
     */
    public:
        /*
         * \brief Default constructor
         * \param filename Torrent filename
         */
        Torrent(std::string filename);

        ~Torrent();

        /*
         * \brief parseTorrent Parse torrent file for relevant information.
         */
        void parseTorrent();

        /*
         * \brief toString Retrieve string representation of a torrent. 
         * \returns String representation of the torrent
         * Note: This should be used AFTER parsing a torrent. 
         */
        std::string toString();

    private:
        std::string filename;
};


#endif // TORRENT_H