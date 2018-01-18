//
//  IntConstant.hpp
//  YAF
//
//  Created by John Fitzpatrick on 1/17/18.
//  Copyright © 2018 Dad. All rights reserved.
//

#ifndef IntConstant_hpp
#define IntConstant_hpp

#include "ValueWord.hpp"

class IntConstant : public ValueWord {
public:
	IntConstant();
	IntConstant(int value);
	virtual ~IntConstant();
	virtual std::string getTraceName();
	
	operator int();
	IntConstant& operator=(int x);
	
	operator char();
	IntConstant& operator=(char x);
	
	operator WordReference();
	IntConstant& operator=(WordReference x);
	
private:
	struct Values {
		char c;
		int i;
		WordReference w;
	};
	
	Values value;
};

#endif /* IntConstant_hpp */
