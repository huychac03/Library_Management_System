#pragma once
#include "User.h"
#include <string>

using namespace std;

class RegisteredUser : public User
{
private:
	string username;
	string password;
	string fullname;
	string phone;



public:
	RegisteredUser();
	RegisteredUser(string, string, string, string);
	~RegisteredUser() {}

	string getUsername();
	void setUsername(string nUsername);

	string getPassword();
	void setPassword(string nPass);

	string getFullname();
	void setFullname(string nFullname);

	string getPhone();
	void setPhone(string nPhone);

	virtual void Read(vector<Book*> tempListBook) override;

	string createID() override;


};

