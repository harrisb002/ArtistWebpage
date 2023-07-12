//
// Created by Benjamin Harris on 5/9/23.
//

#include "ArtistImage.h"
#include <iostream>

ArtistImage::ArtistImage() {
    _type = "";
    _artistID = 0;
    _uri = "";
    _width = 0;
    _height = 0;
}

std::string ArtistImage::type(){
    if( cachedType )
        return _type;
    cachedType = true;
    return _type = valueForStringAttribute("type");
}

unsigned ArtistImage::artistID(){
    if( cachedArtistID )
        return _artistID;
    cachedArtistID = true;
    return _artistID = valueForIntegerAttribute("artist_id");
}

std::string ArtistImage::uri(){
    if( cachedURI )
        return _uri;
    cachedURI = true;
    return _uri = valueForStringAttribute("uri");
}

unsigned ArtistImage::width(){
    if( cachedWidth )
        return _width;
    cachedWidth = true;
    return _width = valueForIntegerAttribute("width");
}

unsigned ArtistImage::height(){
    if( cachedHeight )
        return _height;
    cachedHeight = true;
    return _height = valueForIntegerAttribute("height");
}


//For debugging
void ArtistImage::print() {
    std:: cout << "The type is: " << type() << std:: endl;
    std:: cout << "The artistID is: " << artistID() << std:: endl;
    std:: cout << "The uri is: " << uri() << std:: endl;
    std:: cout << "The width is: " << width() << std:: endl;
    std:: cout << "The height is: " << height() << std:: endl;
}
