//
// Created by Benjamin Harris on 4/13/23.
//

#include "Tracks.h"
#include <iostream>
#include <vector>

std::string Tracks::htmlString(){
    // Construct the modified string of characters for HTML string
    std::string HTML;

    HTML = "<ol>";
    for (int i = 0; i < numTracks(); i++) {
        HTML += "<li><p> ";
        HTML += "</p><ul><li><p>title ";
        HTML += listOfTracks()->at(i)->title();
        HTML += "</p></li><li><p>artist_name ";
        HTML += listOfTracks()->at(i)->artistName();
        HTML += "</p></li><li><p>album_name ";
        HTML += listOfTracks()->at(i)->albumName();
        HTML += "</p></li><li><p>duration ";
        HTML += listOfTracks()->at(i)->duration();
        HTML += "</p></li><li><p>position ";
        HTML += listOfTracks()->at(i)->position();
        HTML += "</p></li><li><p>albumID ";
        HTML += std::to_string(listOfTracks()->at(i)->albumID());
        HTML += "</p></li></ul></li>";
    }
    HTML += "</ol>";

    return HTML;
}

void Tracks::writeHTMLFile(std::string htmlString) {

    std::fstream inputFile("tracks_template.html");

    if (!inputFile.is_open()) {
        std::cerr << "Failed to open file: " << "tracks_template.html" << std::endl;
        exit(6);
    }

    // Read the contents of the file and store in the string fileContents
    std::string fileContents((std::istreambuf_iterator<char>(inputFile)),
                             std::istreambuf_iterator<char>());

    // Find the position of the placeholder in the text
    std::string placeholder = "{% tracks %}";
    size_t pos = fileContents.find(placeholder);

    if (pos == std::string::npos) {
        std::cerr << "Placeholder not found in file: " << "tracks_template.html" << std::endl;
        exit(7);
    }

    // Replace the placeholder text with the HTML string and write the modified file back to the original file
    fileContents.replace(pos, placeholder.length(), htmlString);
    std::fstream outputFile("tracks_template.html");
    outputFile << fileContents;
    outputFile.close();
}


//New Implementation
void Tracks::loadTracksFromFile(std::string tracksFileName)
{
    Tokenizer *tokenizer = new Tokenizer(tracksFileName);
    parseJSONArray(tokenizer);
    delete tokenizer;
}

void Tracks::print() {
    for (int i = 0; i < numTracks(); i++) {
        listOfTracks()->at(i)->print();
    }
}

Tracks * Tracks::tracksForAlbumWithID(int albumID) {
    Tracks *tracksWithAlbumID = new Tracks();
    for (int i = 0; i < numTracks(); i++) {
        // Add all albums that pertain to certain Artist to albumsWithArtistID
        if (listOfTracks()->at(i)->albumID() == albumID)
            tracksWithAlbumID->addTrack(listOfTracks()->at(i));
    }
    return tracksWithAlbumID;
}


