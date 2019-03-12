// #include "pch.h"
#include<string>
#include <ctime>
#include <algorithm>    // std::sort
#include <vector>       // std::vector

#include "User.h"
//using namespace std;


User::User()
{
}


User::~User()
{
}

//set register time
void User::setRegisterTime(time_t registerTime) {

	register_time = registerTime;
}

//set user name
void User::setUserName(string userName) {
	user_name = userName;
}

//get register time
time_t User::getRegisterTime() {
	return register_time;
}

//get user name
string User::getUserName() {
	return user_name;
}

