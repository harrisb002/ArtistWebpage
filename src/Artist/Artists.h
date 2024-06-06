//
// Created by Benjamin Harris on 4/13/23.
//
#include <vector>
#include "Artist.h"
#include "../Album/Albums.h"

#ifndef PROJ4_ARTISTS_H
#define PROJ4_ARTISTS_H

class Artists : public JSONArray {
public:
    virtual ~Artists() = default;

    int numArtists() { return _listOfDataObjects->size(); }
    void addArtist(Artist *artist) { _listOfDataObjects->push_back(artist); }

    void loadArtistsFromFile(std::string fileName);
    std::string htmlString();
    void writeHTMLFile(std::string htmlString);

    JSONDataObject *jsonObjectNode() override { return new Artist(); }

    std::vector<Artist *> *listOfArtists() { return (std::vector<Artist *> *) _listOfDataObjects; }

    void print();

//  void runAsserts();  // used for checking the integrity of this class.

};

#endif //PROJ4_ARTISTS_H
