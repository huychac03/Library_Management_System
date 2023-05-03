#pragma once
#include<iostream>
#include<string>

using namespace std;
class Book
{
private:
	int ID;
	std::string title;
	std::string author;
	int pageCount;
	std::string serialNumber;
	std::string category;
	bool visibility; // true sẽ là hiển thị
public:
	Book();
	Book(int id, std::string t, std::string a, int p, std::string s, std::string c, bool v);
	void setID(int id);
	int getID();
	void setTitle(std::string t);
	std::string getTitle();
	void setAuthor(std::string a);
	std::string getAuthor();
	void setPageCount(int pC);
	int getPageCount();
	void setSerialNumber(std::string sN);
	std::string getSerialNumber();
	void setCategory(std::string c);
	std::string getCategory();
	void setVisibility(bool v);
	bool getVisibility();
	void showAllInfor() const;
	friend std::ostream& operator<<(std::ostream&, const Book&);
};
