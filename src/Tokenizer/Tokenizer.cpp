//
// Created by Ben Harris on 4/20/23.
//

#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include "Tokenizer.h"

Tokenizer::Tokenizer(std::string name) :    inputFileName{name},
											isToken(false) {
                                             // open the input file. We will make sure that it is open in getToken.
                                            inputStream.open(inputFileName, std::ios::in); }
                                            

bool Tokenizer::charOfInterest(char c) {
    // Returns true if token found, false otherwise.
    return ((c == '{') || (c == '}') || (c == '[') || (c == ']') || (c == ',') 
    		|| (c == ':') || (c == '"'));
}

bool Tokenizer::isParenthesis(){
    return inputStream.peek() == '"';
}

bool Tokenizer::isNumber() {
    char c;
    while(isspace(inputStream.peek())){
        inputStream.get(c);
    }
    return isdigit(inputStream.peek());
}

std::string Tokenizer::stringValue(){
	std::string tempStr = "";
    char c;
    do{
        inputStream.get(c);
        tempStr += c;
        if(c == '\\' && inputStream.peek() == '"'){  // Inject \"
        	inputStream.get(c);
        	tempStr += c;
        }
    } while(inputStream.peek() != '"');
    return tempStr;
}  

int Tokenizer::getIntValue(){
	int tempInt;
    inputStream >> tempInt;
    return tempInt;
}  

Token Tokenizer::getToken() {

    char c;  // Used to hold each char read from inputStream

    if( ! inputStream.is_open()) {
        std::cout << "Tokenizer::getToken() called with a stream that is not open." << std::endl;
        std::cout << "Make sure that " << inputFileName << " exists and is readable. Terminating.";
        exit(2);
    }

    while( inputStream.get(c) && ! charOfInterest(c) ) {
        // Skip chars until a character of interest is found
        // and when this happens break out of loop.
        
        // If escape char found then skip next char i:e "
        if(c == '\\'){
			inputStream.get(c);
        }
    }

    // The above loop stops because one of its conditions is false. That means
    // either function get failed, which happens at the end of the file, or
    // c, the character that get read, is a character of interest. The other
    // possibility is if the input file was not open or the input somehow got clobbered.

    // Use Token Constructor 
    Token token;

    if( inputStream.eof() ) {
        token.endOfFile() = true;
        return token;
    }

    // Now, we go through a sequence of if ... else if statements
    // to identify the token whose first character we have just read. This is
    // the character that caused the while loop to terminate.

    if( c == '[' ) { 
    	token.isOpenSquareBracket() = true;
    	return token;	
    }else if(c == ']'){
    	token.isCloseSquareBracket() = true;
    	return token;	
    }else if(c == '{'){
        token.isOpenCurlyBrace() = true;
    	return token;	 
    }else if(c == '}'){
        token.isCloseCurlyBrace() = true;
    	return token;	
    }else if(c == ':'){
        token.isColon() = true;
    	return token;	
    }else if(c == ','){
        token.isComma() = true;
    	return token;	
    }else if(c == '"'){
        token.isQuote() = true;
    	return token;	
    }
    else {
        // The condition of one of the above "if ... else if" statements should
        // evaluate to true because function charOfInterest return true when it
        // finds a character that is the start of some token and that the
        // "if ... else if" has one case for each character that starts a token.
        // Therefore, the control should never get here. However, it is always
        // a good idea to have an "else" when you have a sequence of "if ... else if"
        // statements so that you do not end up with a case that has not been handled.
        // For example, you forgot to account for one of the cases.
        std::cout << "There is a logic error in function Tokenizer::getToken.\n";
        std::cout << "The function doesn't know how to process this character: ->" << c << "<-\n";
        exit(1);
    }
    
    return token; // The control SHOULD NOT reach this statement.
}