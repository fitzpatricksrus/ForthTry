//
//  CompositeWord.cpp
//  YAF
//
//  Created by Dad on 1/10/18.
//  Copyright © 2018 Dad. All rights reserved.
//

#include "CompositeWord.hpp"
#include "ThreadState.hpp"


/**
 * Data used by the inner interpreter and base primatives.
 */
CompositeWord::CompositeWord(int size)
: Word(), ownsRecipe(true) {
	recipe = new WordReference[size];
}

CompositeWord::CompositeWord(WordRecipe recipeIn)
: Word(), recipe(recipeIn), ownsRecipe(false) {
}

CompositeWord::CompositeWord(WordRecipe recipeIn, int size)
: Word(), ownsRecipe(true) {
	recipe = new WordReference[size];
	for (int i = 0; i < size; i++) {
		recipe[i] = recipeIn[i];
	}
}

CompositeWord::~CompositeWord() {
	if (ownsRecipe) {
		delete[] recipe;
	}
}

void CompositeWord::execute (ThreadState* state) {
	state->returnStack.push(state->ip);
	state->ip = recipe;
}

class ExitWord : public Word {
public:
	virtual ~ExitWord();
	virtual void execute (ThreadState* state);
};

ExitWord::~ExitWord() {
}

void ExitWord::execute (ThreadState* state) {
	state->ip = state->returnStack.pop();
}

static ExitWord EXIT_WORD_INSTANCE;
Word& CompositeWord::EXIT_WORD = EXIT_WORD_INSTANCE;

