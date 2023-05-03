//Library.cpp start here
#include "Library.h"

Library::Library()
{
	listBook.clear();
	listCollection.clear();
	listUser.clear();
}

Library::~Library()
{
	if (listBook.size() > 0) {
		for (int i = 0; i < listBook.size(); i++) {
			if (listBook[i]) delete listBook[i];
		}
	}
	listBook.clear();

	if (listCollection.size() > 0) {
		for (int i = 0; i < listCollection.size(); i++) {
			if (listCollection[i]) delete listCollection[i];
		}
	}
	listCollection.clear();

	if (listUser.size() > 0) {
		for (int i = 0; i < listUser.size(); i++) {
			if (listUser[i]) delete listUser[i];
		}
	}
	listUser.clear();	
}



void Library::addBook()
{
	int tID;
	string tTitle;
	string tAuthor;
	int tPageCount;
	string tSerialNumber;
	string tCategory;
	bool tVisibility = 1;
	cout << "Enter book details:\n";
	cout << "ID: ";
	cin >> tID;
	cout << "Title: ";
	cin.ignore();
	getline(std::cin, tTitle);
	cout << "Author: ";
	getline(std::cin, tAuthor);
	cout << "Page count: ";
	cin >> tPageCount;
	cout << "Serial number: ";
	cin.ignore();
	getline(std::cin, tSerialNumber);
	cout << "Category: ";
	getline(std::cin, tCategory);
	Book* tempBook = new Book(tID, tTitle, tAuthor, tPageCount, tSerialNumber, tCategory, tVisibility);
	listBook.push_back(tempBook);
}

Book* Library::getBook(int index)
{
	return listBook[index];
}

void Library::addUser(User* u)
{
	this->listUser.push_back(u);
}


User* Library::getUser(int index)
{
	return listUser[index];
}



void Library::addCollection()
{
	int tID;
	string tName;
	cout << "Enter book details:\n";
	cout << "ID: ";
	cin >> tID;
	cout << "Name: ";
	cin.ignore();
	getline(std::cin, tName);
	Collection* tempCollection = new Collection(tID, tName);
	listCollection.push_back(tempCollection);
}

Collection* Library::getCollection(int index)
{
	return listCollection[index];
}

void Library::showAllBook()
{
	if (listBook.size() > 0) {
		for (int i = 0; i < listBook.size(); i++) {
			std::cout << i + 1 << ". " << *(listBook[i]);

		}
	}
}
vector<Book*> Library::getListBook()
{
	return listBook;
}
vector<Collection*> Library::getListCollection()
{
	return listCollection;
}


void Library::addBookForLibrary(Book* b)
{
	listBook.push_back(b);
}

void Library::addCollectionForLibrary(Collection* c)
{
	listCollection.push_back(c);
}


void Library::updateListColletion(std::vector<Collection*> newList)
{
	listCollection = newList;
}


//Library.cpp ends here