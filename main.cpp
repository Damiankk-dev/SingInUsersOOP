#include <iostream>
#include <vector>
#include <conio.h>
#include "RegisteredUsers.h"

//using namespace std;
int RegisteredUsers::lastUserId = 0;

void showMenuSignedIn(std::string) ;
void showMainMenu(std::string) ;
void maitainSignInMenu() ;
void maitainMenuSignedIn(std::vector<std::string>signedInUserData);

int main()
{
    maitainSignInMenu();

//    RegisteredUsers regUsrs;
//    regUsrs.loadRegisteredUsers();
//    std::map<std::string, std::pair<std::string, int> >  maptoShow = regUsrs.registeredUsers;
//    for (std::map<std::string, std::pair<std::string, int> >::iterator itr = maptoShow.begin(), finish = maptoShow.end();
//        itr != finish; itr++){
//            std::cout << itr->second.second<< "-" << itr->first << " : " << itr->second.first << "\n";
//        }
//    regUsrs.createUser();
//    std::string signedInUser = regUsrs.getSignedInUser();
//    std::cout << "poprawnie zalofowano uzytkownika: " << signedInUser << "\n";
    return 0;
}
void showMenuSignedIn(std::string header = "Poprawne logowanie!\n") {
    std::cout << "\n" << header << "\n";
    std::cout << "____________________________\n\n";
    std::cout << "1. Zmiana hasla\n";
    std::cout << "2. Wylogowanie\n";
    std::cout << "3. Przejscie do aplikacji\n";
    std::cout << "____________________________\n";
}
void showMainMenu(std::string header = "MENU GLOWNE") {
    std::cout << "\n" << header << "\n";
    std::cout << "____________________________\n\n";
    std::cout << "1. Logowanie\n";
    std::cout << "2. Rejestracja\n";
    std::cout << "0. Zamknij program\n";
    std::cout << "____________________________\n";
}
void maitainSignInMenu() {
    char choice = '\0';
    showMainMenu();
    while(choice != '0') {
        choice = getch();
        switch(choice) {
        case '1': {
            RegisteredUsers userSignedIn;

            std::vector<std::string>signedInUserData = userSignedIn.getSignedInUser();
            std::string signedInUser = signedInUserData[0];
            if ( signedInUser != "\0" ) {
                showMenuSignedIn();
                maitainMenuSignedIn(signedInUserData);
            }
            break;
        }
        case '2': {
            system("cls");
            RegisteredUsers userToBeCreated;
            userToBeCreated.createUser();
            system("cls");
            showMainMenu();
            break;
        }
        case '0':
            system("cls");
            std::cout << "Koniec programu\n";
            break;
        default:
            break;
        }
    }
}
void maitainMenuSignedIn(std::vector<std::string>signedInUserData) {
    char choice = '\0';
    while(choice != '2') {
        choice = getch();
        switch(choice) {
        case '1':{
            system("cls");
            RegisteredUsers maitainedUser;
            maitainedUser.changePassword(signedInUserData[0]);
            showMenuSignedIn("Poprawnie zmieniono haslo");
            break;
        }
        case '2':
            system("cls");
            showMainMenu("Wylogowano uzytkownika");
            break;
        case '3':
            system("cls");
            showMenuSignedIn("sekcja w budowie...\n");
            break;
        default:
            break;
        }
    }
}
