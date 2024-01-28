#include "Library.h"
#include "Book.h"
#include "User.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
#include <fstream>

using namespace std;

Library :: Library() {
    ifstream readData("Books.txt");

    if (!readData.is_open()) {
        cerr << "Dosya acilamadi !!!" << endl;
        return;
    }

    string title, author;
    int id;
    bool checkedOut;

    books.clear();

    while (readData >> title >> author >> id >> checkedOut) {
        books.push_back(Book(title, author, id, checkedOut));
    }
}

// Kitap yönetim iþlemleri
void Library::addBook() {
    system("cls");

    ofstream writeData("Books.txt", ios::app);

    if (!writeData.is_open()) {
        cerr << "Dosya acilamadi !!!" << endl;
        return;
    }

    string title;
    string author;
    int id;
    bool checkedOut;

    cout << "\n\t Eklemek istediginiz kitabin bilgilerini girin: " << endl << endl;
    cout << "\n\t Kitabin Basligi                          : "; cin >> title;
    cout << "\n\t Kitabin Yazari                           : "; cin >> author;
    cout << "\n\t Kitap ID                                 : "; cin >> id;
    cout << "\n\t Kitap odunc alindi mi?(1: Evet, 0: Hayir): "; cin >> checkedOut;
	books.push_back(Book(title, author, id, checkedOut));

    writeData << title << endl;
    writeData << author << endl;
    writeData << id << endl;
    writeData << checkedOut << endl;
    writeData << endl;

	cout << "\n\t Kitap basariyla eklendi !" << endl;

    writeData.close();
}
void Library::removeBook() {
    system("cls");
    int bookID;
    cout << "\n\t Kaldirmak istediginiz kitabin ID: ";
    cin >> bookID;
    auto it = remove_if(books.begin(), books.end(), [bookID](const Book& book) {
        return book.getBookID() == bookID;
        });

    if (it != books.end()) {
        books.erase(it, books.end());
        cout << "\n\t Kitap kutuphaneden kaldirildi !" << endl;
    }
    else {
        cout << "\n\t Kitap bulunamadi ! " << endl;
    }
    writeBooksFile();
    system("pause");
}
void Library::updateBook() {
    system("cls");
    int bookID;
    cout << "\n\t Guncellemek istediginiz kitabin ID: ";
    cin >> bookID;

    auto it = find_if(books.begin(), books.end(), [bookID](const Book& book) {
        return book.getBookID() == bookID;
        });

    if (it != books.end()) {
        string title, author;
        int id;
        bool checkedOut;

        cout << "\n\t Yeni kitap bilgilerini girin " << endl << endl;
        cout << "\n\t Kitabin Basligi                          : "; cin >> title;
        cout << "\n\t Kitabin Yazari                           : "; cin >> author;
        cout << "\n\t Kitap ID                                 : "; cin >> id;
        cout << "\n\t Kitap odunc alindi mi?(1: Evet, 0: Hayir): "; cin >> checkedOut;

        it->setBookInfo(title, author, id, checkedOut);
        cout << "\n\t Kitap bilgileri guncellendi." << endl;
    }
    else {
        cout << "\n\t Kitap bulunamadi ! " << endl;
    }
    writeBooksFile();
    system("pause");
}
void Library::findBook() {
    system("cls");

    if (books.empty()) {
        cout << "\n\t Kitap listesi boþ ! " << endl;
    }

    int bookID;
    cout << "\n\t Aramak istediginiz kitabin ID: ";
    cin >> bookID;

    auto it = find_if(books.begin(), books.end(), [bookID](const Book& book) {
        return book.getBookID() == bookID;
        });

    if (it != books.end()) {
        it->displayBookInfo();
    }
    else {
        cout << "\n\t Kitap bulunamadi ! " << endl;
    }
    system("pause");
}

void Library ::  writeBooksFile() {
    ofstream writeData("Books.txt");

    if (!writeData.is_open()) {
        cerr << "Dosya acilamadi !!!" << endl;
        return;
    }

    for (const auto& book1 : books) {
        writeData << book1.getTitle() << endl;
        writeData << book1.getAuthor() << endl;
        writeData << book1.getBookID() << endl;
        writeData << book1.getCheckedOut() << endl;
        writeData << endl;
    }

}


