//
//  LoggingWord.cpp
//  YAF
//
//  Created by Dad on 1/10/18.
//  Copyright © 2018 Dad. All rights reserved.
//

#include "LoggingWord.hpp"
#include <iostream>


LoggingWord::LoggingWord(const char* messageIn)
: Word(), message(messageIn) {
	
}

LoggingWord::~LoggingWord() {
}

void LoggingWord::execute (ThreadState* state) {	
	std::cout << message;
}