#pragma once
#include<iostream>
#include<string>
#include<vector>


#include"Book.h"
#include"Collection.h"


class User;

using namespace std;

class Library
{
private:
	std::vector<Book*> listBook;
	std::vector<User*> listUser;
	// Sample Collection chính là Collection ở Index 0 trong listCollection
	std::vector<Collection*> listCollection;


public:
	Library();
	~Library();
	void addBook();
	Book* getBook(int index);
	void addUser(User* u);
	User* getUser(int index);
	void addCollection();
	Collection* getCollection(int index);
	void showAllBook();

	void addBookForLibrary(Book* b);

	void addCollectionForLibrary(Collection* c);


	vector<Book*> getListBook();
	void updateListBook(std::vector<Book*> newList) {
		listBook = newList;
	}

	vector<Collection*> getListCollection();
	void updateListColletion(std::vector<Collection*> newList);







};
