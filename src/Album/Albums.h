//
// Created by Benjamin Harris on 4/9/23.
//
#include <vector>
#include "Album.h"

#ifndef PROJ4_ALBUMS_H
#define PROJ4_ALBUMS_H


class Albums: public JSONArray {
public:
    virtual ~Albums() = default;

    int numAlbums(){ return _listOfDataObjects->size(); }
    void addAlbum(Album *album){ _listOfDataObjects->push_back(album); }
    void loadAlbumsFromFile(std::string fileName);

    JSONDataObject *jsonObjectNode() override { return new Album(); }
    std::vector<Album *> *listOfAlbums() { return (std::vector<Album *> *) _listOfDataObjects; }

    Albums *albumsForArtistWithID(int artistID);

    void print();

};
#endif //PROJ4_ALBUMS_H
