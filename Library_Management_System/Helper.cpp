#include "Helper.h"

void Helper::HelperAddABookToCollectionByBookID(int collectionID, int bookID, vector<Collection*>& tempListCollection, vector<Book*> tempListBook)
{
	if (Helper::HelperCheckCollection(collectionID, tempListCollection) && Helper::HelperCheckBook(bookID, tempListBook)) {
		Book* tempBook = tempListBook[0];
		for (int i = 0; i < tempListBook.size(); i++) {
			if (bookID == tempListBook[i]->getID()) {
				tempBook = tempListBook[i];
			}
		}
		for (int i = 0; i < tempListCollection.size(); i++) {
			if (collectionID == tempListCollection[i]->getID()) {

				tempListCollection[i]->addBookToCollection(tempBook);
				break;
			}
		}
	}
	else {
		cout << "No Book or No Collection match this ID" << endl;
	}
}

void Helper::HelperRemoveABookToCollectionByBookID(int collectionID, int bookID, /*Library* tempLibrary*/ vector<Collection*>& tempListCollection)
{

	if (Helper::HelperCheckCollection(collectionID, tempListCollection)) {
		for (int i = 0; i < tempListCollection.size(); i++) {
			if (collectionID == tempListCollection[i]->getID()) {
				tempListCollection[i]->displayAllBookIDInCollection();
				vector<Book*> tempListBook = tempListCollection[i]->getAllBook();



				for (int j = 0; j < tempListBook.size(); j++) {
					if (bookID == tempListBook[j]->getID()) {
						tempListBook.erase(tempListBook.begin() + 1);

						

						tempListCollection[i]->setListBook(tempListBook);
						break;
					}
				}
				tempListCollection[i]->displayAllBookIDInCollection();
			}


		}
	}
	else {
		cout << "No Collection match this ID" << endl;

	}
}

bool Helper::HelperCheckBook(int bookID, vector<Book*> tempListBook)
{
	for (int i = 0; i < tempListBook.size(); i++) {
		if (tempListBook[i]->getID() == bookID) {
			return true;
		}
		else {
			continue;
		}
	}
	return false;
}

bool Helper::HelperCheckCollection(int collectionID, vector<Collection*> tempListCollection)
{
	for (int i = 0; i < tempListCollection.size(); i++) {
		if (tempListCollection[i]->getID() == collectionID) {
			return true;
		}
		else {
			continue;
		}
	}
	return false;
}
