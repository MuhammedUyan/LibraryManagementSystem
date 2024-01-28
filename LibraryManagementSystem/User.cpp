#include "User.h"
#include <iostream>
#include <string>

using namespace std;

User::User() {
	name = "NONE";
	surname = "NONE";
	userID = 0;
}

User :: ~User() {

}

User :: User(string name, string surname, int userID) {
	this->name = name;
	this->userID = userID;
	this->surname = surname;
}
void User:: setName(string name) {
	this->name = name;
}
string User :: getName() const{
	return name;
}
void User::setSurname(string surname) {
	this->surname = surname;
}
string User::getSurname() const{
	return surname;
}
void User:: setUserID(int userID) {
	this->userID = userID;
}
int User :: getUserID() const {
	return userID;
}

void User::setUserInfo(string name, string surname, int id) {
	setName(name);
	setSurname(surname);
	setUserID(id);
}

void User :: displayUserInfo() const {
	cout << "\n\t Kullanici Adi    : " << getName() << endl;
	cout << "\n\t Kullanici Soyadi : " << getSurname() << endl;
	cout << "\n\t Kullanici ID     : " << getUserID() << endl;
}
