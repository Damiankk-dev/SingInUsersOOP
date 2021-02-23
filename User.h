#include <iostream>
#include <vector>

class User {
    std::string userName;
    std::string password;
    unsigned int userId;
    static const std::string SIGNED_USERS_DATABASE;
public:
    static unsigned int lastUserId;
    static void getNextUserId();
    User(std::string = "empty", std::string = "empty");
    std::string getUserName();
    std::string getPassword();
    void showUser();
    void loadUsersFromFile();

};
