//
// Created by Benjamin Harris on 5/9/23.
//

#include <vector>
#include "ArtistImage.h"

#ifndef PROJECT5_ARTISTIMAGES_H
#define PROJECT5_ARTISTIMAGES_H


class ArtistImages: public JSONArray  {

public:
    virtual ~ArtistImages() = default;

    int numArtistImages() { return _listOfDataObjects->size(); }

    void loadArtistImagesFromFile(std::string fileName);

    JSONDataObject *jsonObjectNode() override { return new ArtistImage(); }

    std::vector<ArtistImage *> *listOfArtistImages() { return (std::vector<ArtistImage *> *) _listOfDataObjects; }

    void print();
};


#endif //PROJECT5_ARTISTIMAGES_H
