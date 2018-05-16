//
//  NextTokenWord.hpp
//  YAF
//
//  Created by Dad on 2/25/18.
//  Copyright © 2018 Dad. All rights reserved.
//

#ifndef NextTokenWord_hpp
#define NextTokenWord_hpp

#include "Word.hpp"

class NextTokenWord : public Word {
public:
	NextTokenWord();
	virtual ~NextTokenWord();
	virtual void execute(ThreadState* state);
};


#endif /* NextTokenWord_hpp */
