//
//  LoggingWord.cpp
//  YAF
//
//  Created by Dad on 1/10/18.
//  Copyright © 2018 Dad. All rights reserved.
//

#include "LoggingWord.hpp"
#include <iostream>


LoggingWord::LoggingWord(std::string messageIn, std::string traceName)
: Word(), message(messageIn), name(traceName) {
	if (name.empty()) {
		name = "LogginWord";
	}
}

LoggingWord::~LoggingWord() {
}

void LoggingWord::execute (ThreadState* state) {	
	std::cout << message;
}

std::string LoggingWord::getTraceName() {
	return name;
}

