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
	ThreadState(int dataStackSize, int returnStackSize, WordReference startingWord);
	~ThreadState();
	
	bool run();
	void terminate();
	
	void pushReturn(WordRecipe newIp);
	void popReturn();
	
	void push(StackElement ptr);
	StackElement pop();

private:
	StackStructure returnStack;     //return stack
	StackStructure dataStack;       //data stack
	WordRecipe ip;          		//pointer to next word reference to execute
	CompositeWord rootWord;			//word being 'execute()'ed
};

#endif /* ThreadState_hpp */
