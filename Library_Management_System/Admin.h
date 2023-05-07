#pragma once

#include <iostream>
#include <vector>
#include "RegisteredUser.h"
#include "Helper.h"


using namespace std;

class Admin :public RegisteredUser
{
public:
	Admin();
	Admin(string, string, string, string);
	~Admin();

	void addNewBook(Library*);

	void showABookByID(Library*);

	void hideABookByID(Library*);

	void removeABookByID(Library*);

	void editABookByID(Library*);

	void createCollection(Library*);

	void removeCollectionByID(Library*);

	void changeCollectionName(Library*);

	void addBookToCollection(Library*);

	void removeBookFromCollection(Library*);

	void addBookToSampleCollection(Library*);

	void removeBookFromSampleCollection(Library*);


	void loginForAdmin(vector<Admin*> tempListAdmin, string enteredUsername, string enteredPassword);

	void logoutForAdmin();
};
