
#include <iostream>
#include <string>
#include <vector>
#include "post.h"

Post::Post(std::size_t id, std::string message, std::size_t likes)
{
    this->id = id;
    this->message = message;
    this->likes = likes;
}

Post::~Post()
{
}

std::string Post::displayPost()
{
    // return std::to_string(id) + " " + message + " - " + std::to_string(likes) + " likes";
}

std::size_t Post::getID()
{
    return id;
}

std::string Post::getMessage()
{
    return message;
}

std::size_t Post::getLikes()
{
    return likes;
}