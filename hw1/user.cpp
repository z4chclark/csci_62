/*
Define a class to model a User (in user.h with method bodies in user.cpp). 

It should contain the following fields:

A std::size_t id (should be set to the entry/index in the users array/vector of the Network class described below where this user is located; thus it should start at 0)
A std::string name that consists of a first and last name separated by spaces. You should store the full name in a single string. It is recommended to use a C++ ‘string’ object rather than a simple C character array to represent the name.
A std::size_t indicating the birth year of the user.
A std::size_t indicating the user’s zip code.
A vector of std::size_t entries for friend connections. Each entry will be the corresponding integer ID of their friend.

The User class should support the following public operations:

Default and primary constructor which will take in 5 arguments, one for each field.  Note that the constructor does not need to verify that the id passed in reflects its spot in the Network.  The User class needs no knowledge of the Network class.
Individual accessor methods (getId, getName, getYear, getZip, getFriends) to return the user’s name, their user ID, birth year, and zip code, and a reference to the friend list (array or vector)
An addFriend method accepting the ID of a user to add as a friend. If the indicated user is already a friend of this user, do nothing (i.e. don't add it a second time).
A deleteFriend method accepting the ID of a user to delete as a friend. If the friend ID provided is NOT in the list of friends, do nothing.
Any other private methods you feel necessary or helpful
*/

#include <iostream>
#include <string>
#include <vector>
#include "user.h"

using namespace std;

user::user(size_t input_id, string input_name, size_t input_birth_year, size_t input_zip_code, vector<size_t> input_friends) {
    id = input_id;
    name = input_name;
    birth_year = input_birth_year;
    zip_code = input_zip_code;
    friends = input_friends;
}

user::user() {
    id = 0;
    name = "";
    birth_year = 0;
    zip_code = 0;
    friends = {};
}



