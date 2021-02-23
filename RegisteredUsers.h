#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>
#include <windows.h>

class RegisteredUsers{
public:

    struct UniqueUser {
        int id = 0;
        std::string username = "", password = "";
    };

    std::map<std::string, std::pair<std::string, int> > registeredUsers;


    const std::fstream file;
    static const std::string SIGNED_USERS_FILEPATH;
    std::vector<std::string> userDataLine;
    std::vector<std::string> allRegisteredUsers;

    std::vector<std::string> loadRegisteredUsers();
    void split(const std::string &s, char delim, std::vector<std::string> &elems);
    std::vector<std::string> split(const std::string &s, char delim);
    std::string createUser(std::map<std::string, std::pair<std::string, int> > &registeredUsers);
    std::string getUsername();
    std::string getPassword();
    bool isInsertedUsernameCorrect(std::map<std::string, std::pair<std::string, int> > &registeredUsers, std::string& username);
    bool isPasswordCorrect(std::string& password);
    std::string createCorrectUsername(std::map<std::string, std::pair<std::string, int> > &registeredUsers);
    std::string getCorrectPassword();

    bool verifyPassword(std::string username);

    UniqueUser lookupUser(std::string username);



/*				porownywanie wejsciowego usera z baza
				przeszukiwanie bazy po nazwach usera i porownywanie hasla
				odczytywanie ostatniego id
				mapa z u¿ytkownikami w pamiêci

				*/
				/*
std::vector<std::string> loadRegisteredUsers();
*/

};
