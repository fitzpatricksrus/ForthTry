//
//  InputIterator.hpp
//  YAF
//
//  Created by Dad on 2/3/18.
//  Copyright © 2018 Dad. All rights reserved.
//

#ifndef InputIterator_hpp
#define InputIterator_hpp

#include <string>

class InputIterator {
public:
	enum CharType { LETTER, NUMERAL, SYMBOL, DASH, LEFTPAREN, RIGHTPAREN, COLON, LEFTBRACKET, RIGHTBRACKET, SEPERATOR, END };

	InputIterator(std::string text);
	virtual ~InputIterator();
	
	CharType peekType();
	char peekChar();
	void nextChar();
	
private:
	std::string input;
	int inputPos;
};

#endif /* InputIterator_hpp */
