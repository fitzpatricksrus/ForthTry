//
//  ThreadState.cpp
//  YAF
//
//  Created by Dad on 1/10/18.
//  Copyright © 2018 Dad. All rights reserved.
//

#include "ThreadState.hpp"

ThreadState::ThreadState(int dspSize, int rspSize, WordReference startingWord)
: nextThread(this), ip(nullptr), dataStack(dspSize), returnStack(rspSize)
{
	nextThread = this;
	// Slightly hacky way to bootstrap by using the thread's own internal state to
	// represent a composite word.  If the starting work ever returns/exit, things
	// will restart again.
	ip = &currentWord;
	currentWord = startingWord;
}

ThreadState::~ThreadState() {
	
}

void ThreadState::next() {
	currentWord = (*ip);
	ip++;
	currentWord->execute(this);
}

