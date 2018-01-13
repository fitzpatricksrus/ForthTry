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
	CompositeWord(int size, const char* name = nullptr);
	CompositeWord(WordRecipe recipe, const char* name = nullptr);				//adopt & free recipe
	CompositeWord(WordRecipe recipe, int size, const char* name = nullptr);		//copy recipe
	virtual ~CompositeWord();
	
	WordReference& operator[](int ndx);
	
	virtual void execute(ThreadState* state);
	virtual const char* getTraceName();
	
	static Word& EXIT_WORD;

private:
	WordReference* recipe;	//array of word references
	bool ownsRecipe;
	const char* traceName;
};

#endif /* CompositeWord_hpp */
