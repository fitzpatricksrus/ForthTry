//
//  TokenIteratorTest.cpp
//  YAF
//
//  Created by Dad on 2/4/18.
//  Copyright © 2018 Dad. All rights reserved.
//

#include "TokenIteratorTest.hpp"

#include <iostream>
#include <string>

#include "TokenIterator.hpp"

using std::string;

static string typeNames[] = {
	"END_OF_INPUT",
	"NUMBER",
	"OPERATOR",
	"IDENTIFIER",
	"KEYWORD",
	"LEFTPAREN",
	"RIGHTPAREN",
	"LEFTBRACKET",
	"RIGHTBRACKET",
    "TERMINATOR"
};

void TokenIteratorTest::doTest() {
    string input = "   value+=(123+other+Value)toPower:-20- 3 natural:log[kdj23];\n\tthisIsATest foreverDo: [bob; blob]   ";
	
	TokenIterator iter(input);
	
	while (iter.getTokenType() != TokenIterator::END_OF_INPUT) {
		std::cout << "type: " << typeNames[iter.getTokenType()] << "  text: " << iter.getTokenString() << "\n";
		iter.nextToken();
	}
}
