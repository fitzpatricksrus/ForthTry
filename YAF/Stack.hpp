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
	char charData[4];
	int intData;
	WordReference wordData;
	WordRecipe recipeData;
	
	StackElement() {
		wordData = nullptr;
	}
	StackElement(char c0) {
		charData[0] = c0;
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
		return charData[0];
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
	int stackSize;
	int stackPos;
	StackElement* stackData;
	
	StackStructure(int stackSizeIn);
	~StackStructure();
	void push(StackElement ptr);
	bool stackIsEmpty();
	bool stackNotEmpty();
	StackElement pop();
};

#endif /* Stack_hpp */
