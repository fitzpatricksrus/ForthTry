//
//  ThreadState.hpp
//  YAF
//
//  Created by Dad on 1/10/18.
//  Copyright © 2018 Dad. All rights reserved.
//

#ifndef ThreadState_hpp
#define ThreadState_hpp

#include "Word.hpp"
#include "Stack.hpp"

/**
 * All the state needed for the inner interpreter and core primatives to execute a program other than the
 * system memory.
 */
class ThreadState {
public:
	ThreadState* nextThread;		//linked, circular list of threads.
	WordRecipe ip;          		//pointer to next word reference to execute
	WordReference currentWord;		//word being 'execute()'ed
	StackStructure returnStack;     //return stack
	StackStructure dataStack;       //data stack

	ThreadState(int dataStackSize, int returnStackSize, WordReference startingWord);
	virtual ~ThreadState();
	
	virtual void next();
};

#endif /* ThreadState_hpp */
