//
//  SystemState.cpp
//  YAF
//
//  Created by Dad on 1/11/18.
//  Copyright © 2018 Dad. All rights reserved.
//

#include "SystemState.hpp"

class ThreadList {
public:
	ThreadList* prevThread;
	ThreadList* nextThread;
	ThreadState* state;
	
	ThreadList(ThreadState* stateIn);
	~ThreadList();

	void insertNext(ThreadList* newNextThread);
	bool removeSelf();
	ThreadList* find(ThreadState* state);
	
	bool run();
};

ThreadList::ThreadList(ThreadState* stateIn)
: prevThread(this), nextThread(this), state(stateIn)
{
	//next ThreadLists are a list of thier own with just themselves.
}

ThreadList::~ThreadList() {
	delete state;
}

void ThreadList::insertNext(ThreadList* newNextThread) {
	// set up back pointers
	nextThread->prevThread = newNextThread;
	newNextThread->prevThread = this;
	
	// set up forward pointers
	newNextThread->nextThread = nextThread;
	nextThread = newNextThread;
}

bool ThreadList::removeSelf() {
	if (this == nextThread) {
		return false;
	} else {
		nextThread->prevThread = prevThread;
		prevThread->nextThread = nextThread;
		prevThread = this;
		nextThread = this;
		return true;
	}
}

ThreadList* ThreadList::find(ThreadState* stateIn) {
	if (stateIn == state) {
		return this;
	} else {
		ThreadList* node = nextThread;
		while (this != node) {				//terminate when we're back at us
			if (node->state == stateIn) {
				return node;
			} else {
				node = node->nextThread;
			}
		}
		return nullptr;
	}
}

bool ThreadList::run() {
	return state->run();
}

SystemState::SystemState(ThreadState* mainThread)
{
	currentThread = new ThreadList(mainThread);
}

SystemState::~SystemState(){
	ThreadList* next = currentThread->nextThread;
	while (next->removeSelf()) {
		next = currentThread->nextThread;
	}
	delete currentThread;
	currentThread = nullptr;
}

void SystemState::addThread(ThreadState* state) {
	currentThread->insertNext(new ThreadList(state));
}

bool SystemState::run() {
	if (currentThread->run()) {
		currentThread = currentThread->nextThread;
		return true;
	} else {
		//the current thread is done, so we need to delete it.
		ThreadList* deadThread = currentThread;
		currentThread = currentThread->nextThread;
		return deadThread->removeSelf();
	}
}

