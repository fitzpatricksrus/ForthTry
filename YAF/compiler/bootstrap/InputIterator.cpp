//
//  InputIterator.cpp
//  YAF
//
//  Created by Dad on 2/3/18.
//  Copyright © 2018 Dad. All rights reserved.
//

#include "InputIterator.hpp"

using std::string;

// 	enum CharType { LETTER, NUMERAL, SYMBOL, DASH, LEFTPAREN, RIGHTPAREN, COLON, SEPERATOR, END };
/*

LETTER = 'a'..'z' | 'A'..'Z'
NUMERAL = '0'..'9'
SYMBOL =

numberBody = NUMERAL [ numberBody ]
number = [ '-' ] numberBody
operatorBody =  SYMBOL [ '-' | operatorBody ]
operator = SYMBOL operatorBody
identifierBody = LETTER | '(' | ')' [ identifierBody ]
identifier = LETTER [ identifierBody ]
keyword = identifier ':'

*/

InputIterator::InputIterator(string text)
: input(text), inputPos(0)
{
}

InputIterator::~InputIterator() {
}

InputIterator::CharType InputIterator::peekType() {
	if (inputPos >= input.length()) {
		return END_OF_INPUT;
	} else {
		char c = input[inputPos];
		if (c <= ' ') {
			return SEPERATOR;
		} else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
			return LETTER;
		} else if (c >= '0' && c <= '9') {
			return NUMERAL;
		} else {
			switch (c) {
			case ':':
				return COLON;
			case ')':
				return RIGHTPAREN;
			case '(':
				return LEFTPAREN;
			case ']':
				return RIGHTBRACKET;
			case '[':
				return LEFTBRACKET;
            case '-':
                return DASH;
            case ';':
                return TERMINATOR;
			default:
				return SYMBOL;
			}
		}
	}
}

char InputIterator::peekChar() {
	return input[inputPos];
}

char InputIterator::nextChar() {
	if (inputPos < input.length()) {
		char result = input[inputPos];
		inputPos++;
		return result;
	} else {
		return (char)0;
	}
}
