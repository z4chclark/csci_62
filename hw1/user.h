
/*
header file for user class
*/

#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class user {
    private:
        size_t id;
        string name;
        size_t birth_year;
        size_t zip_code;
        vector<size_t> friends;
};

#endif

