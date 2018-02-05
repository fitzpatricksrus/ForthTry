//
//  BootParser.hpp
//  YAF
//
//  Created by Dad on 1/30/18.
//  Copyright © 2018 Dad. All rights reserved.
//

#ifndef BootParser_hpp
#define BootParser_hpp

#include <string>

using std::string;

class BootParser {
public:
	enum CharType { LETTER, NUMERAL, SYMBOL, DASH, UNDERSCORE, LEFTPAREN, RIGHTPAREN, COLON };
	enum TokenType { NUMBER, OPERATOR, IDENTIFIER, KEYWORD };

	BootParser(string text);
	virtual ~BootParser();
	
	bool acceptNumberBody();
	bool number();
	bool acceptOperatorBody();
	bool acceptOperator();
	bool acceptIdentifierBody();
	bool acceptIdentifier();
	bool acceptKeyword();

	bool nextToken();
	TokenType getTokenType();
	string getTokenString();
	
private:
	void skipWhitespace();
	
	string input;
	int inputPosition;
	
};

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

#endif /* BootParser_hpp */


