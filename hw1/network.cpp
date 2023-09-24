
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "user.h"
#include "network.h"

Network::Network()
{
    users = std::vector<User *>();
}

int Network::read_users(char *filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        return -1; // file not open or not found
    }

    int num_users;
    file >> num_users;
    file.ignore();

    std::vector<User> users;

    for (int i = 0; i < num_users; i++)
    {
        User user;
        size_t id;
        std::string name;
        size_t birth_year;
        size_t zip_code;
        std::vector<size_t> friends;
        std::string friend_id_string;

        file >> id;
        user.set_id(id);
        file.ignore();

        std::getline(file, name);
        user.set_name(name);

        file >> birth_year;
        user.set_birth_year(birth_year);
        file.ignore();

        file >> zip_code;
        user.set_zip_code(zip_code);
        file.ignore();

        std::istringstream iss(friend_id_string);
        size_t friend_id;
        while (iss >> friend_id)
        {
            friends.push_back(friend_id);
        }

        users.push_back(user);
    }

    file.close();
    return 0;
}

void Network::add_user(User *user)
{
    users.push_back(user);
}

int Network::add_connection(std::string s1, std::string s2)
{
    size_t id1 = get_id(s1);
    size_t id2 = get_id(s2);

    if (id1 == id2)
    {
        return -1;
    }
    else if (id1 == -1 || id2 == -1)
    {
        return -1;
    }

    User *user1 = get_user(id1);
    User *user2 = get_user(id2);

    user1->add_friend(id2);
    user2->add_friend(id1);

    return 0;
}

int Network::remove_connection(std::string s1, std::string s2)
{
    size_t id1 = get_id(s1);
    size_t id2 = get_id(s2);

    if (id1 == id2)
    {
        return -1;
    }
    else if (id1 == -1 || id2 == -1)
    {
        return -1;
    }

    User *user1 = get_user(id1);
    User *user2 = get_user(id2);

    user1->delete_friend(id2);
    user2->delete_friend(id1);

    return 0;
}

size_t Network::get_id(std::string name)
{
    for (size_t i = 0; i < users.size(); i++)
    {
        if (users[i]->get_name() == name)
        {
            return users[i]->get_id();
        }
    }
    return -1;
}

User *Network::get_user(size_t id)
{
    for (size_t i = 0; i < users.size(); i++)
    {
        if (users[i]->get_id() == id)
        {
            return users[i];
        }
    }
    return NULL;
}

size_t Network::num_users()
{
    return users.size();
}
