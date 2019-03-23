#include "Singleton.h"

 #include <iostream> 
 #include <mutex>   //define td::once_flag in C++11

//You need to declare this instance variable outside
Singleton* Singleton::m_instance = NULL;

Singleton::Singleton()
{
}

Singleton::~Singleton()
{
}

//Get singleton instance
Singleton* Singleton::getInstance() {
	//std::once_flag in C++11 (e.g. VC++ 2017)
	static std::once_flag oc;
	std::call_once(oc, [&] {  m_instance = new Singleton(); });
	return m_instance;
}

//releas singleton instance
void Singleton::releasInstance() {
	if (Singleton::m_instance) {
		delete Singleton::m_instance;
		Singleton::m_instance = NULL;
	}
}

//print this instance address
void Singleton::printAddress() const {
	std::cout << this << std::endl;
}

