//
//  ValueWord.hpp
//  YAF
//
//  Created by John Fitzpatrick on 1/17/18.
//  Copyright © 2018 Dad. All rights reserved.
//

#ifndef ValueWord_hpp
#define ValueWord_hpp

#include "Word.hpp"

/*
 ValueWords push themselves on the data stack when they are interpreted.
 */
class ValueWord : public Word {
public:
	ValueWord();
	virtual ~ValueWord();
	virtual void execute(ThreadState* state);
};

#endif /* ValueWord_hpp */
