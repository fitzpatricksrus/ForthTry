//
//  CompositeWord.cpp
//  YAF
//
//  Created by Dad on 1/10/18.
//  Copyright © 2018 Dad. All rights reserved.
//

#include "CompositeWord.hpp"
#include "ThreadState.hpp"
#include <string.h>

static const char* cloneString(const char* str) {
	if (str == nullptr) {
		str = "CompositeWord";
	}
	char* s = new char[strlen(str)+1];
	strcpy(s, str);
	return s;
}

/**
 * Data used by the inner interpreter and base primatives.
 */
CompositeWord::CompositeWord(int size, const char* name)
: Word(), ownsRecipe(true) {
	recipe = new WordReference[size];
	traceName = cloneString(name);
}

CompositeWord::CompositeWord(WordRecipe recipeIn, const char* name)
: Word(), recipe(recipeIn), ownsRecipe(false), traceName(name) {
	if (traceName == NULL) {
		traceName = "CompositeWord";
	}
}

CompositeWord::CompositeWord(WordRecipe recipeIn, int size, const char* name)
: Word(), ownsRecipe(true) {
	recipe = new WordReference[size];
	for (int i = 0; i < size; i++) {
		recipe[i] = recipeIn[i];
	}
	traceName = cloneString(name);
}

CompositeWord::~CompositeWord() {
	if (ownsRecipe) {
		delete[] recipe;
		delete[] traceName;
	}
}

WordReference& CompositeWord::operator[](int ndx) {
	return recipe[ndx];
}

void CompositeWord::execute (ThreadState* state) {
	state->pushReturn(recipe);
}

const char* CompositeWord::getTraceName() {
	return traceName;
}

class ExitWord : public Word {
public:
	virtual ~ExitWord();
	virtual void execute (ThreadState* state);
	virtual const char* getTraceName();
};

ExitWord::~ExitWord() {
}

void ExitWord::execute (ThreadState* state) {
	state->popReturn();
}

const char* ExitWord::getTraceName() {
	return "ExitWord";
}

static ExitWord EXIT_WORD_INSTANCE;
Word& CompositeWord::EXIT_WORD = EXIT_WORD_INSTANCE;

