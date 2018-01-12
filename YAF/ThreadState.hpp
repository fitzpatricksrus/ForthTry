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
#include "CompositeWord.hpp"

/**
 * All the state needed for the inner interpreter and core primatives to execute a program other than the
 * system memory.
 */
class ThreadState {
public:
	StackStructure returnStack;     //return stack
	StackStructure dataStack;       //data stack
	WordRecipe ip;          		//pointer to next word reference to execute
	CompositeWord rootWord;			//word being 'execute()'ed

	ThreadState(int dataStackSize, int returnStackSize, WordReference startingWord);
	~ThreadState();
	
	bool run();
	void terminate();
};

#endif /* ThreadState_hpp */
