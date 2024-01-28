#include "Book.h"
#include <iostream>
#include <string>

using namespace std;


Book :: Book() {
	title = "NONE";
	author = "NONE";
	bookID = 0;
	checkedOut = false;
}
Book :: ~Book() {

}
Book :: Book(string title, string author, int bookID, bool checkedOut) {
	this->title = title;
	this->author = author;
	this->bookID = bookID;
	this->checkedOut = checkedOut;
}
void Book::setTitle(string title) {
	this->title = title;
}
string Book::getTitle() const{
	return title;
}
void Book::setAuthor(string author) {
	this->author = author;
}
string Book::getAuthor() const{
	return author;
}
void Book::setBookID(int bookID) {
	this->bookID = bookID;
}
int Book::getBookID() const{
	return bookID;
}
void Book:: setCheckedOut(bool checkedOut) {
	this->checkedOut = checkedOut;
}
bool Book::getCheckedOut() const {
	return checkedOut;
}
void Book::setBookInfo(string title, string author, int id, bool checkedOut) {
	setTitle(title);
	setAuthor(author);
	setBookID(id);
	setCheckedOut(checkedOut);
}
void Book::displayBookInfo() const{
	cout << "\n\t Kitap Basligi                             :" << getTitle() << endl;
	cout << "\n\t Kitap Yazari                              :" << getAuthor() << endl;
	cout << "\n\t Kitap ID                                  :" << getBookID() << endl;
	cout << "\n\t Kitap odunc alindi mi?(1: Evet, 0: Hayir) :" << getCheckedOut() << endl;
}

