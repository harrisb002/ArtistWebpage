#include<cstring>
#include<vector>
#include "KeyValuePair.h"
#include "JSONArray.h"

#ifndef PROJ4_TRACK_H
#define PROJ4_TRACK_H

class Track: public JSONDataObject
{
public:
    Track();

    std::string title();
    std::string artistName();
    std::string albumName();
    std::string duration();
    std::string position();
    unsigned    albumID();

    void print();

//  std::string htmlString();

private:
    std::string _title, _artistName, _albumName, _duration, _position;
    unsigned _albumID;
    bool cachedTitle, cachedArtistName, cachedAlbumName, cachedDuration, cachedPosition, cachedAlbumId;
};

#endif //PROJ4_TRACK_H
