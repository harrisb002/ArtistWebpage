//
// Created by Ben Harris on 4/20/23.
//

#ifndef PROJECT4_TOKEN_HPP
#define PROJECT4_TOKEN_HPP

class Token {
public:
	Token();
    bool &isOpenSquareBracket();
    bool &isCloseSquareBracket();

    bool &isOpenCurlyBrace();
    bool &isCloseCurlyBrace();
    
    bool &isColon();
    bool &isComma();
	bool &isQuote();

    bool &endOfFile();
    void print();


private:
    bool _isOpenSquareBracket, _isCloseSquareBracket, _isOpenCurlyBrace,
    	 _isCloseCurlyBrace, _isColon, _isComma, _isQuote, _eof;
};

#endif //PROJECT4_TOKEN_HPP
