#include "Guest.h"

Guest::Guest(Collection* tempSampleCollection)
{
	string id = createID();
	User::setID(id);
	User::setAccessibilityLevel(GUEST);
	sampleCollection = tempSampleCollection;
}

Guest::~Guest()
{
}

Collection* Guest::getSampleCollection()
{
	return sampleCollection;
}

void Guest::setSampleCollection(Collection* tempSampleCollection)
{
	sampleCollection = tempSampleCollection;
	//listOfSubCollection.push_back(tempSampleCollection);
}




string Guest::createID()
{
	int numPart;
	char charPart = 'G';

	numPart = rand() % 1000 + 1000;

	string nID;

	nID.push_back(charPart);
	nID += to_string(numPart);

	return nID;
}

void Guest::Read(vector<Book*> tempListBook)
{
	cout << "List of all book in Sample Collection: " << endl;
	for (int i = 0; i < tempListBook.size(); i++) {
		cout << i + 1 << ": " << tempListBook[i]->getTitle() << endl;
	}

	cout << "Choose a book in the Sample Collection to read: " << endl;
	int opt = 0;
	cin >> opt;

	cout << "Reading 10 first pages in " << tempListBook[opt - 1]->getTitle() << endl;
}

void Guest::upgradeToMeber(vector<Member*>& memberList)
{
	string username;
	string password;
	string fullname;
	string phone;
	string memberShipDuration;

	cout << "Enter Usename: " << endl;

	cin.ignore();
	getline(std::cin, username);

	cout << "Enter Password: " << endl;
	cin >> password;

	cout << "Enter Full Name: " << endl;
	cin.ignore();
	getline(std::cin, fullname);

	cout << "Enter phone: " << endl;
	cin >> phone;

	cout << "Enter MemberShipDuration" << endl;
	cin >> memberShipDuration;

	Member* tempMember = new Member(username, password, fullname, phone, memberShipDuration, this->sampleCollection);

	memberList.push_back(tempMember);
}


