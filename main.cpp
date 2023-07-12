#include <iostream>
#include <fstream>
#include "Artists.h"
#include "Albums.h"
#include "Tracks.h"
#include "ArtistImages.h"
#include "AlbumImages.h"

int main(int argc, char *argv[]) {

    if( argc < 1 ) {  // we expect the name of the file as an argument to the program.
        std::cout << "usage: " << argv[0] << " nameOfAnInputFile" << std::endl;
        exit(1);
    }

    // Here, we open the file to make sure that it exists before starting the program.
    // When using CLion, the input file has to be in cmake-build-debug directory.
    std::fstream inputStream;
    inputStream.open(argv[1], std::ios::in);    // open for reading
    if( ! inputStream.is_open()) {
        std::cout << "Unable to open " << argv[1] << ". Terminating...";
        exit(1);
    }
    // We now know that the input file exists and we can read from it. Here, we will close it
    // and give parseFromJSONstream 'inputStream' so that it just uses it.
    inputStream.close();


    // artists_human_readable.json artist_images_human_readable.json albums_human_readable.json album_images_human_readable.json tracks_human_readable.json

    // Load Artists
    Artists *artistsArray = new Artists();
    artistsArray->loadArtistsFromFile(argv[1]);

    // Load Albums
    Albums *albumsArray = new Albums();
    albumsArray->loadAlbumsFromFile(argv[3]);

    Tracks *tracksArray = new Tracks();
    tracksArray->loadTracksFromFile(argv[5]);

    // Load Images for Artists
    ArtistImages *artistImagesArray = new ArtistImages();
    artistImagesArray->loadArtistImagesFromFile(argv[2]);

    // Load Images for Albums
    AlbumImages *albumImagesArray = new AlbumImages();
    albumImagesArray->loadAlbumImagesFromFile(argv[4]);

    // Set all Images for each Album
    for (int i = 0; i < albumsArray->numAlbums(); i++) {
        albumsArray->listOfAlbums()->at(i)->setAlbumImage(albumImagesArray);
    }


    // Set all Images for each Artist
    for (int i = 0; i < artistsArray->numArtists(); i++) {
        artistsArray->listOfArtists()->at(i)->setArtistImage(artistImagesArray);
    }

//    // Create Relationships between Entities
//    // i.e. Artists/Albums and Albums/Tracks

    // For each artistID find all albums that pertain to it and set them for that Artist
    for (int i = 0; i < artistsArray->numArtists(); i++) {
        artistsArray->listOfArtists()->at(i)->setAlbums(
                albumsArray->albumsForArtistWithID(artistsArray->listOfArtists()->at(i)->artistID()));
    }

   // For each albumID find all tracks that pertain to it and set them for that Album
    for (int i = 0; i < albumsArray->numAlbums(); i++) {
        albumsArray->listOfAlbums()->at(i)->setTracks(
                tracksArray->tracksForAlbumWithID(albumsArray->listOfAlbums()->at(i)->albumID()));
    }

    artistsArray->writeHTMLFile(artistsArray->htmlString());

    delete artistsArray;
    delete artistImagesArray;
    delete albumsArray;
    delete albumImagesArray;
    delete tracksArray;


    return 0;
}
