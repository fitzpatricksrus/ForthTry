//
//  ThreadState.cpp
//  YAF
//
//  Created by Dad on 1/10/18.
//  Copyright © 2018 Dad. All rights reserved.
//

#include "ThreadState.hpp"

#include <string.h>
#include <iostream>

ThreadState::ThreadState(int dspSize, int rspSize, WordReference startingWord)
: ip(nullptr), returnStack(rspSize), rootWord(2), traceEnabled(false), traceName(startingWord->getTraceName())
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

static const char* SPACES = "............................................................................";
static inline size_t min(size_t x,size_t y) {
	if (x < y) {
		return x;
	} else {
		return y;
	}
}

bool ThreadState::run() {
	if (traceEnabled) {
		WordReference currentWord = (*ip);
		ip++;
		std::cout << traceName;
		std::cout << SPACES + strlen(SPACES) - 10 + min(10, strlen(traceName));
		std::cout << ip;
		std::cout << (SPACES + strlen(SPACES) - returnStack.depth());
		std::cout << currentWord->getTraceName();
		std::cout << "\n";
		currentWord->execute(this);
		return ip;
	} else {
		WordReference currentWord = (*ip);
		ip++;
		currentWord->execute(this);
		return ip;
	}
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

void ThreadState::setTrace(bool on) {
	traceEnabled = on;
}

class ChangeTraceValue : public Word {
public:
	ChangeTraceValue(bool on);
	virtual void execute(ThreadState* state);
	virtual const char* getTraceName();
private:
	bool turnTraceOn;
};

ChangeTraceValue::ChangeTraceValue(bool on)
: Word(), turnTraceOn(on)
{
}

void ChangeTraceValue::execute(ThreadState *state) {
	state->setTrace(turnTraceOn);
}

const char* ChangeTraceValue::getTraceName() {
	if (turnTraceOn) {
		return "TRACE ON";
	} else {
		return "TRACE OFF";
	}
}

static ChangeTraceValue traceOn(true);
Word& ThreadState::TRACE_ON_WORD = traceOn;

static ChangeTraceValue traceOff(false);
Word& ThreadState::TRACE_OFF_WORD = traceOff;

class TerminateThreadWord : public Word {
public:
	virtual void execute(ThreadState* state);
	virtual const char* getTraceName();
};

void TerminateThreadWord::execute(ThreadState *state) {
	state->terminate();
}

const char* TerminateThreadWord::getTraceName() {
	return "TERMINATE THREAD";
}

static TerminateThreadWord terminateThread;
Word& ThreadState::TERMINATE_THREAD_WORD = terminateThread;
