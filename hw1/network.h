
#ifndef NETWORK_H
#define NETWORK_H

#include <iostream>
#include <string>
#include <vector>
#include "user.h"

class Network
{
public:
    /**
     * @brief Construct a new Network object.
     *
     * @pre None.
     * @post A new Network object is created.
     */
    Network();

    /**
     * @brief Destroy the Network object.
     *
     * @pre None.
     * @post The Network object is destroyed.
     */
    ~Network();

    /**
     * @brief Add a user to the network.
     *
     * @param user A pointer to the User object to be added.
     * @pre user is not null.
     * @post user is added to the network.
     */
    void add_user(User *user);

    /**
     * @brief Add a connection between two users.
     *
     * @param s1 The name of the first user.
     * @param s2 The name of the second user.
     * @return int 0 if the connection was successfully added, -1 otherwise.
     * @pre s1 and s2 are valid user names in the network.
     * @post A connection is added between s1 and s2.
     */
    int add_connection(std::string s1, std::string s2);

    /**
     * @brief Remove a connection between two users.
     *
     * @param s1 The name of the first user.
     * @param s2 The name of the second user.
     * @return int 0 if the connection was successfully removed, -1 otherwise.
     * @pre s1 and s2 are valid user names in the network.
     * @post The connection between s1 and s2 is removed.
     */
    int remove_connection(std::string s1, std::string s2);

    /**
     * @brief Get the ID of a user given their name.
     *
     * @param name The name of the user.
     * @return size_t The ID of the user.
     * @pre name is a valid user name in the network.
     * @post None.
     */
    size_t get_id(std::string name);

    /**
     * @brief Read user data from a file.
     *
     * @param filename The name of the file to read from.
     * @return int 0 if the file was successfully read, -1 otherwise.
     * @pre filename is a valid file path.
     * @post The user data from the file is added to the network.
     */
    int read_users(const char *filename);

    /**
     * @brief Write user data to a file.
     *
     * @param filename The name of the file to write to.
     * @return int 0 if the file was successfully written, -1 otherwise.
     * @pre filename is a valid file path.
     * @post The user data is written to the file.
     */
    int write_users(const char *filename);

    /**
     * @brief Get the number of users in the network.
     *
     * @return size_t The number of users in the network.
     * @pre None.
     * @post None.
     */
    size_t num_users();

    /**
     * @brief Get a pointer to a user given their ID.
     *
     * @param id The ID of the user.
     * @return User* A pointer to the User object.
     * @pre id is a valid user ID in the network.
     * @post None.
     */
    User *get_user(size_t id);

    /* 
     * @brief Get the shortest path between two users.
     *
     * @param from The ID of the first user. 
     * @param to The ID of the second user.
     * @return std::vector<std::size_t> A vector of user IDs representing the shortest path between the two users.
     * @pre from and to are valid user IDs in the network.
     * @post None.
     */
    std::vector<std::size_t> Network::shortestPath(std::size_t from, std::size_t to);

private:
    std::vector<User *> users;
};

#endif