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
	return std::to_string(value);
}

IntConstant::operator int() {
	return value;
}

IntConstant& IntConstant::operator=(int x) {
	value = x;
	return *this;
}
