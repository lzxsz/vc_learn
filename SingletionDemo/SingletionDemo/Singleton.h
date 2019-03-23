#pragma once

class Singleton
{
public:
	static Singleton* getInstance();  //get singleton instance
	static void releasInstance();     //releas singleton instance

	void printAddress() const;        //print this instance address

private:
	//Construction and Deconstruction use private
	Singleton();
	~Singleton();

	static Singleton* m_instance;     //instance pointer
};


