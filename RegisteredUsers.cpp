#include "RegisteredUsers.h"

//RegisteredUsers::RegisteredUsers(std::map<std::string, std::pair<std::string, int> > regUsrs){
//    std::pair<std::string, int> samplePair("none", 0);
//    regUsrs["user"] = samplePair;
//}

RegisteredUsers::RegisteredUsers()
    : registeredUsers()
{
}
void RegisteredUsers::split(const std::string &s, char delim, std::vector<std::string> &elems)
{
    std::stringstream ss(s);
    std::string item;
    while (getline(ss, item, delim))
    {
        elems.push_back(item);
    }
}
std::vector<std::string> RegisteredUsers::split(const std::string &s, char delim)
{
    std::vector<std::string> elems;
    RegisteredUsers::split(s, delim, elems);
    return elems;
}

const std::string RegisteredUsers::SIGNED_USERS_FILEPATH = "signedInUsers.txt";


void RegisteredUsers::createUser()
{
    std::string newUser;
    newUser = createCorrectUsername(registeredUsers);
    lastUserId++;
    std::string newPassword = RegisteredUsers::getCorrectPassword();
    std::pair<std::string, int> samplePair(newPassword, lastUserId);
    registeredUsers[newUser] = samplePair;
    saveUserData2File(newUser);
//    return newUser;
}
std::string RegisteredUsers::createCorrectUsername(std::map<std::string, std::pair<std::string, int> > &registeredUsers)
{
    bool confirmUsername = false;
    do
    {
        std::string newUsername = getUsername();
        confirmUsername = isInsertedUsernameCorrect(registeredUsers, newUsername);
        if (confirmUsername == true)
        {
            std::cout << "Poprawnie dodano uzytkownika\n";
//            userId = registeredUsers.size();
            return newUsername;
        }
        else
        {
            std::cout << "Taki uzytkownik juz istnieje\n";
            std::cout << "Podaj inny login\n";
        }
    }
    while(confirmUsername == false);
    return "";
}

std::string RegisteredUsers::getUsername()
{
    std::string inputUsername;
    std::cout << "Podaj login\n";
    getline(std::cin, inputUsername);
    return inputUsername;
}
bool RegisteredUsers::isInsertedUsernameCorrect(std::map<std::string, std::pair<std::string, int> > &registeredUsers, std::string& username)
{
    std::pair<std::map<std::string, std::pair<std::string, int> >::iterator,bool> ret;
    std::pair<std::string, int> defaultPair("", 0);
    ret = registeredUsers.insert(
              std::pair<std::string, std::pair<std::string, int>>(username, defaultPair));
    return ret.second;
}
std::string RegisteredUsers::getPassword()
{
    std::string inputPass;
    std::cout << "Podaj haslo\n";
    getline(std::cin, inputPass);
    return inputPass;
}
bool RegisteredUsers::isPasswordCorrect(std::string& password)
{
    int passLength = password.length();
    if (passLength >= 4) return true;
    else return false;
}

std::string RegisteredUsers::getCorrectPassword()
{
    unsigned int wrongPasswordApproach = 0;
    std::string inputPass ;
    do
    {
        wrongPasswordApproach++;
        inputPass = getPassword();
        if (isPasswordCorrect(inputPass))
        {
            return inputPass;
        }
        else
        {
            std::cout << "Haslo musi posiadac przynajmniej 4 znaki\n";
        }
    }
    while (isPasswordCorrect(inputPass) == false);
    return "";
}
void RegisteredUsers::saveUserData2File(std::string &user)
{
    std::fstream file;
    file.open(RegisteredUsers::SIGNED_USERS_FILEPATH, std::ios::out | std::ios::app);
    std::map<std::string, std::pair<std::string, int> > ::iterator userItr;
    userItr = registeredUsers.find(user);
    file << userItr->second.second << '|';
    file << userItr->first << '|';
    file << userItr->second.first << '\n';
    file.close();
}
void RegisteredUsers::loadRegisteredUsers()
{
    std::fstream inputFile;
    std::string temp;
    std::vector<std::string> userDataLine;
    inputFile.open(RegisteredUsers::SIGNED_USERS_FILEPATH, std::ios::in);
    if ( !(inputFile.good()) )
    {
        std::cout <<  "Unable to open file!\n";
    }
    else
    {
        while(getline(inputFile, temp))
        {
            userDataLine = RegisteredUsers::split(temp, '|');
            std::string loadedUser = userDataLine[1];
            std::string loadedPass = userDataLine[2];
            int loadedId = stoi(userDataLine[0]);
            std::pair<std::string, int> userData (loadedPass, loadedId);
            registeredUsers[loadedUser] = userData;
            if (loadedId > lastUserId) lastUserId = loadedId;
        }
        inputFile.close();
    }

}


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




//

