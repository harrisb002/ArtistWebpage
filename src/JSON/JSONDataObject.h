//
// Created by Ben Harris on 4/20/23.
//
#include "../Tokenizer/Data/KeyValuePair.h"
#include <vector>

#ifndef PROJECT4_JSONDATAOBJECT_HPP
#define PROJECT4_JSONDATAOBJECT_HPP

class JSONDataObject {
public:
    JSONDataObject();
    virtual ~JSONDataObject();
    
    void parseDataObject( Tokenizer *tokenizer );
    
    std::vector<KeyValuePair *> *listOfDataItems() { return _listOfDataItems; }
    std::string valueForStringAttribute( std::string key );
    int valueForIntegerAttribute( std::string key );

private:
    std::vector<KeyValuePair *> *_listOfDataItems;
};

#endif //PROJECT4_JSONDATAOBJECT_HPP
