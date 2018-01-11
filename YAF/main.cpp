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
	
	LoggingWord Hello("Hello ");
	LoggingWord World("World\n");
	ExitSystemWord Done(0);
	WordReference recipeBits[3] = {
		&Hello,
		&World,
		&Done
	};
	
	CompositeWord word(recipeBits);
	ThreadState thread(10, 10, &word);
	
	while (1) {
		thread.next();
	}
	return 0;
}
