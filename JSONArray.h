//
// Created by Ben Harris on 4/20/23.
//
#include "JSONDataObject.h"
#include <vector>

#ifndef PROJECT4_JSONARRAY_HPP
#define PROJECT4_JSONARRAY_HPP

class JSONArray {
public:
    JSONArray();
    ~JSONArray();
    std::vector<JSONDataObject *> *listOfDataObjects() { return _listOfDataObjects; }
    virtual JSONDataObject *jsonObjectNode() = 0;
    void parseJSONArray(Tokenizer *tokenizer);
    int numJSONObjects();

protected:
    std::vector<JSONDataObject *> *_listOfDataObjects;
    
};

#endif //PROJECT4_JSONARRAY_HPP