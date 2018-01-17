//
//  ExitSystemWord.hpp
//  YAF
//
//  Created by Dad on 1/10/18.
//  Copyright © 2018 Dad. All rights reserved.
//

#ifndef ExitSystemWord_hpp
#define ExitSystemWord_hpp

#include <stdio.h>

#include "Word.hpp"

class ThreadState;

class ExitSystemWord : public Word {
public:
	int code;
	
	ExitSystemWord(int code);
	virtual ~ExitSystemWord();
	virtual void execute(ThreadState* state);
	virtual std::string getTraceName();
};

#endif /* ExitSystemWord_hpp */
