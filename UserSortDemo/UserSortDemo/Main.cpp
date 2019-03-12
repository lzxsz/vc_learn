// Main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <string>
#include<algorithm>

#include "User.h"

using namespace std;

//String to time_t
time_t stringToDatetime(string str)
{
	char *cha = (char*)str.data();             // Convert string to char*.
	tm tm_;                                    // Define the TM structure.
	int year, month, day, hour, minute, second;// Each int temporary variable that defines the time.
	sscanf(cha, "%d-%d-%d %d:%d:%d", &year, &month, &day, &hour, &minute, &second);// Converts the date and time stored in string to an int temporary variable.
	tm_.tm_year = year - 1900;                 // Year£¬Since TM structure stores time from 1900, tm_year subtracts 1900 from int temporary variable.
	tm_.tm_mon = month - 1;                    // Month, because the monthly storage range of the TM structure is 0-11, tm_mon is an int temporary variable minus 1.
	tm_.tm_mday = day;                         // Day.
	tm_.tm_hour = hour;                        // Hour.
	tm_.tm_min = minute;                       // Minute.
	tm_.tm_sec = second;                       // Seconds.
	tm_.tm_isdst = 0;                          // It's not daylight saving time.
	time_t t_ = mktime(&tm_);                  // The TM structure is converted into time_t format.
	return t_;                                 // Return value.
}



int main()
{
	//cout << "Hello World!" << endl;

	//Define User List
	vector<User> userList;

	//Init User Register Time
	time_t t_;  //second
	tm  gmt;   //greenwich mean time;

	char buf[128] = { 0 };
	vector<string>  arrRegisterTime  = { "2019-3-11 11:02:02","2019-3-11 11:03:03" ,"2019-3-11 11:01:01","2019-3-11 11:05:05","2019-3-11 11:04:04" };
	vector<string>  arrUserName      = { "Davy", "Bob", "Joe", "Zack", "Randy" };

	int count = arrRegisterTime.size();
    for(int i=0; i<count; i++){
		User user;  
  		time_t t_= stringToDatetime(arrRegisterTime[i]);

			user.setRegisterTime(t_); // Set register time
			user.setUserName(arrUserName[i]);  //Set user name
           
			userList.push_back(user);
                  
	}

	
	std::cout << "Before sorting:" << endl;
	//output register time and user name
	for (size_t i = 0; i < userList.size(); ++i) {
		time_t t = userList[i].getRegisterTime();
		tm *pTmp = localtime(&t);
		char szTime[128];

		sprintf(szTime, "%d-%d-%d %d:%d:%d", pTmp->tm_year + 1900, pTmp->tm_mon + 1, pTmp->tm_mday, pTmp->tm_hour, pTmp->tm_min, pTmp->tm_sec);
		string userName = userList[i].getUserName();
		std::cout << szTime << "    " << userName << endl;
	}


	std::cout <<"---------------------------------------" <<endl;

	sort(userList.begin(), userList.end(), [](User & user1, User & user2)
	{
		if (user1.getRegisterTime() < user2.getRegisterTime()) {
			return true;
		}
		else
		{
			return false;
		}
	});


	std::cout << "Sort user by register time:" << endl;
	//output register time and user name
	for (size_t i = 0; i < userList.size(); ++i) {
		time_t t = userList[i].getRegisterTime();
		tm *pTmp = localtime(&t);
		char szTime[128];

		sprintf(szTime, "%d-%d-%d %d:%d:%d", pTmp->tm_year + 1900, pTmp->tm_mon + 1, pTmp->tm_mday, pTmp->tm_hour, pTmp->tm_min, pTmp->tm_sec);		
		string userName = userList[i].getUserName();
		std::cout << szTime << "    " << userName << endl;
	}

	//--------------------------------------------------
	//Sort user by name
	sort(userList.begin(), userList.end(), [](User & user1, User & user2)
	{
		if (user1.getUserName() < user2.getUserName()) {
			return true;
		}
		else
		{
			return false;
		}
	});


	std::cout << "---------------------------------------" << endl;
	std::cout << "Sort user by name:" << endl;
	//output register time
	for (size_t i = 0; i < userList.size(); ++i) {
		time_t t = userList[i].getRegisterTime();
		tm *pTmp = localtime(&t);
		char szTime[128];

		sprintf(szTime, "%d-%d-%d %d:%d:%d", pTmp->tm_year + 1900, pTmp->tm_mon + 1, pTmp->tm_mday, pTmp->tm_hour, pTmp->tm_min, pTmp->tm_sec);
		string userName = userList[i].getUserName();
		std::cout << szTime << "    " << userName << endl;
	}


}
