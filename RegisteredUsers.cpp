#include "RegisteredUsers.h"

//RegisteredUsers::RegisteredUsers(std::map<std::string, std::pair<std::string, int> > regUsrs){
//    std::pair<std::string, int> samplePair("none", 0);
//    regUsrs["user"] = samplePair;
//}

RegisteredUsers::RegisteredUsers()
    : registeredUsers()
{
    loadRegisteredUsers();
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
    std::cout << "Poprawnie dodano uzytkownika: " << newUser << "\n";
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
std::string RegisteredUsers::getRegisteredUser() {
    std::map<std::string, std::pair<std::string, int> > ::iterator userItr;
    std::string userToLogIn = "\0";
    do {
        userToLogIn = getUsername();
        userItr = RegisteredUsers::registeredUsers.find(userToLogIn);
        if (userItr == RegisteredUsers::registeredUsers.end()) {
            std::cout << "Uzytkownik o podanym loginie nie istnieje, podaj wlasciwy login\n";
        }
    } while (userItr == RegisteredUsers::registeredUsers.end());
    return userToLogIn;
}

bool RegisteredUsers::isPasswordMatch(std::string username) {
    std::string password = getPassword();
    std::string userPassword = RegisteredUsers::registeredUsers[username].first;
    if (userPassword == password) return true;
    else return false;
}
bool RegisteredUsers::isPasswordVerified(std::string userToSingIn) {
    unsigned int wrongPasswordAttempt = 0;
    while (isPasswordMatch(userToSingIn) == false ) {
        wrongPasswordAttempt++;
        if (wrongPasswordAttempt >= 3) {
            std::cout << "Blednie wpisano haslo 3 razy, nalezy odczekac 5 sekund\n";
            wrongPasswordAttempt = 0;
            Sleep(5000);
        }
    }
    return true;
}
std::vector<std::string> RegisteredUsers::getSignedInUser () {
    std::vector<std::string> signedInUserData;
    std::string user2SingIn;
    user2SingIn = RegisteredUsers::getRegisteredUser();
    if (user2SingIn != "\0" ) {
        if (RegisteredUsers::isPasswordVerified(user2SingIn) ) {
        signedInUserData.push_back(user2SingIn);
        signedInUserData.push_back(RegisteredUsers::registeredUsers[user2SingIn].first);
        signedInUserData.push_back(std::to_string(RegisteredUsers::registeredUsers[user2SingIn].second));
        }
    } else {
        signedInUserData.push_back(user2SingIn);
        signedInUserData.push_back("none");
        signedInUserData.push_back(0);
    }
    return signedInUserData;
}
void RegisteredUsers::changePassword(std::string belongToUser) {
    std::string newPassword = getCorrectPassword();
    RegisteredUsers::registeredUsers[belongToUser].first = newPassword;
    saveUserData2File(belongToUser);
}

