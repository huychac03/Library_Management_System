#pragma once
#include <iostream>
#include <string>
#include "Member.h"


using namespace std;



class Collection;

class Guest : public User
{
private:
	Collection* sampleCollection;
public:
	Guest(Collection* tempSampleCollection);
	~Guest();

	Collection* getSampleCollection();
	void setSampleCollection(Collection* tempSampleCollection);


	string createID() override; // ID của Guest sẽ bắt đầu bằng T

	void Read(vector<Book*> tempListBook) override;

	void upgradeToMeber(vector<Member*>& memberList);


};

