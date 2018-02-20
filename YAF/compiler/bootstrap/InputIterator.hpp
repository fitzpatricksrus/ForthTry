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
	enum CharType {
		END_OF_INPUT = 0x0000,
		LETTER = 0x0001,
		NUMERAL = 0x0002,
		SYMBOL = 0x0004,
		DASH = 0x0008,
		LEFTPAREN = 0x0010,
		RIGHTPAREN = 0x0020,
		COLON = 0x0040,
		LEFTBRACKET = 0x0080,
		RIGHTBRACKET = 0x0100,
		SEPERATOR = 0x0200,
        TERMINATOR = 0x0400
	};

	InputIterator(std::string text);
	~InputIterator();
	
	CharType peekType();
	char peekChar();
	char nextChar();
	
private:
	std::string input;
	int inputPos;
};

#endif /* InputIterator_hpp */
