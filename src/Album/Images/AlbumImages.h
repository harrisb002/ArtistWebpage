//
// Created by harri on 5/9/2023.
//

#include <vector>
#include "AlbumImage.h"

#ifndef PROJECT5_ALBUMIMAGES_H
#define PROJECT5_ALBUMIMAGES_H


class AlbumImages: public JSONArray   {

public:
    virtual ~AlbumImages() = default;

    int numAlbumImages() { return _listOfDataObjects->size(); }

    void loadAlbumImagesFromFile(std::string fileName);

    JSONDataObject *jsonObjectNode() override { return new AlbumImage(); }

    std::vector<AlbumImage *> *listOfAlbumImages() { return (std::vector<AlbumImage *> *) _listOfDataObjects; }

    void print();
};


#endif //PROJECT5_ALBUMIMAGES_H
