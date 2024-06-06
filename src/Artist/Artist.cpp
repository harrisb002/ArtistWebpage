//
// Created by Ben Harris on 4/20/23.
//

#include <iostream>
#include "Artist.h"

Artist::Artist() {
    _name = "";
    _realName = "Unknown";
    _profile = "Unknown";
    _numImages = "0";
    _artistID = 0;
    cachedName = 0;
	cachedRealName = 0;
	cachedProfile = 0;
	cachedNumImages = 0;
	cachedArtistID = 0;
    primaryImageFound = 0;
    secondaryImageFound = 0;
}

std::string Artist::profile(){
    if( cachedProfile )
        return _profile;
    cachedProfile = true;
    return _profile = valueForStringAttribute("profile");
}
    
std::string Artist::artistName(){
    if( cachedName )
        return _name;
    cachedName = true;
    return _name = valueForStringAttribute("artist_name");
}
    
std::string Artist::realName(){
    if( cachedRealName )
        return _realName;
    cachedRealName = true;
    return _realName = valueForStringAttribute("real_name");
}
    
std::string Artist::numImages(){
    if( cachedNumImages )
        return _numImages;
    cachedNumImages = true;
    return _numImages = valueForStringAttribute("num_images");
}  
    
unsigned Artist::artistID(){
    if( cachedArtistID )
        return _artistID;
    cachedArtistID = true;
    return _artistID = valueForIntegerAttribute("artist_id");
}

void Artist::setArtistImage(ArtistImages * artistImages){
    for (int i = 0; i < artistImages->numArtistImages(); i++) {
        if(artistImages->listOfArtistImages()->at(i)->artistID() == artistID()) {
            if (artistImages->listOfArtistImages()->at(i)->type() == "primary") {
                _primaryImage = artistImages->listOfArtistImages()->at(i);
                primaryImageFound = true;
            } else {
                _secondaryImage = artistImages->listOfArtistImages()->at(i);
                secondaryImageFound = true;
            }
        }
    }
}


//For debugging
void Artist::print() {
    std:: cout << "The name of artist is: " << artistName() << std:: endl;
    std:: cout << "The realName of artist is: " << realName() << std:: endl;
    std:: cout << "The artistID of artist is: " << artistID() << std:: endl;
    std:: cout << "The numImages of artist is: " << numImages() << std:: endl;
    std:: cout << "The profile of artist is: " << profile() << std:: endl << std::endl;
    std:: cout << "The Album information of this artist is: " << std:: endl;
    _albums->print(); std:: cout << std:: endl;

    if (primaryImageFound){
        std:: cout << "The Image information of this artist is: " << std:: endl;
        _primaryImage->print();
    }
    if(secondaryImageFound){
        std:: cout << "The Image information of this artist is: " << std:: endl;
        _secondaryImage->print();
    }
}
