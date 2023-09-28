
#ifndef USER_H
#define USER_H

#include <iostream>
#include <vector>

class User
{

private:
    size_t id;
    std::string name;
    size_t birth_year;
    size_t zip_code;
    std::vector<size_t> friends;

public:
    /**
     * @brief Default constructor for User class.
     *
     * @pre None.
     * @post A User object is created with default values for its member variables.
     */
    User();

    /**
     * @brief Parameterized constructor for User class.
     *
     * @param input_id The ID of the User.
     * @param input_name The name of the User.
     * @param input_birth_year The birth year of the User.
     * @param input_zip_code The zip code of the User.
     * @param input_friends A vector of IDs of the User's friends.
     *
     * @pre None.
     * @post A User object is created with the given values for its member variables.
     */
    User(size_t input_id, std::string input_name, size_t input_birth_year, size_t input_zip_code, std::vector<size_t> input_friends);

    /**
     * @brief Destructor for User class.
     *
     * @pre None.
     * @post The User object is destroyed.
     */
    ~User();

    /**
     * @brief Adds a friend to the User's friend list.
     *
     * @param new_friend The ID of the new friend to add.
     *
     * @pre The new_friend ID is not already in the User's friend list.
     * @post The new_friend ID is added to the User's friend list.
     */
    void add_friend(size_t new_friend);

    /**
     * @brief Deletes a friend from the User's friend list.
     *
     * @param old_friend The ID of the friend to delete.
     *
     * @pre The old_friend ID is in the User's friend list.
     * @post The old_friend ID is removed from the User's friend list.
     */
    void delete_friend(size_t old_friend);

    /**
     * @brief Returns the ID of the User.
     *
     * @return The ID of the User.
     *
     * @pre None.
     * @post None.
     */
    size_t get_id();

    /**
     * @brief Returns the name of the User.
     *
     * @return The name of the User.
     *
     * @pre None.
     * @post None.
     */
    std::string get_name();

    /**
     * @brief Returns the birth year of the User.
     *
     * @return The birth year of the User.
     *
     * @pre None.
     * @post None.
     */
    size_t get_birth_year();

    /**
     * @brief Returns the zip code of the User.
     *
     * @return The zip code of the User.
     *
     * @pre None.
     * @post None.
     */
    size_t get_zip_code();

    /**
     * @brief Returns a vector of IDs of the User's friends.
     *
     * @return A vector of IDs of the User's friends.
     *
     * @pre None.
     * @post None.
     */
    std::vector<size_t> get_friends();

    /**
     * @brief Sets the ID of the User.
     *
     * @param new_id The new ID of the User.
     *
     * @pre None.
     * @post The ID of the User is set to the new_id value.
     */
    void set_id(size_t new_id);

    /**
     * @brief Sets the name of the User.
     *
     * @param new_name The new name of the User.
     *
     * @pre None.
     * @post The name of the User is set to the new_name value.
     */
    void set_name(std::string new_name);

    /**
     * @brief Sets the birth year of the User.
     *
     * @param new_birth_year The new birth year of the User.
     *
     * @pre None.
     * @post The birth year of the User is set to the new_birth_year value.
     */
    void set_birth_year(size_t new_birth_year);

    /**
     * @brief Sets the zip code of the User.
     *
     * @param new_zip_code The new zip code of the User.
     *
     * @pre None.
     * @post The zip code of the User is set to the new_zip_code value.
     */
    void set_zip_code(size_t new_zip_code);

    /**
     * @brief Sets the friend list of the User.
     *
     * @param new_friends A vector of IDs of the User's new friends.
     *
     * @pre None.
     * @post The friend list of the User is set to the new_friends vector.
     */
};

#endif