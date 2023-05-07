#include "RegisteredUser.h"

RegisteredUser::RegisteredUser() :username(""), password(""), fullname(""), phone("")
{
	string id = createID();
	User::setID(id);
	User::setAccessibilityLevel(REGIST);
}

RegisteredUser::RegisteredUser(string nUsername, string nPass, string nFullname, string nPhone)
{
	string id = createID();
	User::setID(id);
	User::setAccessibilityLevel(REGIST);
	this->username = nUsername;
	this->password = nPass;
	this->fullname = nFullname;
	this->phone = nPhone;
}

string RegisteredUser::getUsername()
{
	return this->username;
}

void RegisteredUser::setUsername(string nUsername)
{
	this->username = nUsername;
}



void RegisteredUser::Read(vector<Book*> tempListBook)
{
	cout << "Read in Register";
}

string RegisteredUser::createID()
{
	int numPart;
	char charPart = 'R';

	numPart = rand() % 1000 + 1000;

	string nID;

	nID.push_back(charPart);
	nID += to_string(numPart);

	return nID;
}

string RegisteredUser::getPassword()
{
	return this->password;
}

void RegisteredUser::setPassword(string nPass)
{
	this->password = nPass;
}

string RegisteredUser::getFullname()
{
	return fullname;
}

void RegisteredUser::setFullname(string nFullname)
{
	this->fullname = nFullname;
}

string RegisteredUser::getPhone()
{
	return this->phone;
}

void RegisteredUser::setPhone(string nPhone)
{
	this->phone = nPhone;
}
