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

	void insert(ThreadList* newNextThread);
	void removeSelf();
	ThreadList* find(ThreadState* state);
	
	ThreadList* run();
};

ThreadList::ThreadList(ThreadState* stateIn)
: prevThread(this), nextThread(this), state(stateIn)
{
	//next ThreadLists are a list of thier own with just themselves.
}

ThreadList::~ThreadList() {
	delete state;
}

void ThreadList::insert(ThreadList* newNextThread) {
	// set up back pointers
	nextThread->prevThread = newNextThread;
	newNextThread->prevThread = this;
	
	// set up forward pointers
	newNextThread->nextThread = nextThread;
	nextThread = newNextThread;
}

void ThreadList::removeSelf() {
	nextThread->prevThread = prevThread;
	prevThread->nextThread = nextThread;
	prevThread = nullptr;
	nextThread = nullptr;
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

ThreadList* ThreadList::run() {
	if (state->run()) {
		// this thread is still working and can stay in the list.
		return nextThread;
	} else {
		// this thread is done, so it needs to be removed from the list
		if (this == nextThread) {
			// we're the only thread and we're done, so shut down the system.
			return nullptr;
		} else {
			// this thread is done, but other still have work to do, so
			// just remove this thread from the list and leave the rest.
			ThreadList* result = nextThread;
			removeSelf();
			return result;
		}
	}
}

SystemState::SystemState(ThreadState* mainThread)
{
	currentThread = new ThreadList(mainThread);
}

SystemState::~SystemState(){
	while (currentThread != currentThread->nextThread) {
		ThreadList* d = currentThread;
		currentThread = currentThread->nextThread;
		d->removeSelf();
		delete d;
	}
	delete currentThread;
	currentThread = nullptr;
}

void SystemState::addThread(ThreadState* state) {
	currentThread->insert(new ThreadList(state));
}

void SystemState::removeThread(ThreadState* state) {
	ThreadList* t = currentThread->find(state);
	if (t == currentThread) {
		currentThread = currentThread->nextThread;
	}
	if (t == currentThread) {
		currentThread = nullptr;
		// TODO this will crash things.  We've removed the only thread.
	}
}

bool SystemState::run() {
	currentThread = currentThread->run();
	return currentThread;
}

