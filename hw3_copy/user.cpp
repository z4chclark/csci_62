
#include <iostream>
#include <string>
#include <vector>
#include "user.h"
#include "incoming_post.h"

User::User()
{
    id = 0;
    name = "";
    birth_year = 0;
    zip_code = 0;
    friends = std::vector<size_t>();
    messages = std::vector<Post *>();
}

User::User(size_t input_id, std::string input_name, size_t input_birth_year, size_t input_zip_code, std::vector<size_t> input_friends)
{
    id = input_id;
    name = input_name;
    birth_year = input_birth_year;
    zip_code = input_zip_code;
    friends = input_friends;
}

User::~User()
{
}

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

std::vector<Post *> User::get_messages()
{
    return messages;
}

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

void User::add_friend(size_t friend_id)
{
    for (size_t i = 0; i < friends.size(); i++)
    {
        if (friends[i] == friend_id)
        {
            return;
        }
    }
    friends.push_back(friend_id);
}

void User::delete_friend(size_t friend_id)
{
    for (size_t i = 0; i < friends.size(); i++)
    {
        if (friends[i] == friend_id)
        {
            friends.erase(friends.begin() + i);
            return;
        }
    }
}

void User::addPost(Post *post)
{   
    messages.push_back(post);
}

std::string User::displayPosts(std::size_t howMany, bool showOnlyPublic)
{
    std::string returnString;
    size_t count = 0;
    std::vector<Post *> messages_copy = messages;
    std::reverse(messages_copy.begin(), messages_copy.end());

    if (!showOnlyPublic)
    {
        for (Post *current_post : messages_copy)
        {
            returnString += current_post->displayPost() + "\n\n";
            count++;
            if (count == howMany)
            {
                return returnString;
            }
        }
        return returnString;
    }

    else
    {
        for (Post *current_post : messages_copy)
        {
            if (typeid(current_post).name() == "IncomingPost")
            {
                IncomingPost *current_incoming_post = (IncomingPost *)current_post;
                std::string s = current_incoming_post->displayPost();

                if (s[2] == 'u') // check if returned string is public
                {
                    returnString += current_post->displayPost() + "\n\n";
                    count++;
                    if (count == howMany)
                    {
                        return returnString;
                    }
                }
                else
                {
                    continue;
                }
            }
            else
            {
                returnString += current_post->displayPost() + "\n\n";
                count++;
                if (count == howMany)
                {
                    return returnString;
                }
            }
        }

        return returnString;
    }
}