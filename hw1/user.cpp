
#include <iostream>
#include <string>
#include <vector>
#include "user.h"

User::User()
{
    id = 0;
    name = "";
    birth_year = 0;
    zip_code = 0;
    friends = {};
}

User::User(size_t input_id, std::string input_name, size_t input_birth_year, size_t input_zip_code, std::vector<size_t> input_friends)
{
    id = input_id;
    name = input_name;
    birth_year = input_birth_year;
    zip_code = input_zip_code;
    friends = input_friends;
}

// getters
size_t User::get_id()
{
    return id;
}

std::string User::get_name()
{
    return name;
}

size_t User::get_birth_year()
{
    return birth_year;
}

size_t User::get_zip_code()
{
    return zip_code;
}

std::vector<size_t> User::get_friends()
{
    return friends;
}

// setters
void User::set_id(size_t input_id)
{
    id = input_id;
}

void User::set_name(std::string input_name)
{
    name = input_name;
}

void User::set_birth_year(size_t input_birth_year)
{
    birth_year = input_birth_year;
}

void User::set_zip_code(size_t input_zip_code)
{
    zip_code = input_zip_code;
}
