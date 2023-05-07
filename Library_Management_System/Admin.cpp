#include "Admin.h"

Admin::Admin() :RegisteredUser()
{
	User::setAccessibilityLevel(ADMIN);
}

Admin::Admin(string nUsername, string nPass, string nFullname, string nPhone) :RegisteredUser(nUsername, nPass, nFullname, nPhone)
{
	User::setAccessibilityLevel(ADMIN);
}

Admin::~Admin()
{
}

void Admin::addNewBook(Library* tempLibrary)
{
	tempLibrary->addBook();

}

void Admin::showABookByID(Library* tempLibrary)
{
	cout << "Show a book-----------------------" << endl;
	cout << "Enter the BookID: " << endl;
	int bookID;
	cin >> bookID;

	vector<Book*> tempListBook = tempLibrary->getListBook();
	if (Helper::HelperCheckBook(bookID, tempListBook)) {
		for (int i = 0; i < tempListBook.size(); i++) {
			if (tempListBook[i]->getID() == bookID) {
				tempListBook[i]->setVisibility(true);
				break;
			}
			else {
				continue;
			}
		}
	}
	else {
		cout << "No Book match this ID" << endl;
	}
	tempLibrary->updateListBook(tempListBook);

}

void Admin::hideABookByID(Library* tempLibrary)
{
	cout << "Hide a book-----------------------" << endl;
	cout << "Enter the BookID: " << endl;
	int bookID;
	cin >> bookID;

	vector<Book*> tempListBook = tempLibrary->getListBook();
	if (Helper::HelperCheckBook(bookID, tempListBook)) {
		for (int i = 0; i < tempListBook.size(); i++) {
			if (tempListBook[i]->getID() == bookID) {
				tempListBook[i]->setVisibility(false);
				break;
			}
			else {
				continue;
			}
		}
	}
	else {
		cout << "No Book match this ID" << endl;
	}
	tempLibrary->updateListBook(tempListBook);
}

void Admin::removeABookByID(Library* tempLibrary)
{
	cout << "Remove a book-----------------------" << endl;
	cout << "Enter the BookID: " << endl;
	int bookID;
	cin >> bookID;

	vector<Book*> tempListBook = tempLibrary->getListBook();

	if (Helper::HelperCheckBook(bookID, tempListBook)) {

		for (int i = 0; i < tempListBook.size(); i++) {
			if (tempListBook[i]->getID() == bookID) {
				tempListBook.erase(tempListBook.begin() + i);
				break;
			}
			else {
				continue;
			}
		}
		tempLibrary->updateListBook(tempListBook);
		cout << "REMOVED" << endl;
	}
	else {
		cout << "No Book match this ID" << endl;
	}
}

void Admin::editABookByID(Library* tempLibrary)
{
	cout << "Edit a book-----------------------" << endl;

	cout << "Enter the BookID: " << endl;
	int bookID;
	cin >> bookID;

	vector<Book*> tempListBook = tempLibrary->getListBook();

	if (Helper::HelperCheckBook(bookID, tempListBook)) {

		for (int i = 0; i < tempListBook.size(); i++) {
			if (bookID == tempListBook[i]->getID()) {
				std::string title;
				std::string author;
				int pageCount;
				std::string serialNumber;
				std::string category;

				cout << "Enter new title: ";
				cin >> title;
				tempListBook[i]->setTitle(title);

				cout << "Enter new author: ";
				cin >> author;
				tempListBook[i]->setAuthor(author);

				cout << "Enter new pageCount: ";
				cin >> pageCount;
				tempListBook[i]->setPageCount(pageCount);

				cout << "Enter new serialNumber: ";
				cin >> serialNumber;
				tempListBook[i]->setSerialNumber(serialNumber);

				cout << "Enter new category: ";
				cin >> category;
				tempListBook[i]->setCategory(category);

				break;
			}
		}

	}
	else {
		cout << "No Book match this ID" << endl;
	}
	tempLibrary->updateListBook(tempListBook);
}

void Admin::createCollection(Library* tempLibrary)
{
	tempLibrary->addCollection();

}


