#pragma once
#include <iostream>
#include <vector>
#include "Library.h"


using namespace std;

enum aType {
	GUEST = 111,
	REGIST = 222,
	MEMBER = 333,
	ADMIN = 444
};

class User
{
private:
	string ID;
	aType accessibilityLevel;


public:
	User();
	User(string, aType);
	~User();

	string getID();
	void setID(string);

	aType getAccessibilityLevel();
	void setAccessibilityLevel(aType);


	void Search(vector<Book*> tempListBook);
	virtual void Read(vector<Book*> tempListBook) = 0;

	virtual string createID() = 0;


};

