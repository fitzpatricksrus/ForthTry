//
//  Stack.cpp
//  YAF
//
//  Created by Dad on 1/10/18.
//  Copyright © 2018 Dad. All rights reserved.
//

#include "Stack.hpp"

/**
 * Runtime stack structure.
 */
StackStructure::StackStructure(int stackSizeIn) {
	stackSize = stackSizeIn;
	stackData = new StackElement[stackSizeIn];
	stackPos = 0;
}

StackStructure::~StackStructure() {
	delete[] stackData;
}

void StackStructure::push(StackElement ptr) {
	if (stackPos < stackSize) {
		stackData[stackPos] = ptr;
		stackPos++;
	} else {
		// TODO: Handle stack overflow
	}
}

bool StackStructure::stackIsEmpty() {
	return stackPos == 0;
}

bool StackStructure::stackNotEmpty() {
	return stackPos != 0;
}

void StackStructure::clear() {
	stackPos = 0;
}

StackElement StackStructure::pop() {
	if (stackPos > 0) {
		stackPos--;
		return stackData[stackPos];
	} else {
		// TODO: Handle stack underflow
		return StackElement();
	}
}

