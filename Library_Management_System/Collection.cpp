//Collection.cpp start here
#include "Collection.h"

Collection::Collection()
{
	this->ID = 0;
	this->name = "";
	this->listBook.clear();
}

Collection::Collection(int id, std::string n)
{
	this->ID = id;
	this->name = n;
	this->listBook.clear();
}

Collection::~Collection()
{
	ID = 0;
	name = "";
	if (listBook.size() > 0) {
		for (int i = 0; i < listBook.size(); i++) {
			if (listBook[i]) delete listBook[i];
		}
	}

}

void Collection::setID(int id)
{
	ID = id;
}

int Collection::getID()
{
	return ID;
}

void Collection::setName(std::string n)
{
	name = n;
}

std::string Collection::getName()
{
	return name;
}

void Collection::addBookToCollection(Book* b)
{
	if (b->getVisibility() == true) {
		this->listBook.push_back(b);

	}
}

Book* Collection::getBookFromCollection(int index)
{
	return listBook[index];
}






void Collection::displayAllBookIDInCollection()
{
	cout << "List of all book in this Collection: " << endl;
	for (int i = 0; i < listBook.size(); i++) {
		if (listBook[i]->getVisibility() == true) {
			std::cout << i + 1 << ": " << listBook[i]->getID() << endl;
		}		
	}
}
vector<Book*> Collection::getAllBook()
{
	return listBook;
}

void Collection::setListBook(vector<Book*> nListBook)
{
	listBook = nListBook;
}
//Collection.cpp end here