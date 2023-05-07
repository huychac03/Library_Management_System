#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "RegisteredUser.h"

#include "Helper.h"
using namespace std;


class Member : public RegisteredUser
{
private:
	string memberShipDuration;
	vector<Collection*> listOfSubCollection;
	Collection* sampleCollection;

	vector<Book*> listBookBorrowed;

public:
	Member();
	Member(string, string, string, string, string, Collection*);
	~Member();

	Collection* getSampleCollection();
	void setSampleCollection(Collection*);

	string getMemberShipDuration();
	void setMemberShipDuration(string);

	vector<Collection*> getListOfSubCollection();

	void Read(vector<Book*> tempListBook) override;


	void borrowBook(vector<Book*> tempListBook);
	void returnBook();


	void subCollection(vector<Collection*> tempListCollection);
	void unSubCollection();

	void loginForMember(vector<Member*>& listAllAdmin, string enteredUsername, string enteredPassword);
	void logoutForMember();

};

