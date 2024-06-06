//
// Created by Benjamin Harris on 4/13/23.
//

#include "Artists.h"
#include <iostream>
#include <vector>

std::string Artists::htmlString(){
    // Construct the modified string of characters for HTML string
    std::string HTML;

    for (int i = 0; i < numArtists(); i++) {
        // Start with Artists HTML
        HTML += "<h2>";
        HTML += listOfArtists()->at(i)->artistName();
        HTML += "</h2><img class=\"image\" width=";

        // Print Artist Image
        if(listOfArtists()->at(i)->primaryImageFound){
            HTML +=  std::to_string(listOfArtists()->at(i)->primaryImage()->width());
            HTML += " height=";
            HTML +=  std::to_string(listOfArtists()->at(i)->primaryImage()->height());
            HTML += " src=\"";
            HTML += listOfArtists()->at(i)->primaryImage()->uri();
        }
        else if(listOfArtists()->at(i)->secondaryImageFound){
            HTML +=  std::to_string(listOfArtists()->at(i)->secondaryImage()->width());
            HTML += " height=";
            HTML +=  std::to_string(listOfArtists()->at(i)->secondaryImage()->height());
            HTML += " src=\"";
            HTML += listOfArtists()->at(i)->secondaryImage()->uri();
        }

        // Print Artist Info
        HTML += "\"><table class=\"artistInfo\"><tr><td class=\"tagName\">Number of Images:</td><td class=\"value\">";
        HTML += listOfArtists()->at(i)->numImages();
        HTML += "</td></tr><tr><td>Profile:</td><td class=\"value\">";
        HTML += listOfArtists()->at(i)->profile();

        // Continue with all Albums HTML for each artist
        HTML += "</td></tr></table><div class=\"clear\">&nbsp;</div><h2>Albums</h2><ol>";
        for (int j = 0; j < listOfArtists()->at(i)->albums()->numAlbums(); j++) {
            HTML += "<li><p><strong>";
            HTML += listOfArtists()->at(i)->albums()->listOfAlbums()->at(j)->title();
            HTML += "</strong></p><img class=\"image\" width=";

            // Print Album Image
            if(listOfArtists()->at(i)->albums()->listOfAlbums()->at(j)->primaryImageFound){
                HTML +=  std::to_string(listOfArtists()->at(i)->
                        albums()->listOfAlbums()->at(j)->primaryImage()->width());
                HTML += " height=";
                HTML +=  std::to_string(listOfArtists()->at(i)->
                        albums()->listOfAlbums()->at(j)->primaryImage()->height());
                HTML += " src=\"";
                HTML += listOfArtists()->at(i)->albums()->listOfAlbums()->at(j)->primaryImage()->uri();
            }
            else if(listOfArtists()->at(i)->albums()->listOfAlbums()->at(j)->secondaryImageFound){
                HTML +=  std::to_string(listOfArtists()->at(i)->
                        albums()->listOfAlbums()->at(j)->secondaryImage()->width());
                HTML += " height=";
                HTML +=  std::to_string(listOfArtists()->at(i)->
                        albums()->listOfAlbums()->at(j)->secondaryImage()->height());
                HTML += " src=\"";
                HTML += listOfArtists()->at(i)->albums()->listOfAlbums()->at(j)->secondaryImage()->uri();
            }

            // List Album Info
            HTML += "\"><table class=\"albumInfo\"><tr><td class=\"aTitle\" colspan=2>";
            HTML += listOfArtists()->at(i)->albums()->listOfAlbums()->at(j)->title();
            HTML += "</td></tr><tr><td class=\"tdNarrow\">Artist:</td><td class=\"value\">";
            HTML += listOfArtists()->at(i)->artistName();
            HTML += "</td></tr><tr><td class=\"tdNarrow\">Genres:</td><td class=\"value\">";
            HTML += listOfArtists()->at(i)->albums()->listOfAlbums()->at(j)->genre();
            HTML += "</td></tr><tr><td>Year:</td><td class=\"value\">";
            HTML += listOfArtists()->at(i)->albums()->listOfAlbums()->at(j)->year();
            HTML += "</td></tr></table><div class=\"clear\">&nbsp;</div>";

            // Continue by including all Tracks for the Album
            HTML += "<h2>Tracklist</h2><table class=\"tracks\">";
            for (int k = 0; k < listOfArtists()->at(i)->albums()->listOfAlbums()->at(j)->tracks()->numTracks(); k++) {
                HTML += "<tr class=\"tracks\"><td class=\"trackName\">";
                HTML += listOfArtists()->at(i)->albums()->
                        listOfAlbums()->at(j)->tracks()->listOfTracks()->at(k)->title();
                HTML += "</td><td>";
                HTML += listOfArtists()->at(i)->albums()->
                        listOfAlbums()->at(j)->tracks()->listOfTracks()->at(k)->duration();
                HTML += "</td></tr>";
            }
            HTML += "</table></li>";
        }
        HTML += "</ol>";
    }
    return HTML;
}

void Artists::writeHTMLFile(std::string htmlString) {

    std::fstream inputFile("art.html");

    if (!inputFile.is_open()) {
        std::cerr << "Failed to open file: " << "art.html" << std::endl;
        exit(6);
    }

    // Read the contents of the file and store in the string fileContents
    std::string fileContents((std::istreambuf_iterator<char>(inputFile)),
                             std::istreambuf_iterator<char>());

    // Find the position of the placeholder in the text
    std::string placeholder = "{% artists %}";
    size_t pos = fileContents.find(placeholder);

    if (pos == std::string::npos) {
        std::cerr << "Placeholder not found in file: " << "art.html" << std::endl;
        exit(7);
    }

    // Replace the placeholder text with the HTML string and write the modified file back to the original file
    fileContents.replace(pos, placeholder.length(), htmlString);
    std::fstream outputFile("art.html");
    outputFile << fileContents;
    outputFile.close();
}


//New Implementation
void Artists::loadArtistsFromFile(std::string artistsFileName)
{
    Tokenizer *tokenizer = new Tokenizer(artistsFileName);
    parseJSONArray(tokenizer);
    delete tokenizer;
}

