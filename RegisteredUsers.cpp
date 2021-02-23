#include "RegisteredUsers.h"

void RegisteredUsers::split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
}
std::vector<std::string> RegisteredUsers::split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

const std::string RegisteredUsers::SIGNED_USERS_FILEPATH = "signedInUsers.txt";

//std::vector<std::string> RegisteredUsers::loadRegisteredUsers() {
//    std::ifstream inputFile(RegisteredUsers::SIGNED_USERS_FILEPATH);
//    std::string temp;
//    std::vector<std::string> registeredUsersIds;
//    inputFile.open(RegisteredUsers::SIGNED_USERS_FILEPATH, std::ios::in);
//    if ( !(inputFile.good()) ){
//        std::cout <<  "Unable to open file!\n";
//        registeredUsersIds[0] = "\0";
//    }
//    else {
//        while(getline(inputFile, temp)) {
//        //        userDataLine = split(temp, '|');
//        //        std::string loadedUser = userDataLine[1];
//        //        registeredUsersIds.push_back(loadedUser);
//        //        registeredUsers[loadedUser] = userDataLine[2];
//        //        getline(file, temp);
//        }
//        inputFile.close();
//    }
//    return registeredUsersIds;
//}

//


std::string RegisteredUsers::getUsername() {
    std::string inputUsername;
    std::cout << "Podaj login\n";
    getline(std::cin, inputUsername);
    return inputUsername;
}
bool RegisteredUsers::isInsertedUsernameCorrect(std::map<std::string, std::pair<std::string, int> > &registeredUsers, std::string& username) {
    std::pair<std::map<std::string, std::pair<std::string, int> >::iterator,bool> ret;
    std::pair<std::string, int> defaultPair("", 0);
    ret = registeredUsers.insert(
              std::pair<std::string, std::pair<std::string, int>>(username, defaultPair));
    return ret.second;
}
std::string RegisteredUsers::getPassword() {
    std::string inputPass;
    std::cout << "Podaj haslo\n";
    getline(std::cin, inputPass);
    return inputPass;
}
bool RegisteredUsers::isPasswordCorrect(std::string& password) {
    int passLength = password.length();
    if (passLength >= 4) return true;
    else return false;
}
//std::string createUser(std::map<std::string, std::pair<std::string, int> > &registeredUsers) {
//    std::string newUser;
//    newUser = RegisteredUsers::createCorrectUsername(registeredUsers);
//    registeredUsers[newUser] = getCorrectPassword();
//    saveUserData2File(registeredUsers, newUser);
//    return newUser;
//}

std::string RegisteredUsers::createCorrectUsername(std::map<std::string, std::pair<std::string, int> > &registeredUsers) {
    bool confirmUsername = false;
    do {
        std::string newUsername = getUsername();
        confirmUsername = isInsertedUsernameCorrect(registeredUsers, newUsername);
        if (confirmUsername == true) {
            std::cout << "Poprawnie dodano uzytkownika\n";
//            userId = registeredUsers.size();
            return newUsername;
        } else {
            std::cout << "Taki uzytkownik juz istnieje\n";
            std::cout << "Podaj inny login\n";
        }
    } while(confirmUsername == false);
    return "";
}
std::string RegisteredUsers::getCorrectPassword() {
    unsigned int wrongPasswordApproach = 0;
    std::string inputPass ;
    do {
        wrongPasswordApproach++;
        inputPass = getPassword();
        if (isPasswordCorrect(inputPass)) {
            return inputPass;
        } else {
            std::cout << "Haslo musi posiadac przynajmniej 4 znaki\n";
        }
    } while (isPasswordCorrect(inputPass) == false);
    return "";
}
//void saveUserData2File(std::map<std::string, std::string>& registeredUsers, std::string &user) {
//    std::string fileName = "zarejestrowani_uzytkownicy.txt";
//    std::fstream file;
//    file.open(fileName, std::ios::out | std::ios::app);
//    std::map<std::string, std::string>::iterator userItr;
//    userItr = registeredUsers.find(user);
//    file << registeredUsers.size() << '|';
//    file << userItr->first << '|';
//    file << userItr->second << '\n';
//    file.close();
//}

//std::map<std::string, std::string>::iterator getRegisteredUser(std::map<std::string, std::string>& registeredUsers) {
//    std::map<std::string, std::string>::iterator usernameItr;
//    do {
//        std::string userToLogIn = getUsername();
//        usernameItr = registeredUsers.find(userToLogIn);
//        if (usernameItr == registeredUsers.end()) {
//            std::cout << "Uzytkownik o podanym loginie nie istnieje, podaj wlasciwy login\n";
//        }
//    } while (usernameItr == registeredUsers.end());
//    return usernameItr;
//}
//bool isPasswordMatch(std::map<std::string, std::string>::iterator &usernameItr) {
//    std::string password = getPassword();
//    if (usernameItr->second == password) return true;
//    else return false;
//}
//bool isPasswordVerified(std::map<std::string, std::string>::iterator &usernameItr) {
//    unsigned int wrongPasswordAttempt = 0;
//    while (isPasswordMatch(usernameItr) == false ) {
//        wrongPasswordAttempt++;
//        if (wrongPasswordAttempt >= 3) {
//            std::cout << "Blednie wpisano haslo 3 razy, nalezy odczekac 5 sekund\n";
//            wrongPasswordAttempt = 0;
//            Sleep(5000);
//        }
//    }
//    return true;
//}
//std::map<std::string, std::string>::iterator getSignedInUser (std::map<std::string, std::string>& registeredUsers) {
//    std::map<std::string, std::string>::iterator usernameItr;
//    usernameItr = getRegisteredUser(registeredUsers);
//    if (usernameItr != registeredUsers.end() ) {
//        if (isPasswordVerified(usernameItr) ) return usernameItr;
//    } else return registeredUsers.end();
//    return usernameItr;
//}
//void changePassword(std::map<std::string, std::string>::iterator &usernameItr) {
//    std::string newPassword = getCorrectPassword();
//    usernameItr->second = newPassword;
//}

