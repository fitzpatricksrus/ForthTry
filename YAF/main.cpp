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

LoggingWord Hello("Hello");
LoggingWord World("World");
ExitSystemWord Done(0);
WordReference recipeBits[3] = {
	&Hello,
	&World,
	&Done
};

CompositeWord word(recipeBits);
ThreadState thread(10, 10, &word);

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
    std::cout << "Hello, World!\n";
    return 0;
}
