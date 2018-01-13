//
//  main.cpp
//  YAF
//
//  Created by Dad on 1/4/18.
//  Copyright © 2018 Dad. All rights reserved.
//

#include <iostream>
#include "ThreadState.hpp"
#include "LoggingWord.hpp"
#include "CompositeWord.hpp"
#include "SystemState.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
	
	LoggingWord Hello_H("H");
	LoggingWord Hello_E("e");
	LoggingWord Hello_L("l");
	LoggingWord Hello_O("o");
	LoggingWord Hello_BANG("!");
	LoggingWord Hello_SPACE(" ");
	LoggingWord World("World!\n");
	LoggingWord One("1");
	LoggingWord Two("2");
	LoggingWord Three("3");
	LoggingWord Four("4");
	WordReference countingBits[] = {
		&One,
		&Two,
		&Three,
		&Four,
		&CompositeWord::EXIT_WORD
	};
	CompositeWord counting(countingBits);
	WordReference hBits[] = {
		&Hello_H,
		&CompositeWord::EXIT_WORD
	};
	CompositeWord justH(hBits);
	WordReference bangBits[] = {
		&Hello_BANG,
		&Hello_BANG,
		&Hello_BANG,
		&CompositeWord::EXIT_WORD
	};
	CompositeWord bangBangBang(bangBits);
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
	CompositeWord Hello(helloBits);
	WordReference recipeBits[] = {
		&Hello,
		&World,
		&CompositeWord::EXIT_WORD
	};
	CompositeWord helloWorldWord(recipeBits);
	ThreadState* thread1 = new ThreadState(10, 10, &helloWorldWord);
	ThreadState* thread2 = new ThreadState(10, 10, &counting);
//	ThreadState* thread3 = new ThreadState(10,10,&justH);

	SystemState systemState(thread1);
	systemState.addThread(thread2);
	
	while (systemState.run()) {	}
	return 0;
}
