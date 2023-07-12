//
// Created by Benjamin Harris on 4/9/23.
//
#include <vector>
#include "Track.h"

#ifndef PROJ4_TRACKS_H
#define PROJ4_TRACKS_H

class Tracks:  public JSONArray {
public:

    int numTracks(){ return _listOfDataObjects->size(); }
    void addTrack(Track *track){ _listOfDataObjects->push_back(track); }

    void loadTracksFromFile(std::string fileName);
    std::string htmlString();
    void writeHTMLFile(std::string htmlString);

    JSONDataObject *jsonObjectNode() override { return new Track(); }

    std::vector<Track *> *listOfTracks() { return (std::vector<Track *> *) _listOfDataObjects; }

    Tracks *tracksForAlbumWithID(int albumID);

    void print();
};
#endif //PROJ4_TRACKS_H