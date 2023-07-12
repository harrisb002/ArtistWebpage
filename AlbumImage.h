//
// Created by Ben harris on 5/9/2023.
//

#include<cstring>
#include<vector>
#include "JSONArray.h"

#ifndef PROJECT5_ALBUMIMAGE_H
#define PROJECT5_ALBUMIMAGE_H


class AlbumImage: public JSONDataObject{

public:
    AlbumImage();

    // image-types are "primary" and "secondary". primary-image,
    // if it exists, is preferred for including in html-files.
    std::string type();
    std::string uri();

    // The id of the artist to whom this image belongs.
    unsigned albumID();
    unsigned  width();
    unsigned  height();

    void print();

private:
    std::string _type, _uri;
    unsigned _width, _height, _albumID;
    bool cachedType, cachedAlbumID, cachedURI, cachedWidth, cachedHeight;
};

#endif //PROJECT5_ALBUMIMAGE_H