void Admin::removeCollectionByID(Library* tempLibrary)
{
	cout << "Remove Collection-----------------------" << endl;

	cout << "Enter the Collection ID: " << endl;
	int collectionID;
	cin >> collectionID;

	if (collectionID == 0) {
		cout << "You can not remove Sample Collection" << endl;
	}
	else {
		vector<Collection*> tempListCollection = tempLibrary->getListCollection();

		if (Helper::HelperCheckCollection(collectionID, tempListCollection)) {
			for (int i = 0; i < tempListCollection.size(); i++) {
				if (collectionID == tempListCollection[i]->getID()) {
					tempListCollection.erase(tempListCollection.begin() + i);
					break;
				}
			}
		}
		else {
			cout << "No Collection match this ID" << endl;
		}

		tempLibrary->updateListColletion(tempListCollection);
	}
}


void Admin::changeCollectionName(Library* tempLibrary)
{
	cout << "Change Collection Name-----------------------" << endl;
	vector<Collection*> tempListCollection = tempLibrary->getListCollection();


	cout << "Enter the Collection ID: " << endl;
	int collectionID;
	cin >> collectionID;

	if (Helper::HelperCheckCollection(collectionID, tempListCollection)) {
		string newCollectionName;
		cout << "Enter new collection name" << endl;
		cin >> newCollectionName;
		for (int i = 0; i < tempListCollection.size(); i++) {
			if (collectionID == tempListCollection[i]->getID()) {
				tempListCollection[i]->setName(newCollectionName);
				break;
			}
		}
	}
	else {
		cout << "No Collection match this ID" << endl;
	}
	tempLibrary->updateListColletion(tempListCollection);
}

void Admin::addBookToCollection(Library* tempLibrary) {
	cout << "Add Book To Collection-----------------------" << endl;

	vector<Book*> tempListBook = tempLibrary->getListBook();
	vector<Collection*> tempListCollection = tempLibrary->getListCollection();


	cout << "Enter the Collection ID: " << endl;
	int collectionID;
	cin >> collectionID;

	cout << "Enter the BookID: " << endl;
	int bookID;
	cin >> bookID;

	Helper::HelperAddABookToCollectionByBookID(collectionID, bookID, tempListCollection, tempListBook);

	tempLibrary->updateListColletion(tempListCollection);

}

void Admin::removeBookFromCollection(Library* tempLibrary)
{
	cout << "Remove Book From Collection-----------------------" << endl;
	cout << "Enter the Collection ID: " << endl;
	vector<Collection*> tempListCollection = tempLibrary->getListCollection();

	int collectionID;
	cin >> collectionID;

	cout << "Enter the BookID: " << endl;
	int bookID;
	cin >> bookID;
	Helper::HelperRemoveABookToCollectionByBookID(collectionID, bookID, tempListCollection);

	tempLibrary->updateListColletion(tempListCollection);

}

void Admin::addBookToSampleCollection(Library* tempLibrary)
{
	cout << "Add Book To Sample Collection-----------------------" << endl;

	vector<Book*> tempListBook = tempLibrary->getListBook();
	vector<Collection*> tempListCollection = tempLibrary->getListCollection();


	cout << "Enter the BookID: " << endl;
	int bookID;
	cin >> bookID;

	Helper::HelperAddABookToCollectionByBookID(0, bookID, tempListCollection, tempListBook);

	tempLibrary->updateListColletion(tempListCollection);

}

void Admin::removeBookFromSampleCollection(Library* tempLibrary)
{
	cout << "Remove Book From Sample Collection-----------------------" << endl;
	vector<Collection*> tempListCollection = tempLibrary->getListCollection();

	cout << "Enter the BookID: " << endl;
	int bookID;
	cin >> bookID;
	Helper::HelperRemoveABookToCollectionByBookID(0, bookID, tempListCollection);
	tempLibrary->updateListColletion(tempLibrary->getListCollection());
	tempLibrary->getListCollection()[0]->displayAllBookIDInCollection();
}

void Admin::loginForAdmin(vector<Admin*> tempListAdmin, string enteredUsername, string enteredPassword)
{
	cout << "Check log in-------------------" << endl;


	for (auto& acc : tempListAdmin) {
		if (enteredUsername == acc->getUsername() && enteredPassword == acc->getPassword()) {
			cout << "Login successful!" << endl;
			return;
		}
	}

	cout << "Incorrect username or password. Please try again." << endl;
	throw 1;


}

void Admin::logoutForAdmin()
{
	cout << "LOGOUT DONE" << endl;
}
