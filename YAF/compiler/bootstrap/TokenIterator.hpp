//
//  TokenIterator.hpp
//  YAF
//
//  Created by Dad on 2/3/18.
//  Copyright © 2018 Dad. All rights reserved.
//

#ifndef TokenIterator_hpp
#define TokenIterator_hpp

#include <string>
#include "InputIterator.hpp"

class TokenIterator {
public:
	enum TokenType { END_OF_INPUT, NUMBER, OPERATOR, IDENTIFIER, KEYWORD, LEFTPAREN, RIGHTPAREN, LEFTBRACKET, RIGHTBRACKET, TERMINATOR };

	TokenIterator(std::string text);
	~TokenIterator();
	
	TokenType getTokenType();
	std::string getTokenString();

	void nextToken();

private:
	InputIterator inputIter;
	TokenType tokenType;
	std::string tokenText;
};

#endif /* TokenIterator_hpp */
