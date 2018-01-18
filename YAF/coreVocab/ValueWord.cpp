//
//  ValueWord.cpp
//  YAF
//
//  Created by John Fitzpatrick on 1/17/18.
//  Copyright © 2018 Dad. All rights reserved.
//

#include "ValueWord.hpp"
#include "ThreadState.hpp"

ValueWord::ValueWord() {
	
}

ValueWord::~ValueWord() {
	
}

void ValueWord::execute(ThreadState* state) {
	state->pushData(this);
}
