#ifndef POST_H
#define POST_H

#include <string>

class Post
{
private:
    std::size_t id;
    std::string message;
    std::size_t likes;

public:
    /**
     * @brief Construct a new Post object.
     *
     * @pre None.
     * @post A new Post object is created.
     */
    Post();

    /**
     * @brief Destroy the Post object.
     *
     * @pre None.
     * @post The Post object is destroyed.
     */
    ~Post();
    /**
     * @brief Construct a new Post object.
     *
     * @param id The ID of the post.
     * @param message The message of the post.
     * @param likes The number of likes of the post.
     * @pre None.
     * @post A new Post object is created.
     */
    Post(std::size_t id, std::string message, std::size_t likes);

    /**
     * @brief Get the ID of the post.
     *
     * @return std::size_t The ID of the post.
     * @pre None.
     * @post The ID of the post is returned.
     */
    std::size_t getID();

    /**
     * @brief Get the message of the post.
     *
     * @return std::string The message of the post.
     * @pre None.
     * @post The message of the post is returned.
     */
    std::string getMessage();

    /**
     * @brief Get the number of likes of the post.
     *
     * @return std::size_t The number of likes of the post.
     * @pre None.
     * @post The number of likes of the post is returned.
     */
    std::size_t getLikes();

    /**
     * @brief Display the post.
     *
     * @return std::string The post.
     * @pre None.
     * @post The post is displayed.
     */
    std::string virtual displayPost();
};

#endif