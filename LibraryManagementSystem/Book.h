#pragma once
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    int bookID;
    bool checkedOut;

public:
    Book();
    ~Book();
    Book(string title, string author, int bookID, bool checkedOut);
    void setTitle(string newTitle);
    string getTitle() const;
    void setAuthor(string newAuthor);
    string getAuthor() const;
    void setBookID(int bookId);
    int getBookID() const;
    void setCheckedOut(bool checkedOut);
    bool getCheckedOut() const;
    void setBookInfo(string title,string author,int id, bool checkedOut);
    void displayBookInfo() const;
};


