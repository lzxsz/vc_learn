// SingletionDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
// This is demo for C++11 (e.g. Visual Studio 2017)

#include <iostream>
#include "Singleton.h"

//For Debug

/*
#define CRTDBG_MAP_ALLOC    
#include <stdlib.h>    
#include <crtdbg.h> 

#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define DBG_NEW new
#endif
*/

int main()
{
    //std::cout << "Hello World!\n"; 

	Singleton* singleton1 = Singleton::getInstance();
	printf("singleton1 address: ");
	singleton1->printAddress();

	Singleton* singleton2 = Singleton::getInstance();
	printf("singleton2 address: ");
	singleton2->printAddress();

	if (singleton1 == singleton2) {
		fprintf(stdout, "singleton1 = singleton2\n");
	}

	 //releas singleton instance
	 Singleton::releasInstance();

	 // For debug	
	// _CrtDumpMemoryLeaks();  // Detected memory leaks!
}
