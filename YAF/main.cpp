//
//  main.cpp
//  YAF
//
//  Created by Dad on 1/4/18.
//  Copyright © 2018 Dad. All rights reserved.
//

#include <iostream>
#include "ThreadState.hpp"
#include "LoggingWord.hpp"
#include "ExitSystemWord.hpp"
#include "CompositeWord.hpp"

typedef struct SystemState {
	ThreadState* currentThread;
	void* memory;
	
	SystemState(ThreadState* state)
	: currentThread(state), memory(nullptr)
	{
		
	}
	void next() {
		currentThread->next();
		currentThread = currentThread->nextThread;
	}
} SystemState;


int main(int argc, const char * argv[]) {
    // insert code here...
	
	LoggingWord Hello_H("H");
	LoggingWord Hello_E("e");
	LoggingWord Hello_L("l");
	LoggingWord Hello_O("o");
	LoggingWord Hello_BANG("!");
	LoggingWord Hello_SPACE(" ");
	LoggingWord World("World!\n");
	ExitSystemWord Done(0);
	WordReference BangBits[] = {
		&Hello_BANG,
		&Hello_BANG,
		&Hello_BANG,
		&Hello_BANG,
		&CompositeWord::EXIT_WORD
	};
	CompositeWord BangBangBang(BangBits);
	WordReference HelloBits[] = {
		&Hello_H,
		&Hello_E,
		&Hello_L,
		&Hello_L,
		&Hello_O,
		&BangBangBang,
		&Hello_SPACE,
		&CompositeWord::EXIT_WORD
	};
	CompositeWord Hello(HelloBits);
	WordReference recipeBits[] = {
		&Hello,
		&World,
		&CompositeWord::EXIT_WORD
	};
	CompositeWord word(recipeBits);
	ThreadState thread(10, 10, &word);
	
	while (thread.next()) {	}
	return 0;
}
