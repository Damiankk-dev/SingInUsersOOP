#include <iostream>
#include <fstream>
#include <vector>

class RegisteredUsersInterface{
public:
    const std::fstream file;
    static const std::string SIGNED_USERS_DATABASE;
    std::vector<std::string> userDataLine;

    std::vector<std::string> loadRegisteredUsers();

/*				porownywanie wejsciowego usera z baza
				przeszukiwanie bazy po nazwach usera i porownywanie hasla
				odczytywanie ostatniego id
				mapa z u¿ytkownikami w pamiêci

				*/
				/*
std::vector<std::string> loadRegisteredUsers();
*/

};
