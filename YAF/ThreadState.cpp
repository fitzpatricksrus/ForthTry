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
	// build the root word consisting of the word passed in and an exit command.
	rootWord[0] = startingWord;
	rootWord[1] = &CompositeWord::EXIT_WORD;
	// since the root word is a CompositeWord, it will set the ip to it's
	// recipe, that we built above, and it will also push a null ip onto the
	// return stack which will also cleanly cause the thread to exit (via
	// returning null from its run() method.
	rootWord.execute(this);
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

void ThreadState::pushReturn(WordRecipe newIp) {
	returnStack.push(ip);
	ip = newIp;
}

void ThreadState::popReturn() {
	ip = returnStack.pop();
}

void ThreadState::push(StackElement ptr){
	dataStack.push(ptr);
}

StackElement ThreadState::pop() {
	return dataStack.pop();
}

