//
//  Stack.hpp
//  YAF
//
//  Created by Dad on 1/10/18.
//  Copyright © 2018 Dad. All rights reserved.
//

#ifndef Stack_hpp
#define Stack_hpp

#include <stdio.h>

#include "Word.hpp"

class StackElement {
public:
	char charData;
	int intData;
	WordReference wordData;
	WordRecipe recipeData;
	
	StackElement() {
		charData = 0;
		intData = 0;
		wordData = 0;
		recipeData = 0;
	}
	StackElement(char c0) {
		charData = c0;
	}
	StackElement(int i) {
		intData = i;
	}
	StackElement(WordReference p) {
		wordData = p;
	}
	StackElement(WordRecipe p) {
		recipeData = p;
	}
	operator char() {
		return charData;
	}
	operator int() {
		return intData;
	}
	operator WordReference() {
		return wordData;
	}
	operator WordRecipe() {
		return recipeData;
	}
};

/**
 * Runtime stack structure.
 */
class StackStructure {
public:
	StackStructure(int stackSizeIn);
	~StackStructure();
	void push(StackElement ptr);
	StackElement pop();
	int depth();
	bool stackIsEmpty();
	bool stackNotEmpty();
	void clear();

private:
	int stackSize;
	int stackPos;
	StackElement* stackData;
};

#endif /* Stack_hpp */
