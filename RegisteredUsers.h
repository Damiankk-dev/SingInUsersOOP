#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>
#include <windows.h>

class RegisteredUsers{
public:

//    struct UniqueUser {
//        int id = 0;
//        std::string username = "", password = "";
//    };

    std::map<std::string, std::pair<std::string, int> > registeredUsers;

RegisteredUsers();

//    const std::fstream file;
    static const std::string SIGNED_USERS_FILEPATH;
    static int lastUserId;
//    std::vector<std::string> userDataLine;
//    std::vector<std::string> allRegisteredUsers;

//    RegisteredUsers(std::map<std::string, std::pair<std::string, int> >);

    void split(const std::string &s, char delim, std::vector<std::string> &elems);
    std::vector<std::string> split(const std::string &s, char delim);
    void createUser();
    std::string getUsername();
    std::string getPassword();
    bool isInsertedUsernameCorrect(std::map<std::string, std::pair<std::string, int> > &registeredUsers, std::string& username);
    bool isPasswordCorrect(std::string& password);
    std::string createCorrectUsername(std::map<std::string, std::pair<std::string, int> > &registeredUsers);
    std::string getCorrectPassword();
    void saveUserData2File(std::string &user);
    void loadRegisteredUsers();
    bool verifyPassword(std::string username);
    std::string getRegisteredUser();
    bool isPasswordMatch(std::string username);
    bool isPasswordVerified(std::string username);
    std::vector<std::string> getSignedInUser ();
    void changePassword(std::string belongToUser);

//    UniqueUser lookupUser(std::string username);



/*				porownywanie wejsciowego usera z baza
				przeszukiwanie bazy po nazwach usera i porownywanie hasla
				odczytywanie ostatniego id
				mapa z u¿ytkownikami w pamiêci

				*/
				/*
std::vector<std::string> loadRegisteredUsers();
*/

};
