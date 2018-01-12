//
//  CompositeWord.hpp
//  YAF
//
//  Created by Dad on 1/10/18.
//  Copyright © 2018 Dad. All rights reserved.
//

#ifndef CompositeWord_hpp
#define CompositeWord_hpp

#include "Word.hpp"

/**
 * Data used by the inner interpreter and base primatives.
 */
class CompositeWord : public Word {
public:
	WordReference* recipe;	//array of word references
	bool ownsRecipe;
	
	CompositeWord(int size);
	CompositeWord(WordRecipe recipe);				//adopt & free recipe
	CompositeWord(WordRecipe recipe, int size);		//copy recipe
	virtual ~CompositeWord();
	virtual void execute (ThreadState* state);
	
	static Word& EXIT_WORD;

};

#endif /* CompositeWord_hpp */
