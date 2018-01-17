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

static std::string cloneString(std::string str) {
	if (str.empty()) {
		str = "CompositeWord";
	}
	return str;
}

/**
 * Data used by the inner interpreter and base primatives.
 */
CompositeWord::CompositeWord(int size, std::string name)
: Word(), ownsRecipe(true) {
	recipe = new WordReference[size];
	traceName = cloneString(name);
}

CompositeWord::CompositeWord(WordRecipe recipeIn, std::string name)
: Word(), recipe(recipeIn), ownsRecipe(false), traceName(name) {
	if (traceName.empty()) {
		traceName = "CompositeWord";
	}
}

CompositeWord::CompositeWord(WordRecipe recipeIn, int size, std::string name)
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
	}
}

WordReference& CompositeWord::operator[](int ndx) {
	return recipe[ndx];
}

void CompositeWord::execute (ThreadState* state) {
	state->pushReturn(recipe);
}

std::string CompositeWord::getTraceName() {
	return traceName;
}

class ExitWord : public Word {
public:
	virtual ~ExitWord();
	virtual void execute (ThreadState* state);
	virtual std::string getTraceName();
};

ExitWord::~ExitWord() {
}

void ExitWord::execute (ThreadState* state) {
	state->popReturn();
}

std::string ExitWord::getTraceName() {
	return "ExitWord";
}

static ExitWord EXIT_WORD_INSTANCE;
Word& CompositeWord::EXIT_WORD = EXIT_WORD_INSTANCE;

