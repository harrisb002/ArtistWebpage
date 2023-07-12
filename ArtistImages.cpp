//
// Created by Benjamin Harris on 5/9/23.
//

#include "ArtistImages.h"
#include <iostream>
#include <vector>

//New Implementation
void ArtistImages::loadArtistImagesFromFile(std::string ArtistImagesFileName)
{
    Tokenizer *tokenizer = new Tokenizer(ArtistImagesFileName);
    parseJSONArray(tokenizer);
    delete tokenizer;
}
