#pragma once
#include <string>

using namespace std;

class User
{
private:
	string name, surname;
	int userID;

public:
	~User();
	User();
	User(string name, string surname, int userID);
	void setName(string name);
	string getName() const;
	void setSurname(string surname);
	string getSurname() const;
	void setUserID(int userID);
	int getUserID() const;
	void setUserInfo(string name, string surname, int id);
	void displayUserInfo() const;
};

