#include <cstring>
#include "../JSON/JSONArray.h"
#include "Images/ArtistImages.h"
#include "../Album/Albums.h"

#ifndef PROJECT4_ARTIST_HPP
#define PROJECT4_ARTIST_HPP

class Artist: public JSONDataObject {

public:
    Artist();

    std::string profile();
    std::string artistName();
    std::string realName();
    std::string numImages();  // since it's a string in the JSON file
    unsigned    artistID();

    void print();

   // the following 4 function-prototypes are new to this project.
   void setAlbums(Albums *albums) { _albums = albums; }
   Albums *albums() { return _albums; }

   ArtistImage *&primaryImage()       { return _primaryImage;   }
   ArtistImage *&secondaryImage()     { return _secondaryImage; }

   void setArtistImage(ArtistImages *);

   bool primaryImageFound, secondaryImageFound;

private:
    std::string _name, _realName, _profile, _numImages;
    unsigned _artistID;
    bool cachedName, cachedRealName, cachedProfile, cachedNumImages, cachedArtistID;

    // the following 3 variables are new to this project.
    ArtistImage *_primaryImage, *_secondaryImage;
    Albums *_albums;
    
};
#endif //PROJECT4_ARTIST_HPP










