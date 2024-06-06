//
// Created by harri on 5/9/2023.
//

#include "AlbumImage.h"
#include <iostream>

AlbumImage::AlbumImage() {
    _type = "";
    _albumID = 0;
    _uri = "";
    _width = 0;
    _height = 0;
}

std::string AlbumImage::type(){
    if( cachedType )
        return _type;
    cachedType = true;
    return _type = valueForStringAttribute("type");
}

unsigned AlbumImage::albumID(){
    if( cachedAlbumID )
        return _albumID;
    cachedAlbumID = true;
    return _albumID = valueForIntegerAttribute("album_id");
}

std::string AlbumImage::uri(){
    if( cachedURI )
        return _uri;
    cachedURI = true;
    return _uri = valueForStringAttribute("uri");
}

unsigned AlbumImage::width(){
    if( cachedWidth )
        return _width;
    cachedWidth = true;
    return _width = valueForIntegerAttribute("width");
}

unsigned AlbumImage::height(){
    if( cachedHeight )
        return _height;
    cachedHeight = true;
    return _height = valueForIntegerAttribute("height");
}


//For debugging
void AlbumImage::print() {
    std:: cout << "The type is: " << type() << std:: endl;
    std:: cout << "The artistID is: " << albumID() << std:: endl;
    std:: cout << "The uri is: " << uri() << std:: endl;
    std:: cout << "The width is: " << width() << std:: endl;
    std:: cout << "The height is: " << height() << std:: endl << std:: endl;
}
