//
// Created by Benjamin Harris on 4/9/23.
//
#include <iostream>
#include <vector>
#include "Album.h"

Album::Album() {
    _title = "";
    _genre = "";
    _year = "";
    _albumID = 0;
    _artistID = 0;
    _numImages = 0;
    _numTracks = 0;
    primaryImageFound = 0;
    secondaryImageFound = 0;
}


std::string Album::title(){
    if( cachedTitle )
        return _title;
    cachedTitle = true;
    return _title = valueForStringAttribute("title");
}

std::string Album::genre(){
    if( cachedGenre )
        return _genre;
    cachedGenre = true;
    return _genre = valueForStringAttribute("genres");
}

std::string Album::year(){
    if( cachedYear )
        return _year;
    cachedYear = true;
    return _year = valueForStringAttribute("year");
}

unsigned Album::albumID(){
    if( cachedAblumID )
        return _albumID;
    cachedAblumID = true;
    return _albumID = valueForIntegerAttribute("album_id");
}

unsigned Album::artistID(){
    if( cachedArtistID )
        return _artistID;
    cachedArtistID = true;
    return _artistID = valueForIntegerAttribute("artist_id");
}

unsigned Album::numImages(){
    if( cachedNumImgaes )
        return _numImages;
    cachedNumImgaes = true;
    return _numImages = valueForIntegerAttribute("num_images");
}

unsigned Album::numTracks(){
    if( cachedNumTracks )
        return _numTracks;
    cachedNumTracks = true;
    return _numTracks = valueForIntegerAttribute("num_tracks");
}

void Album::setAlbumImage(AlbumImages * albumImages){
    for (int i = 0; i < albumImages->numAlbumImages(); i++) {
        if(albumImages->listOfAlbumImages()->at(i)->albumID() == albumID()) {
            if (albumImages->listOfAlbumImages()->at(i)->type() == "primary") {
                _primaryImage = albumImages->listOfAlbumImages()->at(i);
                primaryImageFound = true;
            } else {
                _secondaryImage = albumImages->listOfAlbumImages()->at(i);
                secondaryImageFound = true;
            }
        }
    }
}



//Debugging
void Album::print() {
    std:: cout << "The name of title is: " << title() << std:: endl;
    std:: cout << "The genre is: " << genre() << std:: endl;
    std:: cout << "The year is: " << year() << std:: endl;
    std:: cout << "The album_id is: " << albumID() << std:: endl;
    std:: cout << "The artist_id is: " << artistID() << std:: endl;
    std:: cout << "The num_tracks is: " << numTracks() << std:: endl;
    std:: cout << "The num_images is: " << numImages() << std:: endl << std::endl;

    std:: cout << "The Tracks information of this Album is: " << std:: endl;
    _tracks->print();
    std:: cout << std::endl << std::endl;

    if (primaryImageFound){
        std:: cout << "The Image information of this artist is: " << std:: endl;
        _primaryImage->print();
    }
    if(secondaryImageFound){
        std:: cout << "The Image information of this artist is: " << std:: endl;
        _secondaryImage->print();
    }

}