// Str2Int.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// error C4996 : 'ltoa' : The POSIX name for this item is deprecated.Instead, use the ISO C and C++ conformant name : _ltoa.See online help for details.
//Add :菜单栏下“项目”->属性->c / c++->预处理器->预处理器定义->编辑->输入：
// _CRT_NONSTDC_NO_DEPRECATE
// _CRT_SECURE_NO_WARNINGS

#include "pch.h"
#include <iostream>
//using namespace std;

int isspace(int x)
{
	if (x == ' ' || x == '\t' || x == '\n' || x == '\f' || x == '\b' || x == '\r')
		return 1;
	else
		return 0;
}
int isdigit(int x)
{
	if (x <= '9'&&x >= '0')
		return 1;
	else
		return 0;

}

int my_atoi(const char *nptr)
{
	int c;              /* current char */
	int total;         /* current total */
	int sign;           /* if '-', then negative, otherwise positive */

	/* skip whitespace */
	while (isspace((int)(unsigned char)*nptr))
		++nptr;

	c = (int)(unsigned char)*nptr++;
	sign = c;           /* save sign indication */
	if (c == '-' || c == '+')
		c = (int)(unsigned char)*nptr++;    /* skip sign */

	total = 0;

	while (isdigit(c)) {
		total = 10 * total + (c - '0');     /* accumulate digit */
		c = (int)(unsigned char)*nptr++;    /* get next char */
	}

	if (sign == '-')
		return -total;
	else
		return total;   /* return result, negated if necessary */
}


//该函数来源于网络，作了修改,可用于10进制的正负，和16进制正数转换字符串输出。
//
/* 实现itoa函数的源码 */
char *my_itoa(int num, char *str, int radix)
{
	/* 索引表 */
	char index[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	unsigned unum; /* 中间变量 */
	int i = 0, j,  k;
	int n = 0;

	/* 确定unum的值 */
	if (radix == 10 && num < 0) /* 十进制负数 */
	{
		unum = (unsigned)-num;
		str[i++] = '-';
	}
	else unum = (unsigned)num; /* 其它情况 */
	/* 逆序 */
	do
	{
		str[i++] = index[unum % (unsigned)radix];
		unum /= radix;
	} while (unum);
	str[i] = '\0';
	/* 转换 */

	if (str[0] == '-')
	{
		k = 1; /* 十进制负数 */
	}
	else
	{
		n = 1;  //Modified 2021/3/3 For 负数
		k = 0;
	}

	/* 将原来的“/2”改为“/2.0”，保证当num在16~255之间，radix等于16时，也能得到正确结果 */
	char temp;


	for (j = k; j <= (i - k ) / 2.0; j++)
	{
		temp = str[j];
		str[j] = str[i - j - n ];
		str[i - j - n ] = temp;
	}
	return str;
}


//只用
int my_itoa_10(int val, char* buf)
{
	const unsigned int radix = 10;

	char* ptr;
	unsigned int a; //every digit
	int len;
	char* startChar; //start of the digit char
	char temp;
	unsigned int u;

	ptr = buf;

	if (val < 0)
	{
		*ptr++ = '-';
		val = 0 - val;
	}
	u = (unsigned int)val;

	startChar = ptr;

	do
	{
		a = u % radix;
		u /= radix;

		*ptr++ = a + '0';

	} while (u > 0);

	len = (int)(ptr - buf);

	*ptr-- = 0;

	//swap
	do
	{
		temp = *ptr;
		*ptr = *startChar;
		*startChar = temp;
		--ptr;
		++startChar;

	} while (startChar < ptr);

	return len;
}


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

// My Int to String
char* my_Int2Str(int num, char* str)
{
	my_itoa( num, str ,10);

	return str;
}

char* my_Int2Str10(int num, char* str)
{
	my_itoa_10(num, str);

	return str;
}

char* my_Int2Str_sp(int num, char* str)
{
	sprintf(str, "%d", num);

	return str;
}

int main()
{
	char psVal[50] = {0};
	std::cout << "Str2Int: " << Str2Int("-12345");

	std::cout << "\n";
	//std::cout << endl;  //Need Add "using namespace std;" 

	std::cout << "Int2Str: " << Int2Str(-23456, psVal);
	
	std::cout << "\n";

	std::cout << "my_Int2Str: " << my_Int2Str(-23456, psVal);
	std::cout << "\n";

	std::cout << "my_Int2Str10: " << my_Int2Str10(-23456, psVal);
	std::cout << "\n";

	std::cout << "my_Int2Str_sp: " << my_Int2Str_sp(-23456, psVal);

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
