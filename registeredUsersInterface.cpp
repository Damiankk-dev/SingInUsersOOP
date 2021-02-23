#include "RegisteredUsersInterface.h"


const std::string RegisteredUsersInterface::SIGNED_USERS_DATABASE = "signedInUsers.txt";

std::vector<std::string> loadRegisteredUsers() {
    std::ifstream InputFile(RegisteredUsersInterface::SIGNED_USERS_DATABASE);
    std::string temp;
    std::vector<std::string> registeredUsersIds;
//    file.open("registeredUsers.txt", std::ios::in);
//    getline(file, temp);
//    while(!file.eof()) {
//        userDataLine = split(temp, '|');
//        std::string loadedUser = userDataLine[1];
//        registeredUsersIds.push_back(loadedUser);
//        registeredUsers[loadedUser] = userDataLine[2];
//        getline(file, temp);
//    }
//    file.close();
    return registeredUsersIds;
}
