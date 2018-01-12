//
//  SystemState.hpp
//  YAF
//
//  Created by Dad on 1/11/18.
//  Copyright © 2018 Dad. All rights reserved.
//

#ifndef SystemState_hpp
#define SystemState_hpp

#include "ThreadState.hpp"

class ThreadList;

class SystemState {
public:
	SystemState(ThreadState* mainThread);
	~SystemState();
	void addThread(ThreadState* state);
	void removeThread(ThreadState* state);
	bool run();
	
private:
	ThreadList* currentThread;
};

#endif /* SystemState_hpp */



