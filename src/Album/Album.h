#include <cstring>
#include <vector>
#include "../Tracks/Tracks.h"
#include "Images/AlbumImages.h"
#include "../JSON/JSONArray.h"

#ifndef PROJ4_ALBUM_H
#define PROJ4_ALBUM_H

class Album: public JSONDataObject {
public:
    Album();

    std::string title();
    std::string genre();
    std::string year();
    unsigned albumID();
    unsigned artistID();
    unsigned numImages();
    unsigned numTracks();

    void setTracks(Tracks *tracks) { _tracks = tracks; }

    Tracks *tracks()  { return _tracks; }

    AlbumImage *&primaryImage() { return _primaryImage;   }
    AlbumImage *&secondaryImage()  { return _secondaryImage; }

    //void setArtist(Artist *artist);
    //Artist *artist();

    void print();

    std::string htmlString();

    void setAlbumImage(AlbumImages *);

    bool primaryImageFound, secondaryImageFound;

private:
    std::string _title, _genre, _year;
    unsigned _albumID, _artistID, _numImages, _numTracks;
    bool cachedTitle, cachedGenre, cachedYear, cachedAblumID,
            cachedArtistID, cachedNumImgaes, cachedNumTracks;

    AlbumImage *_primaryImage, *_secondaryImage;
    Tracks *_tracks;
};

#endif //PROJ4_ALBUM_H

