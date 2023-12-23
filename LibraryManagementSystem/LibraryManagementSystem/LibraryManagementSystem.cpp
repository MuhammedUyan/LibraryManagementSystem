#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Book {
public:
    string title;
    string author;
    int id;
    bool checkedOut;

    Book(string title, string author, int id) {
        this->title = title;
        this->author = author;
        this->id = id;
        checkedOut = false;
    }

    void displayInfo() const{
        cout << "ID: " << id << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        if (checkedOut) {
            cout << "Status: Checked Out" << endl;
        }
        else {
            cout << "Status: Available" << endl;
        }
    }
};

class User {
public:
    string name;
    int userID;

    User(string name, int userID) {
        this->name = name;
        this->userID = userID;
    }
    
    void displayInfo() const{
        cout << "Name: " << name << endl;
        cout << "UserID: " << userID << endl;
    }
};

class Library {
private:
    vector<Book> books;
    vector<User> users;
public:
    
    void addBook(string title, string author, int id) {
        books.push_back(Book(title, author, id));
    }
    
    void addUser(string name, int userID) {
        users.push_back(User(name, userID));
    }

    void displayBooks() {
        cout << "Books in the library:" <<endl;
        cout << endl;
        for (const Book& book : books) {
            book.displayInfo();
            cout << "---------------------" <<endl;
        }
    }

    void displayUsers() {
        cout << "Users in the library:" << endl;
        cout << endl;
        for (const User& user : users) {
            user.displayInfo();
            cout << "---------------------" << endl;
        }
    }

    void checkOutBook(int bookId, int userId) {
        for (Book& book : books) {
            if (book.id == bookId) {
                if (!book.checkedOut) {
                    book.checkedOut = true;
                    cout << "Book checked out successfully." << endl;
                    cout << endl;
                }
                else {
                    cout << "Book is already checked out." << endl;
                    cout << endl;
                }
                return;
            }
        }
        cout << "Book not found." << endl;
    }

};



int main()
{
    Library library;

    // add Book
    library.addBook("The Catcher in the Rye", "J.D. Salinger", 1);
    library.addBook("To Kill a Mockingbird", "Harper Lee", 2);
    library.addBook("1984", "George Orwell", 3);

    // add User
    library.addUser("Alice Johnson", 101);
    library.addUser("Bob Smith", 102);

    // display books and users
    library.displayBooks();
    cout << endl;
    library.displayUsers();
    cout << endl;

    // Checking out a book
    library.checkOutBook(1, 101);

    // Displaying books after checkout
    library.displayBooks();

    return 0;
}

