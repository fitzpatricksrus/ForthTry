//
//  CompositeWord.cpp
//  YAF
//
//  Created by Dad on 1/10/18.
//  Copyright © 2018 Dad. All rights reserved.
//

#include "CompositeWord.hpp"

/**
 * Data used by the inner interpreter and base primatives.
 */
CompositeWord::CompositeWord(int size)
: Word() {
	recipe = new WordReference[size];
}

CompositeWord::CompositeWord(WordRecipe recipeIn)
: Word(), recipe(recipeIn) {
}

CompositeWord::~CompositeWord() {
	delete[] recipe;
}

void CompositeWord::execute (ThreadState* state) {
	state->returnStack.push(state->ip);
	state->ip = recipe;
}

CompositeWord::ExitWord::~ExitWord() {
}

void CompositeWord::ExitWord::execute (ThreadState* state) {
	state->ip = state->returnStack.pop();
}

