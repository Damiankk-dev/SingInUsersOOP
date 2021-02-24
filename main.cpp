#include <iostream>
#include <vector>
#include "User.h"
#include "RegisteredUsers.h"

//using namespace std;
unsigned int User::lastUserId = 0;
int RegisteredUsers::lastUserId = 0;
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

    std::map<std::string, std::pair<std::string, int> > sampleMap;
    std::pair<std::string, int> samplePair("none", 1);
    sampleMap["user"]  = samplePair;
    std::cout << sampleMap["user"].second<< " : " << sampleMap["user"].first << std::endl;

    RegisteredUsers regUsrs;
    regUsrs.loadRegisteredUsers();
    std::map<std::string, std::pair<std::string, int> >  maptoShow = regUsrs.registeredUsers;
    for (std::map<std::string, std::pair<std::string, int> >::iterator itr = maptoShow.begin(), finish = maptoShow.end();
        itr != finish; itr++){
            std::cout << itr->second.second<< "-" << itr->first << " : " << itr->second.first << "\n";
        }
    regUsrs.createUser();
    return 0;
}
