#ifndef INCOMING_POST_H
#define INCOMING_POST_H

#include "post.h"

class IncomingPost : Post
{
private:
    bool isPublic;
    std::string author;

public:
    /**
     * @brief Construct a new Incoming Post object
     * 
     * @pre None.
     * @post A new Incoming Post object is created.
     */
    IncomingPost();

    /**
     * @brief Destroy the Incoming Post object
     * 
     * @pre None.
     * @post The Incoming Post object is destroyed.
     */
    ~IncomingPost();

    /**
     * @brief Construct a new Incoming Post object
     * 
     * @param id The ID of the post.
     * @param message The message of the post.
     * @param likes The number of likes of the post.
     * @param isPublic Whether the post is public or not.
     * @param author The author of the post.
     * @pre None.
     * @post A new Incoming Post object is created.
     */
    IncomingPost(std::size_t id,
                 std::string message,
                 size_t likes,
                 bool isPublic,
                 std::string author);

    /**
     * @brief Display the post.
     *
     * @return std::string The post.
     * @pre None.
     * @post The post is displayed.
    */
    std::string displayPost();

};

#endif