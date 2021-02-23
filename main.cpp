#include <iostream>
#include <vector>
#include "User.h"

//using namespace std;
unsigned int User::lastUserId = 0;
int main()
{
    std::vector<User> users;
    User u1("test", "tescik");
//    User::userId = 0;
    users.push_back(u1);
    u1.showUser();
    User u2("user2", "haslo2");
    u2.showUser();
    users.push_back(u2);
    for (std::vector<User>::iterator itr = users.begin(), finish = users.end(); itr!=finish; itr++){
        itr->showUser();
    }
    return 0;
}
