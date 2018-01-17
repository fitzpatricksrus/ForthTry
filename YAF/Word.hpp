//
//  Word.hpp
//  YAF
//
//  Created by Dad on 1/10/18.
//  Copyright © 2018 Dad. All rights reserved.
//

#ifndef Word_hpp
#define Word_hpp

#include <string>

class ThreadState;

/**
 * Data used by the inner interpreter and base primatives.
 */
class Word {
public:
	virtual ~Word();
	virtual void execute(ThreadState* state);
	
	virtual std::string getTraceName();
};

typedef Word* WordReference;
typedef WordReference* WordRecipe;

#endif /* Word_hpp */
