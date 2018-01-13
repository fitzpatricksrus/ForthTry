//
//  LoggingWord.cpp
//  YAF
//
//  Created by Dad on 1/10/18.
//  Copyright © 2018 Dad. All rights reserved.
//

#include "LoggingWord.hpp"
#include <iostream>


LoggingWord::LoggingWord(const char* messageIn, const char* traceName)
: Word(), message(messageIn), name(traceName) {
	if (name == nullptr) {
		name = "LogginWord";
	}
}

LoggingWord::~LoggingWord() {
}

void LoggingWord::execute (ThreadState* state) {	
	std::cout << message;
}

const char* LoggingWord::getTraceName() {
	return name;
}

