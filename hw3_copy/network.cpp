#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <queue>

#include "user.h"
#include "network.h"
#include "post.h"
#include "incoming_post.h"

Network::Network()
{
    users = std::vector<User *>();
}

Network::~Network()
{
    for (size_t i = 0; i < users.size(); i++)
    {
        delete users[i];
    }
}

int Network::read_users(const char *filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        return -1; // file not open or not found
    }

    int num_users;
    file >> num_users;
    file.ignore();

    for (int i = 0; i < num_users; i++)
    {
        User *user = new User();
        size_t id;
        std::string name;
        size_t birth_year;
        size_t zip_code;
        std::string friend_id_string;

        file >> id;
        user->set_id(id);
        file.ignore(); // Skip the newline character

        std::getline(file, name);
        name.erase(0, 1); // remove leading \t character
        user->set_name(name);

        file >> birth_year;
        user->set_birth_year(birth_year);
        file.ignore(); // Skip the newline character

        file >> zip_code;
        user->set_zip_code(zip_code);
        file.ignore(); // Skip the newline character

        std::getline(file, friend_id_string); // Read the entire line into friend_id_string

        std::istringstream iss(friend_id_string);
        size_t friend_id;

        while (iss >> friend_id)
        {
            user->add_friend(friend_id);
        }

        this->add_user(user);
    }

    file.close();
    return 0;
}

