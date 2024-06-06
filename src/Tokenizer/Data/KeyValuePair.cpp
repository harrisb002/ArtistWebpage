//
// Created by Ben Harris on 4/20/23.
//

#include "KeyValuePair.h"
#include <iostream>
#include <string>

KeyValuePair::KeyValuePair() {
    _attributeName = "";
    _attributeStringValue = "";
    _attributeNumberValue = 0;
    _isNumber = 0;
}

void KeyValuePair::parsePair(Tokenizer *tokenizer){

    // Validate start-quote
    if( ! tokenizer->getToken().isQuote() ){
 		std::cout << "The input stream did not begin with a quote " << std::endl;
 		std::cout << "and is therefore not valid. " << std::endl;
 		 exit(4);
 	}

 	// Get/Set Key
    _attributeName = tokenizer->stringValue();

    // Validate end-quote
    if( ! tokenizer->getToken().isQuote() ){
        std::cout << "The input stream did not begin with a quote " << std::endl;
        std::cout << "and is therefore not valid. " << std::endl;
        exit(4);
    }

    // Validate colon between Key-Value Pairs
    if ( ! tokenizer->getToken().isColon()) {
 		std::cout << "The input stream did not have a colon " << std::endl;
 		std::cout << "and is therefore not valid. " << std::endl;
 		 exit(4);
    }

    // Determine if value is a number without quotes i:e: duration, album_id, ect and if so get it
    if (tokenizer->isNumber()) {
        _attributeNumberValue = tokenizer->getIntValue();
        _isNumber = true;
        return;
    }
    _isNumber = false; // Value is not a number

    if ( ! tokenizer->getToken().isQuote()) {
 		std::cout << "The input stream did not end with a quote " << std::endl;
 		std::cout << "and is therefore not valid. " << std::endl;
 		 exit(4);
    }

    // Used to find parenthesis without taking char out of input stream
    if (tokenizer->isParenthesis()) {  // Value is an empty string
        // Validate end-quote
        if ( ! tokenizer->getToken().isQuote()) {
            std::cout << "The input stream did not end with a quote " << std::endl;
            std::cout << "and is therefore not valid. " << std::endl;
            exit(4);
        }
        return;
    }

    // If not empty string then read in the string.
    _attributeStringValue = tokenizer->stringValue();

    // Validate end-quote
    if ( ! tokenizer->getToken().isQuote()) {
        std::cout << "The input stream did not end with a quote " << std::endl;
        std::cout << "and is therefore not valid. " << std::endl;
        exit(4);
    }
    return;
}

//For Debugging
void KeyValuePair::print() {
    std::cout << "attribute name is: " << _attributeName << std::endl;
    if(isNumber())
        std::cout << "attribute number is: " <<  _attributeNumberValue << std::endl;

    std::cout << "attribute string is: " <<  _attributeStringValue << std::endl;
}


















