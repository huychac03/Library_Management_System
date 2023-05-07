
#include "Book.h"

Book::Book()
{
	this->ID = 0;
	this->title = "";
	this->author = "";
	this->pageCount = 0;
	this->serialNumber = "";
	this->category = "";
	this->visibility = 1;
}

Book::Book(int id, std::string t, std::string a, int p, std::string s, std::string c, bool v)
{
	this->ID = id;
	this->title = t;
	this->author = a;
	this->pageCount = p;
	this->serialNumber = s;
	this->category = c;
	this->visibility = v;
}

void Book::setID(int id)
{
	this->ID = id;
}

int Book::getID()
{
	return ID;
}

void Book::setTitle(std::string t)
{
	this->title = t;
}

std::string Book::getTitle()
{
	return title;
}

void Book::setAuthor(std::string a)
{
	this->author = a;
}

std::string Book::getAuthor()
{
	return author;
}

void Book::setPageCount(int pC)
{
	this->pageCount = pC;
}

int Book::getPageCount()
{
	return pageCount;
}

void Book::setSerialNumber(std::string sN)
{
	this->serialNumber = sN;
}

std::string Book::getSerialNumber()
{
	return serialNumber;
}

void Book::setCategory(std::string c)
{
	this->category = c;
}

std::string Book::getCategory()
{
	return category;
}

void Book::setVisibility(bool v)
{
	this->visibility = v;
}

bool Book::getVisibility()
{
	return visibility;
}

void Book::showAllInfor() const
{
	std::cout << "\t\t\t\t" << this->ID << "\n";
	std::cout << "\t\t\t\tTitle: " << this->title << "\n";
	std::cout << "\t\t\t\tAuthor: " << this->author << "\n";
	std::cout << "\t\t\t\tPage Count: " << this->pageCount << "\n";
	std::cout << "\t\t\t\tSerialNumber: " << this->serialNumber << "\n";
	std::cout << "\t\t\t\tCatagory: " << this->category << "\n";
}

std::ostream& operator<<(std::ostream& out, const Book& b)
{
	b.showAllInfor();
	return out;
}
