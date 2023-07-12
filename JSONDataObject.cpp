//
// Created by Ben Harris on 4/20/23.
//

#include "JSONDataObject.h"
#include "KeyValuePair.h"
#include <iostream>
#include<vector>

JSONDataObject::JSONDataObject() {
    _listOfDataItems = new std::vector<KeyValuePair *>();
}

JSONDataObject::~JSONDataObject() {
    delete _listOfDataItems;
}

void JSONDataObject::parseDataObject( Tokenizer *tokenizer ){

    Token token = tokenizer->getToken();
    if( ! token.isOpenCurlyBrace() ){
 		std::cout << "The input stream did not begin with a open curly brace " << std::endl;
 		std::cout << "and is therefore not valid. " << std::endl;
 		 exit(3);   
 	}
 	do {
        KeyValuePair *pair = new KeyValuePair();
        pair->parsePair(tokenizer);
        _listOfDataItems->push_back(pair);
        token = tokenizer->getToken();
        if( ! token.isComma() && ! token.isCloseCurlyBrace() ) {
            std::cout << "The input stream did not begin with a end with a curly brace " << std::endl;
            std::cout << " or contain a comma and is therefore not valid. " << std::endl;
            exit(3);
        }
 	} while( ! token.isCloseCurlyBrace() );
}

std::string JSONDataObject::valueForStringAttribute( std::string key ){
    std::string emptyStr = "";
    for (int i = 0; i < _listOfDataItems->size(); i++) {
        if(_listOfDataItems->at(i)->attributeName() == key)
            return _listOfDataItems->at(i)->stringValue();
    }
    // Should not reach this statement
    return emptyStr;
}

int JSONDataObject::valueForIntegerAttribute( std::string key ){
    for (int i = 0; i < _listOfDataItems->size(); i++) {
        if(_listOfDataItems->at(i)->attributeName() == key)
            return _listOfDataItems->at(i)->numberValue();
    }
    // Should not reach this statement
    return 0;
}





