int Network::write_users(const char *filename)
{
    std::ofstream output_file(filename);

    if (!output_file.is_open())
    {
        return -1; // file not open or not found
    }

    output_file << users.size() << std::endl;

    for (size_t i = 0; i < users.size(); i++)
    {
        output_file << users[i]->get_id() << std::endl;
        output_file << "\t" << users[i]->get_name() << std::endl;
        output_file << "\t" << users[i]->get_birth_year() << std::endl;
        output_file << "\t" << users[i]->get_zip_code() << std::endl;
        output_file << "\t";

        std::vector<size_t> friends = users[i]->get_friends();

        for (size_t j = 0; j < friends.size(); j++)
        {
            output_file << friends[j] << " ";
        }
        output_file << std::endl;
    }

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

std::vector<std::size_t> Network::shortestPath(std::size_t from, std::size_t to)
{
    std::vector<std::size_t> path;
    std::vector<std::size_t> parent(num_users(), -1); // Initialize parent vector with -1
    std::queue<std::size_t> queue;

    queue.push(from);

    while (!queue.empty())
    {
        std::size_t current = queue.front();
        queue.pop();

        if (current == to)
        {
            std::size_t current_node = to;

            while (current_node != from)
            {
                path.push_back(current_node);
                current_node = parent[current_node];
            }

            path.push_back(from);
            std::reverse(path.begin(), path.end());
            return path;
        }

        std::vector<std::size_t> friends = get_user(current)->get_friends();

        for (std::size_t i = 0; i < friends.size(); i++)
        {
            if (parent[friends[i]] == -1)
            {
                queue.push(friends[i]);
                parent[friends[i]] = current;
            }
        }
    }

    return path; // Return an empty path if no path is found
}

std::vector<std::size_t> Network::distanceUser(std::size_t from, std::size_t &to, std::size_t distance)
{
    std::vector<std::size_t> path;
    std::vector<std::size_t> visited(num_users(), 0);
    std::queue<std::size_t> queue;

    queue.push(from);
    visited[from] = 1;

    while (!queue.empty())
    {
        std::size_t current = queue.front();
        queue.pop();

        path = shortestPath(from, current);

        if (path.size() - 1 == distance)
        {
            to = current;
            return path;
        }

        std::vector<std::size_t> friends = get_user(current)->get_friends();

        for (std::size_t i = 0; i < friends.size(); i++)
        {
            if (visited[friends[i]] == 0)
            {
                queue.push(friends[i]);
                visited[friends[i]] = 1;
            }
        }
    }
    to = -1;
    return path;
}

std::vector<std::size_t> Network::suggestFriends(std::size_t who, std::size_t &score)
{
    std::vector<size_t> friends_of_who = get_user(who)->get_friends();
    std::vector<size_t> suggested_friends;
    std::vector<size_t> best_candidates;
    std::vector<size_t> visited(num_users(), 0);
    std::vector<size_t> path;
    std::queue<size_t> queue;

    score = 0;
    queue.push(who);
    visited[who] = 1;

    while (!queue.empty())
    {
        size_t current = queue.front();
        queue.pop();

        size_t neighbor_distance = shortestPath(who, current).size() - 1;

        if (neighbor_distance == 2)
        {
            suggested_friends.push_back(current);
        }

        std::vector<size_t> friends = get_user(current)->get_friends();

        for (std::size_t i = 0; i < friends.size(); i++)
        {
            if (visited[friends[i]] == 0)
            {
                queue.push(friends[i]);
                visited[friends[i]] = 1;
            }
        }
    }

    for (size_t j = 0; j < suggested_friends.size(); j++)
    {
        size_t count = 0;
        std::vector<size_t> friends_of_suggested = get_user(suggested_friends[j])->get_friends();

        for (size_t k = 0; k < friends_of_who.size(); k++)
        {

            for (size_t n = 0; n < friends_of_suggested.size(); n++)
            {
                if (friends_of_who[k] == friends_of_suggested[n])
                {
                    count++;
                }
            }
        }

        if (count > score)
        {
            score = count;
            best_candidates.clear();
            best_candidates.push_back(suggested_friends[j]);
        }
        else if (count == score && count != 0)
        {
            best_candidates.push_back(suggested_friends[j]);
        }
        count = 0;
    }
    if (best_candidates.size() == 0)
    {
        score = -1;
    }

    return best_candidates;
}

std::vector<std::vector<std::size_t> > Network::groups()
{
    std::vector<std::vector<std::size_t> > groups;
    std::vector<std::size_t> visited(num_users(), 0);
    std::vector<std::size_t> stack;

    for (std::size_t i = 0; i < num_users(); i++)
    {
        if (visited[i] == 0)
        {
            std::vector<std::size_t> group;
            stack.push_back(i);
            visited[i] = 1;

            while (!stack.empty())
            {
                std::size_t current = stack[stack.size() - 1];
                stack.pop_back();
                group.push_back(current);

                std::vector<std::size_t> friends = get_user(current)->get_friends();

                for (std::size_t j = 0; j < friends.size(); j++)
                {
                    if (visited[friends[j]] == 0)
                    {
                        stack.push_back(friends[j]);
                        visited[friends[j]] = 1;
                    }
                }
            }
            groups.push_back(group);
        }
    }
    return groups;
}

void Network::addPost(std::size_t ownerId, std::string message, std::size_t likes, bool incoming, std::size_t author, bool isPublic)
{
    User *user = get_user(ownerId);
    size_t messages_size = get_user(ownerId)->get_messages().size();
    std::string author_name = get_user(author)->get_name();

    if (incoming)
    {
        IncomingPost *incoming_post = new IncomingPost(messages_size, message, likes, isPublic, author_name);
        user->addPost(incoming_post);
    }
    else
    {
        Post *post = new Post(messages_size, message, likes);
        user->addPost(post);
    }
}

std::string Network::displayPost(std::string name, std::size_t howMany, bool showOnlyPublic)
{
    User *user = get_user(get_id(name));
    return user->displayPosts(howMany, showOnlyPublic);
}

int Network::readPosts(const char *filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        return -1; // file not open or not found
    }

    int num_posts;
    file >> num_posts;
    file.ignore();

    std::size_t id;
    std::string message;
    std::size_t likes;
    bool isPublic;
    std::size_t owner_id;
    std::string incoming_line;
    std::string author_name;

    for (size_t i = 0; i < num_posts; i++)
    {
        file >> id;
        file.ignore();

        std::getline(file, message);
        message.erase(0, 1);

        file >> owner_id;
        file.ignore();

        file >> likes;
        file.ignore();

        std::getline(file, incoming_line);

        if (incoming_line == "") // check if next line is empty
        {
            addPost(owner_id, message, likes, false, owner_id, false);
        }
        else
        {
            std::getline(file, author_name);
            author_name.erase(0, 1);

            incoming_line.erase(0, 1);

            if (incoming_line == "public")
            {
                isPublic = true;
            }
            else
            {
                isPublic = false;
            }

            addPost(owner_id, message, likes, true, get_id(author_name), isPublic);
        }
    }

    file.close();
    return 0;
}
