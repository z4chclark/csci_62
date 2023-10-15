#include <iostream>
#include <string>
#include <vector>

#include "incoming_post.h"
#include "post.h"

IncomingPost::IncomingPost() : Post::Post()
{
    isPublic = false;
    author = "";
}

IncomingPost::~IncomingPost()
{
}

IncomingPost::IncomingPost(std::size_t id,
                           std::string message,
                           size_t likes,
                           bool isPublic,
                           std::string author) : Post::Post(id, message, likes)
{
    this->isPublic = isPublic;
    this->author = author;
}

std::string IncomingPost::displayPost()
{
    std::string returnString;
    if (this->isPublic)
    {
        returnString = "Public: " + this->Post::displayPost();
    }
    else
    {
        returnString = "Private: " + this->Post::displayPost();
    }

    return returnString;
}
