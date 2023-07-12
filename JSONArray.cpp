//
// Created by Ben Harris on 4/20/23.
//
#include "JSONArray.h"
#include "JSONDataObject.h"
#include "Tokenizer.h"
#include <iostream>
#include<vector>

JSONArray::JSONArray() {
    _listOfDataObjects = new std::vector<JSONDataObject *>();
}

JSONArray::~JSONArray() {
    delete _listOfDataObjects;
}

void JSONArray::parseJSONArray(Tokenizer *tokenizer)
{
    Token token = tokenizer->getToken();
    if( ! token.isOpenSquareBracket() ){
 		std::cout << "The input stream did not begin with a open square bracket " << std::endl;
 		std::cout << "and therefore is not valid. " << std::endl;
 		 exit(2);
 	}
 	do {
        JSONDataObject *dItem = jsonObjectNode();
        dItem->parseDataObject(tokenizer);
        _listOfDataObjects->push_back(dItem);
        token = tokenizer->getToken();
        if( ! token.isCloseSquareBracket() && ! token.isComma() ) {
 		    std::cout << "The input stream did not end with a closed square bracket or a " << std::endl;
 		    std::cout << "comma and therefore is not valid. " << std::endl;
 		    exit(2);
 	    }
     } while( ! token.isCloseSquareBracket() );
}

int JSONArray::numJSONObjects(){
	return  _listOfDataObjects->size();
}












