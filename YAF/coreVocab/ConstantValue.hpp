//
//  ConstantValue.hpp
//  YAF
//
//  Created by John Fitzpatrick on 1/18/18.
//  Copyright © 2018 Dad. All rights reserved.
//

#ifndef ConstantValue_hpp
#define ConstantValue_hpp

#include "ValueWord.hpp"

class ConstantValue : public ValueWord {
public:
	ConstantValue();
	ConstantValue(int value);
	virtual ~ConstantValue();
	virtual std::string getTraceName();
	
	operator char();
	ConstantValue& operator=(char x);
	
	operator int();
	ConstantValue& operator=(int x);
	
	operator WordReference();
	ConstantValue& operator=(WordReference x);
	
private:
	struct Values {
		char c;
		int i;
		WordReference w;
	};
	
	Values value;
};

#endif /* ConstantValue_hpp */
