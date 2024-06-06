//
// Created by Benjamin Harris on 5/9/23.
//

#include<cstring>
#include<vector>
#include "../../JSON/JSONArray.h"

#ifndef PROJECT5_ARTISTIMAGE_H
#define PROJECT5_ARTISTIMAGE_H


class ArtistImage: public JSONDataObject {

public:
    ArtistImage();

    // image-types are "primary" and "secondary". primary-image,
    // if it exists, is preferred for including in html-files.
    std::string type();
    std::string uri();

    // The id of the artist to whom this image belongs.
    unsigned artistID();
    unsigned  width();
    unsigned  height();

    void print();

private:
    std::string _type, _uri;
    unsigned _width, _height, _artistID;
    bool cachedType, cachedArtistID, cachedURI, cachedWidth, cachedHeight;
};

#endif //PROJECT5_ARTISTIMAGE_H
