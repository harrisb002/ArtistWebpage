//
// Created by Ben Harris on 4/20/23.
//

#include <string>
#include "../Tokenizer.h"

#ifndef PROJECT4_KEYVALUEPAIR_HPP
#define PROJECT4_KEYVALUEPAIR_HPP

class KeyValuePair {
public:
    KeyValuePair();

    std::string attributeName() { return _attributeName; }
    std::string stringValue() { return _attributeStringValue; }
    int numberValue() { return _attributeNumberValue; }
    bool isNumber() { return _isNumber; }  // is the datatype of the value of this entity integer?

    void parsePair(Tokenizer *tokenizer);

    void print();

private:
    std::string _attributeName;
    std::string _attributeStringValue;
    int _attributeNumberValue;
    bool _isNumber;
};
#endif //PROJECT4_KEYVALUEPAIR_HPP
