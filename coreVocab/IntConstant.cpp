//
//  IntConstant.cpp
//  YAF
//
//  Created by John Fitzpatrick on 1/17/18.
//  Copyright © 2018 Dad. All rights reserved.
//

#include "IntConstant.hpp"

IntConstant::IntConstant() {
	
}

IntConstant::IntConstant(int value) {
	
}

IntConstant::~IntConstant() {
	
}

std::string IntConstant::getTraceName(){
	return std::to_string(value.i);
}

IntConstant::operator int() {
	return value.i;
}

IntConstant& IntConstant::operator=(int x) {
	value.i = x;
	return *this;
}

IntConstant::operator char() {
	return value.c;
}

IntConstant& IntConstant::operator=(char x) {
	value.c = x;
	return *this;
}

IntConstant::operator WordReference() {
	return value.w;
}

IntConstant& IntConstant::operator=(WordReference x) {
	value.w = x;
	return *this;
}
