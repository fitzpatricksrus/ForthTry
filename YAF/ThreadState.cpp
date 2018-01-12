//
//  ThreadState.cpp
//  YAF
//
//  Created by Dad on 1/10/18.
//  Copyright © 2018 Dad. All rights reserved.
//

#include "ThreadState.hpp"

ThreadState::ThreadState(int dspSize, int rspSize, WordReference startingWord)
: ip(nullptr), dataStack(dspSize), returnStack(rspSize), rootWord(2)
{
	// Slightly hacky way to bootstrap by using the thread's own internal state to
	// represent a composite word.  If the starting work ever returns/exit, things
	// will restart again.
	rootWord.recipe[0] = startingWord;
	rootWord.recipe[1] = &CompositeWord::EXIT_WORD;
	ip = rootWord.recipe;
}

ThreadState::~ThreadState() {
}

bool ThreadState::run() {
	WordReference currentWord = (*ip);
	ip++;
	currentWord->execute(this);
	return ip;
}

void ThreadState::terminate() {
	ip = 0;
}
