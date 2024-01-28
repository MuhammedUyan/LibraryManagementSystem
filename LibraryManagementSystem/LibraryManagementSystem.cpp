#include <iostream>
#include <string>
#include "User.h"
#include "Book.h"
#include "Library.h"

using namespace std;

int main()
{
    
    Library library1;
    

    while (true) {

        system("cls");

        switch (library1.menu())
        {
        case 1:
            // Kitap ekleme
            library1.addBook();
            break;
        case 2:
            // Kitap silme
            library1.removeBook();
            break;
        case 3:
            // Kitap guncellme
            library1.updateBook();
            break;
        case 4:
            // Kitap arama
            library1.findBook();
            break;
        case 5:
            // Kullanıcı ekleme
            library1.addUser();
            break;
        case 6:
            // Kullanıcı silme
            library1.removeUser();
            break;
        case 7:
            // Kullanıcı güncelleme
            library1.updateUser();
            break;
        case 8:
            // Kullanıcı arama
            library1.findUser();
            break;
        case 9:
            // Kitapları listeleme
            library1.displayBooks();
            break;
        case 10:
            // Kullanicilari listeleme
            library1.displayUsers();
            break;
        case 0:
            cout << "\n\t Programdan cikiliyor !!!" << endl;
            return 0;
        default:
            cout << "\n\t Gecersiz secenek !!!" << endl;
            break;
        }
    }

    return 0;
}

