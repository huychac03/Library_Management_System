#pragma once
//Collection.h start here

#include<iostream>
#include<string>
#include<vector>

#include"Book.h"



using namespace std;


class Collection
{
private:
	int ID;
	std::string name;
	vector<Book*> listBook;
public:
	Collection();
	Collection(int id, std::string n);
	~Collection();
	void setID(int id);
	int getID();
	void setName(std::string n);
	string getName();
	void addBookToCollection(Book* b);
	Book* getBookFromCollection(int index);


	void displayAllBookIDInCollection();
	vector<Book*> getAllBook();


	void setListBook(vector<Book*> nListBook);


};

//Collection.h ends here