//
// Created by harri on 5/9/2023.
//

#include "AlbumImages.h"
#include <iostream>
#include <vector>

//New Implementation
void AlbumImages::loadAlbumImagesFromFile(std::string AlbumImagesFileName)
{
    Tokenizer *tokenizer = new Tokenizer(AlbumImagesFileName);
    parseJSONArray(tokenizer);
    delete tokenizer;
}
