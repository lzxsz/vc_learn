// Str2Int.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
//using namespace std;

//String to Int
int Str2Int(const char* str)
{
	return atol(str);
}

//Int to String
char* Int2Str(int num, char* str)
{
	ltoa(num, str,10);
	return str;
}

int main()
{
	char psVal[50] = {0};
	std::cout << "Str2Int: " << Str2Int("-12345");

	std::cout << "\n";
	//std::cout << endl;  //Need Add "using namespace std;" 

	std::cout << "Int2Str: " << Int2Str(-23456, psVal);
	
    //std::cout << "Hello World!\n"; 
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
