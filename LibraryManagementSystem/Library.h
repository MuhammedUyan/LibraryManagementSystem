#pragma once
#include <string>
#include <vector>
#include "Book.h"
#include "User.h"

using namespace std;

class Library
{
private:
	vector<Book> books;
	vector<User> users;
	Book book1;
	User user1;

public:

	Library();

	// Kitap y�netim i�lemleri
	void addBook();
	void removeBook();
	void updateBook();
	void findBook();
	void writeBooksFile();


	// Kullan�c� y�netim i�lemleri
	void addUser();
	void removeUser();
	void updateUser();
	void findUser();
	void writeUsersFile();

	// kitaplar� ve kullan�c�lar� g�r�nt�leme
	void displayBooks();
	void displayUsers();

	//men� i�lemleri
	int menu();
};

