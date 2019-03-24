// DebugMemory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

//For Debug
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

//Notice: test() Error!!! Here, It is an incorrect sample for debug demo.
double test()
{
	double *t = new double[2];  //Warning!!! New memory,But memory is not freed.
	return t[2];                //Warning!!! Access cross-border, memory overflow.
}


//main
int main()
{
	std::cout << "Debug Demo: This is a \"Detected memory leaks\" demo!\n";

	double k = test();

   // For debug	
   _CrtDumpMemoryLeaks();  // Detected memory leaks!
}


//Output View:
//Detected memory leaks!
//Dumping objects ->
//{153} normal block at 0x0049CAB0, 16 bytes long.
//Data: <                > CD CD CD CD CD CD CD CD CD CD CD CD CD CD CD CD
//Object dump complete.