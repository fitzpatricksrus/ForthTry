//
//  ExitSystemWord.cpp
//  YAF
//
//  Created by Dad on 1/10/18.
//  Copyright © 2018 Dad. All rights reserved.
//

#include "ExitSystemWord.hpp"

#include <stdlib.h>

ExitSystemWord::ExitSystemWord(int codeIn)
: Word(), code(codeIn) {
	
}

ExitSystemWord::~ExitSystemWord() {
}

void ExitSystemWord::execute (ThreadState* state) {
	exit(code);
}
