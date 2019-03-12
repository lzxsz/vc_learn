#pragma once
#include <ctime>
#include <string>
#include <vector>
using namespace std;

class User
{
public:
	User();
	~User();

protected:
	time_t    register_time;    //User register time
	string    user_name;        //User name

public:
	void setRegisterTime(time_t registerTime);  //set register time
	void setUserName(string userName);          //set user name

	time_t getRegisterTime();                   //get register time
	string getUserName();                       //get user name
};

