
#include <iostream>
#include <string>
#include <vector>
#include "incoming_post.h"

IncomingPost::IncomingPost()
{
}

IncomingPost::~IncomingPost()
{
}

IncomingPost::IncomingPost(std::size_t id,
                           std::string message,
                           size_t likes,
                           bool isPublic,
                           std::string author) : Post(id, message, likes)
{
    this->isPublic = isPublic;
    this->author = author;
}

std::string displayPost() 
{
    // return std::to_string(id) + " " + message + " - " + std::to_string(likes) + " likes";
}