//
//  CompositeWord.hpp
//  YAF
//
//  Created by Dad on 1/10/18.
//  Copyright © 2018 Dad. All rights reserved.
//

#ifndef CompositeWord_hpp
#define CompositeWord_hpp

#include <stdio.h>

#include "Word.hpp"
#include "ThreadState.hpp"

/**
 * Data used by the inner interpreter and base primatives.
 */
class CompositeWord : public Word {
public:
	WordReference* recipe;	//array of word references
	
	CompositeWord(int size);
	CompositeWord(WordRecipe recipe);
	virtual ~CompositeWord();
	virtual void execute (ThreadState* state);
	
	class ExitWord : public Word {
	public:
		virtual ~ExitWord();
		virtual void execute (ThreadState* state);
	};
};

#endif /* CompositeWord_hpp */
