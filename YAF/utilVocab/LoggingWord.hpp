//
//  LoggingWord.hpp
//  YAF
//
//  Created by Dad on 1/10/18.
//  Copyright © 2018 Dad. All rights reserved.
//

#ifndef LoggingWord_hpp
#define LoggingWord_hpp

#include <stdio.h>

#include "Word.hpp"
#include "ThreadState.hpp"

/**
 * Data used by the inner interpreter and base primatives.
 */
class LoggingWord : public Word {
public:
	const char* message;
	const char* name;

	LoggingWord(const char* message, const char* traceName = nullptr);
	virtual ~LoggingWord();
	virtual void execute(ThreadState* state);
	virtual const char* getTraceName();
};

#endif /* LoggingWord_hpp */
