#include <iostream>
#include "Library.h"
#include"Member.h"
#include "Guest.h"
#include "Admin.h"
#include "Menu.h"

using namespace std;


// Global variable to store the currently logged in user
Member* loggedInMember = nullptr;
Admin* loggedInAdmin = nullptr;
Guest* the_guest = nullptr;


enum ACTION {
	EXIT,
	//SEARCH,
	//
	GUEST_READ,
	GUEST_UPGRADE_TO_MEM,
	GUEST_SEARCH,
	//
	MEM_LOGIN,
	MEM_LOGOUT,
	MEM_READ,
	MEM_SEARCH,
	MEM_SUB_COLLECTION,
	MEM_UNSUB_COLLECTION,
	MEM_BORROW,
	MEM_RETURN,
	//
	AD_LOGIN,
	AD_LOGOUT,
	AD_SEARCH,
	AD_ADD_NEW_BOOK,
	AD_SHOW_BOOK,
	AD_HIDE_BOOK,
	AD_REMOVE_BOOK,
	AD_EDIT_BOOK,
	AD_CREATE_COLLECTION,
	AD_REMOVE_COLLECTION,
	AD_CHANGE_COLLECTION_NAME,
	AD_ADD_BOOK_TO_COLLECTION,
	AD_REMOVE_BOOK_FROM_COLLECTION,
	AD_ADD_BOOK_TO_SAMPLE_COLLECTION,
	AD_REMOVE_BOOK_FROM_SAMPLE_COLLECTION,
};



