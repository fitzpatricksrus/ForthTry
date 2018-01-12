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
	rootWord[0] = startingWord;
	rootWord[1] = &CompositeWord::EXIT_WORD;
	//this is a bit of a hack to have the rootWord set it's recipe in the IP.
	//a side effect is that a bogus IP gets pushed onto the return
	//stack.  We pop that off so that it's clean when the thread starts.
	rootWord.execute(this);
	returnStack.clear();
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

