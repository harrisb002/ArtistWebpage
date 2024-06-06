//
// Created by Benjamin Harris on 4/9/23.
//
#include <iostream>
#include <vector>
#include "Track.h"
#include "../Tokenizer/Data/KeyValuePair.h"

Track::Track() {
    _title = "";
    _artistName = "";
    _albumName = "";
    _duration = "";
    _position = "";
    _albumID = 0;
}

std::string Track::title(){
    if( cachedTitle )
        return _title;
    cachedTitle = true;
    return _title = valueForStringAttribute("title");
}

std::string Track::artistName(){
    if( cachedArtistName )
        return _artistName;
    cachedArtistName = true;
    return _artistName = valueForStringAttribute("artist_name");
}

std::string Track::albumName(){
    if( cachedAlbumName )
        return _albumName;
    cachedAlbumName = true;
    return _albumName = valueForStringAttribute("album_name");
}

std::string Track::duration(){
    if( cachedDuration )
        return _duration;
    cachedDuration = true;
    return _duration = valueForStringAttribute("duration");
}

std::string Track::position(){
    if( cachedPosition )
        return _position;
    cachedPosition = true;
    return _position = valueForStringAttribute("position");
}

unsigned Track::albumID(){
    if( cachedAlbumId )
        return _albumID;
    cachedAlbumId = true;
    return _albumID = valueForIntegerAttribute("album_id");
}

// For debugging
void Track::print() {
    std::cout << "The _title is: " << title() << std::endl;
    std::cout << "The _artistName is: " << artistName() << std::endl;
    std::cout << "The _albumName is: " << albumName() << std::endl;
    std::cout << "The _albumID is: " << albumID() << std::endl;
    std::cout << "The _duration is: " << duration() << std::endl;
    std::cout << "The _position is: " << position() << std::endl;
    std::cout << std::endl;
}