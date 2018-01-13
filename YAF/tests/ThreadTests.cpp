//
//  ThreadTests.cpp
//  YAF
//
//  Created by Dad on 1/12/18.
//  Copyright © 2018 Dad. All rights reserved.
//

#include "ThreadTests.hpp"

#include <iostream>
#include "ThreadState.hpp"
#include "LoggingWord.hpp"
#include "CompositeWord.hpp"
#include "SystemState.hpp"

void ThreadTests::doTest() {
	// insert code here...
	
	LoggingWord Hello_H("H", "Hello_H");
	LoggingWord Hello_E("e", "Hello_E");
	LoggingWord Hello_L("l", "Hello_L");
	LoggingWord Hello_O("o", "Hello_O");
	LoggingWord Hello_BANG("!", "Hello_BANG");
	LoggingWord Hello_SPACE(" ", "Hello_SPACE");
	LoggingWord World("World!\n", "World");
	LoggingWord One("1", "One");
	LoggingWord Two("2", "Two");
	LoggingWord Three("3", "Three");
	LoggingWord Four("4", "Four");
	WordReference countingBits[] = {
		&One,
		&Two,
		&Three,
		&Four,
		&Three,
		&Two,
		&One,
		&CompositeWord::EXIT_WORD
	};
	CompositeWord counting(countingBits, "(counting)"); //counting = <One><Two><Three><Four><Three><Two><One>");
	WordReference hBits[] = {
		&Hello_H,
		&CompositeWord::EXIT_WORD
	};
	CompositeWord justH(hBits, "justH = <Hello_H>");
	WordReference bangBits[] = {
		&Hello_BANG,
		&Hello_BANG,
		&Hello_BANG,
		&CompositeWord::EXIT_WORD
	};
	CompositeWord bangBangBang(bangBits, "bangBangBang = <Hello_BANG><Hello_BANG><Hello_BANG>");
	WordReference helloBits[] = {
		&justH,
		&Hello_E,
		&Hello_L,
		&Hello_L,
		&Hello_O,
		&bangBangBang,
		&Hello_SPACE,
		&CompositeWord::EXIT_WORD
	};
	CompositeWord Hello(helloBits, "<justH><Hello_E><Hello_L><Hello_L><Hello_O><BangBangBang><HelloSpace> ");
	WordReference recipeBits[] = {
		&Hello,
		&World,
		&CompositeWord::EXIT_WORD
	};
	CompositeWord helloWorldWord(recipeBits, "(HelloWorld)"); //HelloWorld = <Hello><World>");
	ThreadState* thread1 = new ThreadState(10, 10, &helloWorldWord);
	ThreadState* thread2 = new ThreadState(10, 10, &counting);
	ThreadState* thread3 = new ThreadState(10 ,10, &justH);
	
	SystemState systemState(thread1);
	systemState.addThread(thread3);
	systemState.addThread(thread2);
	
	thread1->setTrace(true);
	thread2->setTrace(true);
	thread3->setTrace(true);

	while (systemState.run()) {	}
}
