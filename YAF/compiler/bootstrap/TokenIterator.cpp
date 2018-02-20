//
//  TokenIterator.cpp
//  YAF
//
//  Created by Dad on 2/3/18.
//  Copyright © 2018 Dad. All rights reserved.
//

#include "TokenIterator.hpp"

using std::string;

TokenIterator::TokenIterator(string text)
: tokenType(END_OF_INPUT), tokenText(""), inputIter(text)
{
	nextToken();
}

TokenIterator::~TokenIterator() {
}

TokenIterator::TokenType TokenIterator::getTokenType() {
	return tokenType;
}

std::string TokenIterator::getTokenString() {
	return tokenText;
}


/*
enum CharType { END_OF_INPUT, NUMBER, OPERATOR, IDENTIFIER, KEYWORD, LEFTPAREN, RIGHTPAREN, LEFTBRACKET, RIGHTBRACKET, TERMINATOR  };
enum TokenType { NUMBER, OPERATOR, IDENTIFIER, KEYWORD, LEFTPAREN, RIGHTPAREN, LEFTBRACKET, RIGHTBRACKET, TERMINATOR, END_OF_INPUT };

LETTER = 'a'..'z' | 'A'..'Z'
NUMERAL = '0'..'9'
SYMBOL =

numberBody = NUMERAL [ numberBody ]
number = [ '-' ] numberBody
operatorBody =  SYMBOL [ '-' | operatorBody ]
operator = SYMBOL operatorBody
identifierBody = LETTER | NUMERAL '(' | ')' [ identifierBody ]
identifier = LETTER [ identifierBody ]
keyword = identifier ':'

*/

static void skipSpaces(InputIterator& inputIter) {
	while (inputIter.peekType() == InputIterator::SEPERATOR) {
		inputIter.nextChar();
	}
}

// enum CharType { END_OF_INPUT, LETTER, NUMERAL, SYMBOL, DASH, LEFTPAREN, RIGHTPAREN, COLON, LEFTBRACKET, RIGHTBRACKET, SEPERATOR  };
static string parseToken(InputIterator& inputIter, int inputMask) {
	string result;
	InputIterator::CharType t = inputIter.peekType();
	while (t & inputMask) {
		result += inputIter.nextChar();
		t = inputIter.peekType();
	}
	return result;
}

static string parseIdentifier(InputIterator& inputIter) {
	// letter, numeral, leftparen, rightparen
	static int inputMask = InputIterator::LETTER | InputIterator::NUMERAL | InputIterator::COLON;
	return parseToken(inputIter, inputMask);
}

static string parseNumber(InputIterator& inputIter) {
	string result;
	result = inputIter.nextChar();	//maybe suck up leading '-'
	return result + parseToken(inputIter, InputIterator::NUMERAL);
}

static string parseOperator(InputIterator& inputIter) {
	return parseToken(inputIter, InputIterator::SYMBOL);
}

void TokenIterator::nextToken() {
	// number: '-', 0..9
	// operator: symbol
	// identifier: letter
	// keyword: letter
	// ()[]
	
	skipSpaces(inputIter);
	switch (inputIter.peekType()) {
	case InputIterator::LETTER:
		tokenText = parseIdentifier(inputIter);
		if (tokenText.back() == ':') {
			tokenType = KEYWORD;
		} else {
			tokenType = IDENTIFIER;
		}
		break;
	case InputIterator::DASH:
		tokenText = "-";
		inputIter.nextChar();
		if (inputIter.peekType() == InputIterator::NUMERAL) {
			tokenText += parseNumber(inputIter);
			tokenType = NUMBER;
		} else {
			tokenText += parseOperator(inputIter);
			tokenType = OPERATOR;
		}
		break;
	case InputIterator::NUMERAL:
		tokenText = parseNumber(inputIter);
		tokenType = NUMBER;
		break;
	case InputIterator::COLON:
	case InputIterator::SYMBOL:
		tokenText = parseOperator(inputIter);
		tokenType = OPERATOR;
		break;
	case InputIterator::LEFTPAREN:
		tokenText = inputIter.nextChar();
		tokenType = LEFTPAREN;
		break;
	case InputIterator::RIGHTPAREN:
		tokenText = inputIter.nextChar();
		tokenType = RIGHTPAREN;
		break;
	case InputIterator::LEFTBRACKET:
		tokenText = inputIter.nextChar();
		tokenType = LEFTBRACKET;
		break;
	case InputIterator::RIGHTBRACKET:
		tokenText = inputIter.nextChar();
		tokenType = RIGHTBRACKET;
		break;
    case InputIterator::TERMINATOR:
        tokenText = inputIter.nextChar();
        tokenType = TERMINATOR;
        break;
	case InputIterator::END_OF_INPUT:
	case InputIterator::SEPERATOR:
	default:
		// should never happen unless we missed a case above.
		tokenText = "";
		tokenType = END_OF_INPUT;
	}
}










