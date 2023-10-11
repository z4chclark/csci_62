#ifndef INCOMING_POST_H
#define INCOMING_POST_H

#include "post.h"

class IncomingPost : Post
{
private:
    bool isPublic;
    std::string author;

public:
    IncomingPost();
    ~IncomingPost();
    IncomingPost(std::size_t id,
                 std::string message,
                 size_t likes,
                 bool isPublic,
                 std::string author);

    std::string displayPost();
};

#endif