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
	CompositeWord(int size, std::string name = "");
	CompositeWord(WordRecipe recipe, std::string name = "");				//adopt & free recipe
	CompositeWord(WordRecipe recipe, int size, std::string name = "");		//copy recipe
	virtual ~CompositeWord();
	
	WordReference& operator[](int ndx);
	
	virtual void execute(ThreadState* state);
	virtual std::string getTraceName();
	
	static Word& EXIT_WORD;

private:
	WordReference* recipe;	//array of word references
	bool ownsRecipe;
	std::string traceName;
};

#endif /* CompositeWord_hpp */
