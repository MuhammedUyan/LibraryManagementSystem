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

	// Kitap yönetim iþlemleri
	void addBook();
	void removeBook();
	void updateBook();
	void findBook();
	void writeBooksFile();


	// Kullanýcý yönetim iþlemleri
	void addUser();
	void removeUser();
	void updateUser();
	void findUser();
	void writeUsersFile();

	// kitaplarý ve kullanýcýlarý görüntüleme
	void displayBooks();
	void displayUsers();

	//menü iþlemleri
	int menu();
};

