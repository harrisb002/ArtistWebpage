cmake_minimum_required(VERSION 3.24)
project(Project5)

set(CMAKE_CXX_STANDARD 17)

add_executable(Project5 main.cpp Token.cpp Token.h Tokenizer.cpp Tokenizer.h KeyValuePair.cpp KeyValuePair.h JSONArray.cpp
        JSONArray.h JSONDataObject.cpp JSONDataObject.h Artists.cpp Artists.h Artist.cpp Artist.h Album.h
        Album.cpp Albums.cpp Albums.h Track.h Track.cpp Tracks.cpp Tracks.h ArtistImage.cpp ArtistImage.h
        ArtistImages.h ArtistImages.cpp AlbumImages.cpp AlbumImages.h AlbumImage.cpp AlbumImage.h)

