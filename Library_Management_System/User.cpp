#include "User.h"

User::User() :ID(""), accessibilityLevel(GUEST)
{
}

User::User(string nID, aType nAccess) :ID(nID), accessibilityLevel(nAccess)
{
}

User::~User()
{
}

string User::getID()
{
	return ID;
}

void User::setID(string nID)
{
	ID = nID;
}

aType User::getAccessibilityLevel() {
	return accessibilityLevel;
}

void User::setAccessibilityLevel(aType nAccess)
{
	accessibilityLevel = nAccess;
}

void User::Search(vector<Book*> tempListBook)
{
	cout << "Search a book-----------------------" << endl;

	cout << "Choose the way u wanna search that book" << endl;
	cout << "1. By ID " << endl;
	cout << "2. By Title " << endl;
	cout << "3. By Serial Number" << endl;

	int bookID = 99999;
	string title = "";
	string serialNumber = "";

	bool check = false;


	int opt = 1;
	cout << "Enter ur option: ";
	cin >> opt;
	if (opt == 1) {
		cout << "Enter Book ID: " << endl;
		cin >> bookID;
	}
	else if (opt == 2) {
		cout << "Enter Book Title: " << endl;
		cin >> title;
	}
	else {
		cout << "Enter book serial number" << endl;
		cin >> serialNumber;
	}

	for (int i = 0; i < tempListBook.size(); i++) {
		if (tempListBook[i]->getVisibility() == true) {
			if (tempListBook[i]->getID() == bookID || tempListBook[i]->getTitle() == title || tempListBook[i]->getSerialNumber() == serialNumber) {
				check = true;
			}
			else {
				continue;
			}
		}		
	}


	if (check == true) {
		for (int i = 0; i < tempListBook.size(); i++) {
			if (tempListBook[i]->getVisibility() == true) {
				if (tempListBook[i]->getID() == bookID || tempListBook[i]->getTitle() == title || tempListBook[i]->getSerialNumber() == serialNumber) {
					tempListBook[i]->showAllInfor();

					break;
				}
				else {
					continue;
				}
			}
			
		}
	}
	else {
		cout << "No Book match this ID" << endl;

	}

}


