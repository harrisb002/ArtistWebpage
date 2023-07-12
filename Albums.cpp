//
// Created by Benjamin Harris on 4/13/23.
//

#include "Albums.h"
#include <iostream>
#include <vector>

//New Implementation
void Albums::loadAlbumsFromFile(std::string albumsFileName)
{
    Tokenizer *tokenizer = new Tokenizer(albumsFileName);
    parseJSONArray(tokenizer);
    delete tokenizer;
}

void Albums::print() {
    for (int i = 0; i < numAlbums(); i++) {
        listOfAlbums()->at(i)->print();
    }
}

Albums * Albums::albumsForArtistWithID(int artistID) {
    Albums *albumsWithArtistID = new Albums();
    for (int i = 0; i < numAlbums(); i++) {
        // Add all albums that pertain to certain Artist to albumsWithArtistID
        if (listOfAlbums()->at(i)->artistID() == artistID)
            albumsWithArtistID->addAlbum(listOfAlbums()->at(i));
    }
    return albumsWithArtistID;
}


