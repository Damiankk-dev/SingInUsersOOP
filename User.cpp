#include "User.h"
const std::string User::SIGNED_USERS_DATABASE = "signedInUsers.txt";
User::User(std::string name, std::string pswd){
    userName = name;
    password = pswd;
    userId = lastUserId;
    getNextUserId();
}
void User::showUser(){
    std::cout << "ID: " << userId << "\n";
    std::cout << "Username: " << userName << "\n";
    std::cout << "Password: " << password << "\n";
}
void User::getNextUserId(){
    ++lastUserId;
}
