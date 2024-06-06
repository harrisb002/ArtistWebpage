//
// Created by Ben Harris on 4/20/23.
//

#ifndef PROJECT4_TOKENIZER_HPP
#define PROJECT4_TOKENIZER_HPP

#include <string>
#include <fstream>
#include "Token.h"

class Tokenizer {

public:
    Tokenizer(std::string);
    Token getToken();
    
    // Used to determine if next value in parsePair without removing character from input stream in parsePair
	bool isNumber();
	bool isParenthesis();

    // Used to return Key/Values from input stream to parsePair
    std::string stringValue();
    int getIntValue();

private:
    std::string inputFileName;
    std::ifstream inputStream;
    
    bool isToken;
    Token returnedToken;

    bool charOfInterest(char c);
    Token returnToken();
};


#endif //PROJECT4_TOKENIZER_HPP
