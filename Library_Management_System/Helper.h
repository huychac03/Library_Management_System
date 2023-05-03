#pragma once
#include <iostream>

#include "Library.h"


using namespace std;



class Helper
{
public:
	static void HelperAddABookToCollectionByBookID(int collectionID, int bookID, vector<Collection*>& tempListCollection, vector<Book*> tempListBook);

	static void HelperRemoveABookToCollectionByBookID(int collectionID, int bookID, /*Library* tempLibrary*/ vector<Collection*>& tempListCollection);

	static bool HelperCheckBook(int bookID, vector<Book*> tempListBook);

	static bool HelperCheckCollection(int collectionID, vector<Collection*> tempListCollection);



};

