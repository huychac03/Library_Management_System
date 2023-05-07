#include "Member.h"

Member::Member() :RegisteredUser()
{
	User::setAccessibilityLevel(MEMBER);
	this->memberShipDuration = "";
	this->listOfSubCollection.clear();
}

Member::Member(string nUsername, string nPass, string nFullname, string nPhone, string nMemberShipDuration, Collection* tempSampleCollection) :RegisteredUser(/*nID, */nUsername, nPass, nFullname, nPhone)
{
	User::setAccessibilityLevel(MEMBER);
	this->memberShipDuration = nMemberShipDuration;
	this->sampleCollection = tempSampleCollection;
	listOfSubCollection.push_back(tempSampleCollection);
}

Member::~Member()
{
	this->memberShipDuration = "";
	if (listOfSubCollection.size() > 0) {
		for (int i = 0; i < listOfSubCollection.size(); i++) {
			if (listOfSubCollection[i]) delete listOfSubCollection[i];
		}
	}
	if (listBookBorrowed.size() > 0) {
		for (int i = 0; i < listBookBorrowed.size(); i++) {
			if (listBookBorrowed[i]) delete listBookBorrowed[i];
		}
	}
}

Collection* Member::getSampleCollection()
{
	return sampleCollection;
}

void Member::setSampleCollection(Collection* tempSampleCollection)
{
	sampleCollection = tempSampleCollection;
}

string Member::getMemberShipDuration()
{
	return this->memberShipDuration;
}

void Member::setMemberShipDuration(string nMemberShipDuration)
{
	this->memberShipDuration = nMemberShipDuration;
}

vector<Collection*> Member::getListOfSubCollection()
{
	return this->listOfSubCollection;
}

void Member::Read(vector<Book*> tempListBook)
{

	cout << "List of all book in the library: " << endl;
	for (int i = 0; i < tempListBook.size(); i++) {
		if (tempListBook[i]->getVisibility() == true) {
			cout << tempListBook[i]->getTitle() << " --- " << tempListBook[i]->getID() << endl;
		}
	}

	cout << "Enter the ID of a book to read: " << endl;
	int bookID = 0;
	cin >> bookID;

	if (Helper::HelperCheckBook(bookID, tempListBook)) {

		cout << "Reading " << tempListBook[bookID - 1]->getTitle() << endl;
	}
	else {
		cout << "No Book match this ID" << endl;
	}

}


void Member::borrowBook(vector<Book*> tempListBook)
{
	cout << "Borrow Book function worked------------" << endl;

	for (int i = 0; i < tempListBook.size(); i++) {
		if (tempListBook[i]->getVisibility() == true) {
			tempListBook[i]->showAllInfor();
		}
	}

	cout << "Enter the BookID" << endl;
	int bookID;
	cin >> bookID;


	if (Helper::HelperCheckBook(bookID, tempListBook)) {
		
		for (int i = 0; i < tempListBook.size(); i++) {
			if (tempListBook[i]->getVisibility() == true) {
				if (tempListBook[i]->getID() == bookID) {
					listBookBorrowed.push_back(tempListBook[i]);
					//cout << "Borrowed Book with ID: " << bookID << endl;
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

void Member::returnBook()
{
	cout << "Return Book function worked------------" << endl;

	for (int i = 0; i < listBookBorrowed.size(); i++) {
		listBookBorrowed[i]->showAllInfor();
	}

	cout << "Enter the Book ID" << endl;
	int bookID;
	cin >> bookID;

	if (Helper::HelperCheckBook(bookID, listBookBorrowed)) {
		cout << "Returned Book with ID: " << bookID << endl;

		for (int i = 0; i < listBookBorrowed.size(); i++) {

			if (listBookBorrowed[i]->getID() == bookID) {
				listBookBorrowed.erase(listBookBorrowed.begin() + i);
			}
			else {
				continue;
			}
		}

	}
	else {
		cout << "No Book match this ID" << endl;
	}
}

void Member::subCollection(vector<Collection*> tempListCollection)
{
	cout << "Sub Collection function worked------------" << endl;

	for (int i = 0; i < tempListCollection.size(); i++) {
		cout << tempListCollection[i]->getName() << " --- ID:  " << tempListCollection[i]->getID() << endl;
	}


	cout << "Enter the Collection ID: " << endl;
	int collectionID;
	cin >> collectionID;


	if (Helper::HelperCheckCollection(collectionID, tempListCollection)) {
		for (int i = 0; i < tempListCollection.size(); i++) {
			if (tempListCollection[i]->getID() == collectionID) {
				Collection* temp = tempListCollection[i];
				listOfSubCollection.push_back(temp);
				cout << "Add this Collection to Member Collection List" << endl;
				break;
			}
			else {
				continue;
			}
		}
	}
	else {
		cout << "No Collection match this ID" << endl;
	}

}

void Member::unSubCollection()
{
	cout << "UNSub Collection function worked------------" << endl;

	for (int i = 0; i < listOfSubCollection.size(); i++) {
		cout << listOfSubCollection[i]->getName() << " --- ID:  " << listOfSubCollection[i]->getID() << endl;
	}

	cout << "Enter the Collection ID: " << endl;
	int collectionID;
	cin >> collectionID;

	if (Helper::HelperCheckCollection(collectionID, listOfSubCollection)) {
		for (int i = 0; i < listOfSubCollection.size(); i++) {
			if (listOfSubCollection[i]->getID() == collectionID) {
				listOfSubCollection.erase(listOfSubCollection.begin() + i);
				cout << "Remove this Collection from Member Collection List" << endl;

				break;
			}
		}
	}
	else {
		cout << "No Collection match this ID" << endl;
	}
}


void Member::loginForMember(vector<Member*>& listAllAdmin, string enteredUsername, string enteredPassword)
{
	cout << "Check log in-------------------" << endl;


	for (auto& acc : listAllAdmin) {
		if (enteredUsername == acc->getUsername() && enteredPassword == acc->getPassword()) {
			cout << "Login successful!" << endl;
			return;
		}
	}

	cout << "Incorrect username or password. Please try again." << endl;
	throw 1;


}

void Member::logoutForMember()
{
	cout << "Logout Done" << endl;
}
