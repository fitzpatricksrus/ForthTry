//
//  ConstantValue.cpp
//  YAF
//
//  Created by John Fitzpatrick on 1/18/18.
//  Copyright © 2018 Dad. All rights reserved.
//

#include "ConstantValue.hpp"

ConstantValue::ConstantValue() {
	
}

ConstantValue::ConstantValue(int value) {
	
}

ConstantValue::~ConstantValue() {
	
}

std::string ConstantValue::getTraceName(){
	return std::to_string(value.i);
}

ConstantValue::operator char() {
	return value.c;
}

ConstantValue& ConstantValue::operator=(char x) {
	value.c = x;
	return *this;
}

ConstantValue::operator int() {
	return value.i;
}

ConstantValue& ConstantValue::operator=(int x) {
	value.i = x;
	return *this;
}

ConstantValue::operator WordReference() {
	return value.w;
}

ConstantValue& ConstantValue::operator=(WordReference x) {
	value.w = x;
	return *this;
}