int main()
{
	srand(time(NULL));

	//Library
	Library* lib = new Library();

	// Book
	Book* book1 = new Book(1, "The Library Book", "Susan Orlean", 336, "1476740186", "Culture", 1);
	Book* book2 = new Book(2, "Mythos", "Stephen Fry", 352, "1452178917", "Culture", 1);
	Book* book3 = new Book(3, "Midnight in Chernobyl", "Adam Higginbotham", 560, "1501134612", "Culture", 1);
	Book* book4 = new Book(4, "Blood Meridian", "Cormac McCarthy", 368, "0679728759", "Fiction", 1);
	Book* book5 = new Book(5, "Dune", "Frank Herbert", 528, "044100590X", "Fiction", 1);
	Book* book6 = new Book(6, "The Alchemist", "Paulo Coelho", 208, "0062315005", "Fiction", 1);
	Book* book7 = new Book(7, "Harry Potter and the Half-Blood Prince", "J.K. Rowling", 672, "0439784549", "Fiction", 1);
	Book* book8 = new Book(8, "A Short History of Nearly Everything", "Bill Bryson", 560, "0767908171", "Science", 1);
	Book* book9 = new Book(9, "The God Equation", "Michio Kaku", 240, "0385542747", "Science", 1);
	Book* book10 = new Book(10, "Brief Answers to the Big Questions", "Hawking Stephen", 256, "152936275X", "Science", 1);
	Book* book11 = new Book(11, "Sapiens: A Brief History of Humankind", "Yuval Noah Harari", 464, "9780062316097", "Science", 1);
	Book* book12 = new Book(12, "Ruination: A League of Legends Novel", "Anthony Reynolds", 448, "031646905X", "Fiction", 1);


	lib->addBookForLibrary(book1);
	lib->addBookForLibrary(book2);
	lib->addBookForLibrary(book3);
	lib->addBookForLibrary(book4);
	lib->addBookForLibrary(book5);
	lib->addBookForLibrary(book6);
	lib->addBookForLibrary(book7);
	lib->addBookForLibrary(book8);
	lib->addBookForLibrary(book9);
	lib->addBookForLibrary(book10);



	//Collection
	Collection* collection1 = new Collection(1, "Culture Collection");
	Collection* collection2 = new Collection(2, "Fiction Collection");
	Collection* collection3 = new Collection(3, "Science Collection");
	//Sample Collection luôn có ID là 0
	Collection* sampleCollection = new Collection(0, "Sample Collection");

	//lib


	lib->addCollectionForLibrary(sampleCollection);
	lib->addCollectionForLibrary(collection1);
	lib->addCollectionForLibrary(collection2);
	lib->addCollectionForLibrary(collection3);


	//Collection1
	collection1->addBookToCollection(book1);
	collection1->addBookToCollection(book2);
	collection1->addBookToCollection(book3);
	collection1->addBookToCollection(book4);
	collection1->addBookToCollection(book5);

	//Collection2
	collection2->addBookToCollection(book7);
	collection2->addBookToCollection(book8);
	collection2->addBookToCollection(book9);
	collection2->addBookToCollection(book10);
	collection2->addBookToCollection(book11);

	//Collection3
	collection3->addBookToCollection(book12);

	//Sample Collection
	sampleCollection->addBookToCollection(book1);
	sampleCollection->addBookToCollection(book2);
	sampleCollection->addBookToCollection(book3);




	///////////////
	vector<Book*> TheListBook = lib->getListBook();
	vector<Book*> TheListSampleBook = sampleCollection->getAllBook();
	vector<Collection*> TheCollectionList = lib->getListCollection();
	///// Viết thêm cái sách và COllection vào vector




	// User
	vector<Member*>allMember;
	vector<Admin*>allAdmin;
	vector<Guest*>allGuest;



	Member* member1 = new Member("HuyChac", "1111", "Dang Cong Huy", "0986794514", "2020 - 2026", sampleCollection);
	Member* member2 = new Member("Tuyet_Mai", "2222", "Pham Thi Tuyet Mai", "0355xxxx8888", "20023 - 2025", sampleCollection);
	Member* member3 = new Member("Quang Hoang", "3333", "Nguyen Quang Hoang", "09725435678", "2003 - 2009", sampleCollection);
	Member* member4 = new Member("John", "4444", "Join Watson", "016537486", "2289 - 2378", sampleCollection);
	Member* member5 = new Member("A", "5555", "Nguyen Van A", "0879698698", "20011 - 2019", sampleCollection);

	allMember.push_back(member1);
	allMember.push_back(member2);
	allMember.push_back(member3);
	allMember.push_back(member4);
	allMember.push_back(member5);


	Guest* guest1 = new Guest(sampleCollection);
	Guest* guest2 = new Guest(sampleCollection);
	Guest* guest3 = new Guest(sampleCollection);
	Guest* guest4 = new Guest(sampleCollection);
	Guest* guest5 = new Guest(sampleCollection);

	allGuest.push_back(guest1);
	allGuest.push_back(guest2);
	allGuest.push_back(guest3);
	allGuest.push_back(guest4);
	allGuest.push_back(guest5);




	Admin* admin1 = new Admin("root", "root", "THE_ADMIN", "11111111111");
	Admin* admin2 = new Admin("root2", "root2", "THE_ADMIN_2", "2222222222");
	Admin* admin3 = new Admin("root3", "root3", "THE_ADMIN_3", "3333333333");

	allAdmin.push_back(admin1);
	allAdmin.push_back(admin2);
	allAdmin.push_back(admin3);



	////
	lib->addUser(member1);
	lib->addUser(member2);
	lib->addUser(member3);
	lib->addUser(member4);
	lib->addUser(member5);
	lib->addUser(admin1);
	lib->addUser(admin2);
	lib->addUser(admin3);
	lib->addUser(guest1);
	lib->addUser(guest2);
	lib->addUser(guest3);
	lib->addUser(guest4);
	lib->addUser(guest5);



	////////////////////////////////////////////////////////

	 // Main
	Menu* mainMenu = new Menu("Main menu", "The main menu");


	//GUEST OR REGISTER
	Menu* guestMenu = new Menu("GUEST menu", "GUEST menu", GUEST);
	mainMenu->addSubMenu(guestMenu);
	//GUEST
	Menu* guestReadMenu = new Menu("GUEST Read menu", "Read in sample collection", GUEST_READ);
	guestMenu->addSubMenu(guestReadMenu);

	Menu* upgradeToMemberMenu = new Menu("Upgrade to Member menu", "Welcome to join the system", GUEST_UPGRADE_TO_MEM);
	guestMenu->addSubMenu(upgradeToMemberMenu);

	Menu* searchMenuGUEST = new Menu("Search menu", "Searching done", GUEST_SEARCH);
	guestMenu->addSubMenu(searchMenuGUEST);


	Menu* loginMenu = new Menu("LOGIN menu for Member and Admin", "LOGIN menu (If you choose this opt when you already login, the system will auto logout)", REGIST);
	mainMenu->addSubMenu(loginMenu);





	// MEMBER
	Menu* memberLoginMenu = new Menu("MEMBER login menu", "MEMBER login menu", MEM_LOGIN);
	loginMenu->addSubMenu(memberLoginMenu);

	Menu* memberMenu = new Menu("Member menu", "Choose something you wanna do", MEMBER);
	memberMenu->addSubMenu(memberLoginMenu);

	Menu* LogoutForMember = new Menu("LOGOUT", "Logout Menu", MEM_LOGOUT);
	memberMenu->addSubMenu(LogoutForMember);

	Menu* memReadMenu = new Menu("Member read menu", "Read worked--------------------------", MEM_READ);
	memberMenu->addSubMenu(memReadMenu);

	Menu* searchMenuMEM = new Menu("Search menu", "Searching done", MEM_SEARCH);
	memberMenu->addSubMenu(searchMenuMEM);

	Menu* subCollectionMenu = new Menu("Sub Collection Menu", "Sub Collection worked------------------------", MEM_SUB_COLLECTION);
	memberMenu->addSubMenu(subCollectionMenu);

	Menu* unSubCollectionMenu = new Menu("Un Sub Collection Menu", "Un Sub Collection worked------------------------", MEM_UNSUB_COLLECTION);
	memberMenu->addSubMenu(unSubCollectionMenu);

	Menu* borrowMenu = new Menu("Borrow Menu", "Borrow worked ----------------------", MEM_BORROW);
	memberMenu->addSubMenu(borrowMenu);

	Menu* returnMenu = new Menu("Return Menu", "Return worked ----------------------", MEM_RETURN);
	memberMenu->addSubMenu(returnMenu);




	// ADMIN
	Menu* adminLoginMenu = new Menu("ADMIN login menu", "ADMIN login menu", AD_LOGIN);
	loginMenu->addSubMenu(adminLoginMenu);

	Menu* adminMenu = new Menu("Admin menu", "Choose something you wanna do", ADMIN);
	adminMenu->addSubMenu(adminLoginMenu);

	Menu* LogoutForAdmin = new Menu("LOGOUT", "Logout Menu", AD_LOGOUT);
	adminMenu->addSubMenu(LogoutForAdmin);

	Menu* searchMenuADMIN = new Menu("Search menu", "Searching done", AD_SEARCH);
	adminMenu->addSubMenu(searchMenuADMIN);

	Menu* addNewBookMenu = new Menu("Add New book Menu", "Just add a new book to the system", AD_ADD_NEW_BOOK);
	adminMenu->addSubMenu(addNewBookMenu);

	Menu* hideBookMenu = new Menu("Hide a book Menu", "Just hire a new book in the system", AD_HIDE_BOOK);
	adminMenu->addSubMenu(hideBookMenu);

	Menu* showBookMenu = new Menu("Show a book Menu", "Just show a new book in the system", AD_SHOW_BOOK);
	adminMenu->addSubMenu(showBookMenu);

	Menu* removeBookMenu = new Menu("Remove a book Menu", "Just remove a new book in the system", AD_REMOVE_BOOK);
	adminMenu->addSubMenu(removeBookMenu);

	Menu* editBookMenu = new Menu("Edit a book Menu", "Just edit a new book in the system", AD_EDIT_BOOK);
	adminMenu->addSubMenu(editBookMenu);

	Menu* createCollectionMenu = new Menu("Create a collection Menu", "Just create a new collection in the system", AD_CREATE_COLLECTION);
	adminMenu->addSubMenu(createCollectionMenu);

	Menu* removeCollectionMenu = new Menu("Remove a collection Menu", "Just remove a new collection in the system", AD_REMOVE_COLLECTION);
	adminMenu->addSubMenu(removeCollectionMenu);

	Menu* changeCollectionNameMenu = new Menu("Change a collection's name Menu", "Just Change a collection's name in the system", AD_CHANGE_COLLECTION_NAME);
	adminMenu->addSubMenu(changeCollectionNameMenu);

	Menu* addBook2CollectionMenu = new Menu("Add Book 2 collection Menu", "Just add a new book to collection in the system", AD_ADD_BOOK_TO_COLLECTION);
	adminMenu->addSubMenu(addBook2CollectionMenu);

	Menu* removeBookFromCollectionMenu = new Menu("Remove book from collection Menu", "Just remove a book from collection in the system", AD_REMOVE_BOOK_FROM_COLLECTION);
	adminMenu->addSubMenu(removeBookFromCollectionMenu);

	Menu* addBook2SampleCollectionMenu = new Menu("Add Book 2 sample collection Menu", "Just add a new book to Sample collection in the system", AD_ADD_BOOK_TO_SAMPLE_COLLECTION);
	adminMenu->addSubMenu(addBook2SampleCollectionMenu);

	Menu* removeBookFromSampleCollectionMenu = new Menu("Remove book from Sample collection Menu", "Just remove a book from Sample collection in the system", AD_REMOVE_BOOK_FROM_SAMPLE_COLLECTION);
	adminMenu->addSubMenu(removeBookFromSampleCollectionMenu);











	//EXIT
	Menu* exitMenu = new Menu("Exit", "Exit the program", EXIT);
	mainMenu->addSubMenu(exitMenu);
	guestMenu->addSubMenu(exitMenu);
	memberLoginMenu->addSubMenu(exitMenu);
	adminLoginMenu->addSubMenu(exitMenu);
	loginMenu->addSubMenu(exitMenu);
	LogoutForMember->addSubMenu(exitMenu);
	guestReadMenu->addSubMenu(exitMenu);
	searchMenuGUEST->addSubMenu(exitMenu);
	upgradeToMemberMenu->addSubMenu(exitMenu);
	memReadMenu->addSubMenu(exitMenu);
	memberMenu->addSubMenu(exitMenu);
	searchMenuMEM->addSubMenu(exitMenu);
	subCollectionMenu->addSubMenu(exitMenu);
	unSubCollectionMenu->addSubMenu(exitMenu);
	borrowMenu->addSubMenu(exitMenu);
	returnMenu->addSubMenu(exitMenu);
	adminMenu->addSubMenu(exitMenu);
	LogoutForAdmin->addSubMenu(exitMenu);
	searchMenuADMIN->addSubMenu(exitMenu);
	addNewBookMenu->addSubMenu(exitMenu);
	hideBookMenu->addSubMenu(exitMenu);
	removeBookMenu->addSubMenu(exitMenu);
	editBookMenu->addSubMenu(exitMenu);
	createCollectionMenu->addSubMenu(exitMenu);
	removeCollectionMenu->addSubMenu(exitMenu);
	changeCollectionNameMenu->addSubMenu(exitMenu);
	addBook2CollectionMenu->addSubMenu(exitMenu);
	removeBookFromCollectionMenu->addSubMenu(exitMenu);
	addBook2SampleCollectionMenu->addSubMenu(exitMenu);
	removeBookFromSampleCollectionMenu->addSubMenu(exitMenu);
	showBookMenu->addSubMenu(exitMenu);





	


	////////////////////////////////////////////////////////////////
	the_guest = new Guest(sampleCollection);



	cout << "---------------------------------------------------------------------" << endl;






	Menu* currentMenu = mainMenu;
	while (true) {

		currentMenu->displayMenu();

		int opt = currentMenu->pickOption();

		currentMenu = currentMenu->getSubMenu(opt - 1);
		switch (currentMenu->getAction()) {
		case -1: {
			break;
		}

		case REGIST: {
			the_guest = new Guest(sampleCollection);

			break;
		}
		case GUEST: {
			//the_guest = new Guest();
			cout << "Your GUEST_ID is: " << the_guest->getID() << endl;
			lib->addUser(the_guest);

			break;
		}
		case GUEST_SEARCH: {
			the_guest->Search(lib->getListBook());
			break;
		}
		case GUEST_READ: {		
			//the_guest->Read(lib->getSampleCollection()->getAllBook());
			the_guest->Read(lib->getListCollection()[0]->getAllBook());
			break;
		}
		case GUEST_UPGRADE_TO_MEM: {
			the_guest->upgradeToMeber(allMember);
			for (int i = 0; i < allMember.size(); i++) {
				cout << allMember[i]->getFullname() << endl;
			}
			break;
		}
		case MEM_LOGIN: {
			loggedInMember = nullptr;

			// Login for Member
			while (true) {
				try {
					string enteredUsername, enteredPassword;

					cout << "Enter Member username: ";
					cin >> enteredUsername;

					cout << "Enter Member password: ";
					cin >> enteredPassword;
					loggedInMember->loginForMember(allMember, enteredUsername, enteredPassword);

					for (int i = 0; i < allMember.size(); i++) {
						if (enteredPassword == allMember[i]->getPassword()) {
							loggedInMember = allMember[i];
							break;
						}
					}
					cout << "You are logging as: " << loggedInMember->getFullname() << endl;
					break;
				}
				catch (int ex) {
					cout << "Do it again ???" << endl;
					int opt = 0;

					cout << "0. No" << endl;
					cout << "1. Yes" << endl;

					cout << "Enter ur option " << endl;
					cin >> opt;

					if (opt == 0) {
						currentMenu = currentMenu->getSubMenu(0);

						break;
					}
					else {
						continue;
					}
				}

			}



			break;
		}
		case MEM_LOGOUT: {
			loggedInMember->logoutForMember();
			loggedInMember = nullptr;
			currentMenu = currentMenu->getSubMenu(2 - 1)->getSubMenu(5 - 1);

			break;
		}
		case MEM_READ: {
			loggedInMember->Read(lib->getListBook());
			break;
		}
		case MEM_SEARCH: {
			loggedInMember->Search(lib->getListBook());
			break;
		}
		case MEM_SUB_COLLECTION: {
			//-------------------------------------------------------------------------------
			loggedInMember->subCollection(lib->getListCollection());
			break;
		}
		case MEM_UNSUB_COLLECTION: {
			loggedInMember->unSubCollection();
			break;
		}
		case MEM_BORROW: {
			loggedInMember->borrowBook(lib->getListBook());
			break;
		}
		case MEM_RETURN: {
			loggedInMember->returnBook();
			break;
		}
		case AD_LOGIN: {
			// Login for ADMIN
			loggedInAdmin = nullptr;

			while (true) {
				try {
					string enteredUsername, enteredPassword;

					cout << "Enter Admin username: ";
					cin >> enteredUsername;

					cout << "Enter Amin password: ";
					cin >> enteredPassword;
					loggedInAdmin->loginForAdmin(allAdmin, enteredUsername, enteredPassword);

					for (int i = 0; i < allAdmin.size(); i++) {
						if (enteredPassword == allAdmin[i]->getPassword()) {
							loggedInAdmin = allAdmin[i];
							break;
						}
					}
					cout << "You are logging as: " << loggedInAdmin->getFullname() << endl;
					break;

				}
				catch (int ex) {
					cout << "Do it again ???" << endl;
					int opt = 0;

					cout << "0. No" << endl;
					cout << "1. Yes" << endl;

					cout << "Enter ur option " << endl;
					cin >> opt;

					if (opt == 0) {
						currentMenu = currentMenu->getSubMenu(0);
						break;


					}
					else {
						continue;
					}
				}

			}
			break;
		}
		case AD_LOGOUT: {
			loggedInAdmin->logoutForAdmin();
			loggedInAdmin = nullptr;
			currentMenu = currentMenu->getSubMenu(2 - 1)->getSubMenu(5 - 1);
			break;
		}
		case AD_SEARCH: {
			loggedInAdmin->Search(lib->getListBook());
			break;
		}
		case AD_ADD_NEW_BOOK: {
			loggedInAdmin->addNewBook(lib);
			break;
		}
		case AD_SHOW_BOOK: {
			loggedInAdmin->showABookByID(lib);
			break;
		}
		case AD_HIDE_BOOK: {
			loggedInAdmin->hideABookByID(lib);
			break;
		}
		case AD_REMOVE_BOOK: {
			loggedInAdmin->removeABookByID(lib);
			break;
		}
		case AD_EDIT_BOOK: {
			loggedInAdmin->editABookByID(lib);
			break;
		}
		case AD_CREATE_COLLECTION: {
			loggedInAdmin->createCollection(lib);
			break;
		}
		case AD_REMOVE_COLLECTION: {
			loggedInAdmin->removeCollectionByID(lib);
			break;
		}
		case AD_CHANGE_COLLECTION_NAME: {
			loggedInAdmin->changeCollectionName(lib);
			break;
		}
		case AD_ADD_BOOK_TO_COLLECTION: {
			loggedInAdmin->addBookToCollection(lib);
			break;
		}
		case AD_REMOVE_BOOK_FROM_COLLECTION: {
			loggedInAdmin->removeBookFromCollection(lib);
			break;
		}
		case AD_ADD_BOOK_TO_SAMPLE_COLLECTION: {
			loggedInAdmin->addBookToSampleCollection(lib);
			break;
		}
		case AD_REMOVE_BOOK_FROM_SAMPLE_COLLECTION: {
			loggedInAdmin->removeBookFromSampleCollection(lib);
			break;
		}
		case EXIT:
			exit(0);
			break;
		}
	}



	return 0;
}