// Kullanýcý yönetim iþlemleri
void Library::addUser() {
    system("cls");

    ofstream writeData("Users.txt", ios::app);

    if (!writeData.is_open()) {
        cerr << "Dosya acilamadi !!!" << endl;
        return;
    }

    string name;
    string surname;
    int userID;

    cout << "\n\t Eklemek istediginiz kitabin bilgilerini girin: " << endl << endl;
    cout << "\n\t Kullanici Adi    : "; cin >> name;
    cout << "\n\t kullanici Soyadi : "; cin >> surname;
    cout << "\n\t Kullanici ID     : "; cin >> userID;

    users.push_back(User(name, surname, userID));

    writeData << name << endl;
    writeData << surname << endl;
    writeData << userID << endl;
    writeData << endl;

    cout << "Kullanici eklendi !" << endl;

    writeData.close();
}
void Library::removeUser() {
    system("cls");

    int userID;
    cout << "\n\t Silmek istediginiz kullanici ID: ";
    cin >> userID;

    auto it = remove_if(users.begin(), users.end(), [userID](const User& users) {
        return users.getUserID() == userID;
        });

    if (it != users.end()) {
        users.erase(it, users.end());
        cout << "Kullanici basariyla silindi !" << endl;
    }
    else {
        cout << "Kullanici bulunamadi." << endl;
    }

    writeUsersFile();
    system("pause");
}
void Library::updateUser() {

    system("cls");
    int userID;
    cout << "\n\t Guncellemek istediginiz kullanici ID: ";
    cin >> userID;

    auto it = find_if(users.begin(), users.end(), [userID](const User& users) {
        return users.getUserID() == userID;
        });
    
    if (it != users.end()) {

        string name, surname;
        int id;

        cout << "\n\t Yeni kullanici bilgilerini girin " << endl << endl;
        cout << "\n\t Kullanici Adi    : "; cin >> name;
        cout << "\n\t Kullanici Soyadi : "; cin >> surname;
        cout << "\n\t Kullanici ID     : "; cin >> id;

        it->setUserInfo(name, surname, id);
        cout << "Kullanici bilgileri guncellendi." << endl;
    }
    else {
        cout << "Kullanici bulunamadi ! " << endl;
    }

    writeUsersFile();
    system("pause");
}
void Library::findUser() {
    system("cls");

    if (users.empty()) {
        cout << "\n\t Kullanýcý listesi boþ ! " << endl;
    }

    int userID;
    cout << "\n\t Aramak istediginiz kullanici ID: ";
    cin >> userID;

    auto it = find_if(users.begin(), users.end(), [userID](const User& users) {
        return users.getUserID() == userID;
        });

    if (it != users.end()) {
        it->displayUserInfo();
    }
    else {
        cout << "\n\t Kullanici bulunamadi !" << endl;
    }
    system("pause");
}

void Library::writeUsersFile() {
    ofstream writeData("Users.txt");

    if (!writeData.is_open()) {
        cerr << "Dosya acilamadi !!!" << endl;
        return;
    }

    for (const auto& user1 : users) {
        writeData << user1.getName() << endl;
        writeData << user1.getSurname() << endl;
        writeData << user1.getUserID() << endl;
        writeData << endl;
    }

}


// kitaplarý ve kullanýcýlarý görüntüleme
void Library::displayBooks() {
    system("cls");

    string readLine;
    ifstream readData("Books.txt");

    if (!readData.is_open()) {
        cerr << "Dosya acilamadi !!!" << endl;
        return;
    }
    cout << "\n\t Kutuphanedeki Kitaplar: " << endl;
    cout << "\n\t ***********************" << endl;
    cout << endl;

    while (getline(readData, readLine)) {
        cout << readLine << endl;
    }

    readData.close();

    system("pause");
}
void Library::displayUsers() {
    system("cls");

    string readLine;
    ifstream readData("Users.txt");

    if (!readData.is_open()) {
        cerr << "Dosya acilamadi !!!" << endl;
        return;
    }

    cout << "\n\t Kutuphanedeki Kullanicilar:" << endl;
    cout << "\n\t ***************************" << endl;
    cout << endl;
    while (getline(readData, readLine)) {
        cout << readLine << endl;
    }

    readData.close();

    system("pause");
}

//menü bilgileri
int Library:: menu() {
    // system("cls");
    int secim = 0;
    cout << "\n\t ### KUTUPHANE YONETIM SISTEMI ### " << endl << endl;
    cout << "\n\t [1]  - Kitap Ekle " << endl;
    cout << "\n\t [2]  - Kitap Sil " << endl;
    cout << "\n\t [3]  - Kitap Guncelle " << endl;
    cout << "\n\t [4]  - Kitap Ara " << endl;
    cout << "\n\t [5]  - Kullanici Ekle " << endl;
    cout << "\n\t [6]  - Kullanici Sil " << endl;
    cout << "\n\t [7]  - Kullanici Guncelle " << endl;
    cout << "\n\t [8]  - Kullanici Ara " << endl;
    cout << "\n\t [9]  - Kitaplari Listele " << endl;
    cout << "\n\t [10] - Kullanicilari Listele " << endl;
    cout << "\n\t [0]  - CIKIS " << endl;
    cout << "\n\t Seciminiz: ";
    cin >> secim;
    return secim;
}
