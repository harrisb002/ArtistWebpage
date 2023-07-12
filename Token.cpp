//
// Created by Ben Harris on 4/20/23.
//
#include <iostream>
#include "Token.h"

Token::Token(): _isOpenSquareBracket{false},
                _isCloseSquareBracket{false},
                _isOpenCurlyBrace{false}, 
                _isCloseCurlyBrace{false},
                _isColon {false}, 
                _isComma {false},
                _isQuote {false},
                _eof{false} {}

bool &Token::isOpenSquareBracket() { return _isOpenSquareBracket; }
bool &Token::isCloseSquareBracket() { return _isCloseSquareBracket; }

bool &Token::isOpenCurlyBrace() { return _isOpenCurlyBrace; }
bool &Token::isCloseCurlyBrace() { return _isCloseCurlyBrace; }

bool &Token::isColon() { return _isColon; }
bool &Token::isComma() { return _isComma; }
bool &Token::isQuote() { return _isQuote; }

bool &Token::endOfFile() { return _eof; }

void Token::print() {
    // You should have one condition for each of the token types that you
    // this class can hold.
    if(_isOpenSquareBracket) {
        std::cout << "The Token is a [ " << std::endl;
    }else if(_isCloseSquareBracket) {
        std::cout << "The Token is a ] " << std::endl;
    }else if(_isOpenCurlyBrace) {
        std::cout << "The Token is a { " << std::endl;
    }else if(_isCloseCurlyBrace) {
        std::cout << "The Token is a } " << std::endl;
    }else if(_isColon) {
        std::cout << "The Token is a : " << std::endl;
    }else if(_isComma) {
        std::cout << "The Token is a , " << std::endl;
    }else if(_isQuote) {
        std::cout << "The Token is a \" " << std::endl;
    }else{
        std::cout << "Token::print -- unknown token.\n" << std::endl;
        exit(3);
    }

}
