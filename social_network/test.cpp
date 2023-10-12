
#include <iostream>
#include <string>
#include <vector>
#include <cassert>

#include "user.h"
#include "network.h"
#include "incoming_post.h"
#include "post.h"

using namespace std;

void test_user_constructor()
{
    cout << "Testing User constructor..." << endl;
    vector<size_t> friends;
    friends.push_back(1);
    friends.push_back(2);
    User *user = new User(3, "John Doe", 1999, 12345, friends);
    assert(user->get_id() == 3);

    cout << "Passed!\n"
         << endl;
}

void test_user_getters_setters()
{
    cout << "Testing User setters and getters..." << endl;
    vector<size_t> friends;
    friends.push_back(1);
    friends.push_back(2);
    User *user = new User(3, "John Doe", 1999, 12345, friends);
    user->set_id(4);
    user->set_name("Jane Doe");
    user->set_birth_year(2000);
    user->set_zip_code(54321);

    assert(user->get_id() == 4);
    assert(user->get_name() == "Jane Doe");
    assert(user->get_birth_year() == 2000);
    assert(user->get_zip_code() == 54321);
    assert(user->get_friends() == friends);

    cout << "Passed!\n"
         << endl;
}

void test_user_add_friend()
{
    cout << "Testing User add_friend..." << endl;
    vector<size_t> friends;
    friends.push_back(1);
    friends.push_back(2);
    User *user = new User(3, "John Doe", 1999, 12345, friends);
    user->add_friend(4);
    friends.push_back(4);
    assert(user->get_friends() == friends);

    cout << "Passed!\n"
         << endl;
}

void test_user_delete_friend()
{
    cout << "Testing User delete_friend..." << endl;
    vector<size_t> friends;
    friends.push_back(1);
    friends.push_back(2);
    User *user = new User(3, "John Doe", 1999, 12345, friends);
    user->delete_friend(2);
    friends.pop_back();
    assert(user->get_friends() == friends);

    cout << "Passed!\n"
         << endl;
}

void test_network_constructor()
{
    cout << "Testing Network constructor..." << endl;
    Network *network = new Network();
    assert(network->num_users() == 0);

    cout << "Passed!\n"
         << endl;
}

void test_add_user()
{
    cout << "Testing add_user..." << endl;
    Network *network = new Network();
    vector<size_t> friends;
    friends.push_back(1);
    friends.push_back(2);
    User *user = new User(3, "John Doe", 1999, 12345, friends);
    network->add_user(user);
    assert(network->num_users() == 1);

    cout << "Passed!\n"
         << endl;
}

void test_add_connection()
{
    cout << "Testing add_connection..." << endl;
    Network *network = new Network();
    vector<size_t> johns_friends;
    johns_friends.push_back(1);
    johns_friends.push_back(2);
    vector<size_t> janes_friends;
    janes_friends.push_back(1);
    janes_friends.push_back(2);

    User *user1 = new User(3, "John Doe", 1999, 12345, johns_friends);
    User *user2 = new User(4, "Jane Doe", 2000, 54321, janes_friends);
    network->add_user(user1);
    network->add_user(user2);
    network->add_connection("John Doe", "Jane Doe");
    johns_friends.push_back(4);
    janes_friends.push_back(3);
    assert(network->get_user(3)->get_friends() == johns_friends);
    assert(network->get_user(4)->get_friends() == janes_friends);

    cout << "Passed!\n"
         << endl;
}

void test_remove_connection()
{
    cout << "Testing remove_connection..." << endl;
    Network *network = new Network();
    vector<size_t> johns_friends;
    johns_friends.push_back(1);
    johns_friends.push_back(4);
    vector<size_t> janes_friends;
    janes_friends.push_back(1);
    janes_friends.push_back(3);

    User *user1 = new User(3, "John Doe", 1999, 12345, johns_friends);
    User *user2 = new User(4, "Jane Doe", 2000, 54321, janes_friends);
    network->add_user(user1);
    network->add_user(user2);
    network->remove_connection("John Doe", "Jane Doe");
    vector<size_t> expected_friends;
    expected_friends.push_back(1);
    assert(network->get_user(3)->get_friends() == expected_friends);
    assert(network->get_user(4)->get_friends() == expected_friends);

    cout << "Passed!\n"
         << endl;
}

void test_get_id()
{
    cout << "Testing get_id..." << endl;
    Network *network = new Network();
    vector<size_t> friends;
    friends.push_back(1);
    friends.push_back(4);

    User *user1 = new User(3, "John Doe", 1999, 12345, friends);
    network->add_user(user1);
    assert(network->get_id("John Doe") == 3);

    cout << "Passed!\n"
         << endl;
}

void test_num_users()
{
    cout << "Testing num_users..." << endl;
    Network *network = new Network();
    vector<size_t> friends;
    friends.push_back(1);
    friends.push_back(4);
    User *user1 = new User(3, "John Doe", 1999, 12345, friends);
    network->add_user(user1);
    assert(network->num_users() == 1);

    cout << "Passed!\n"
         << endl;
}

void test_shortestPath()
{
    cout << "Testing shortestPath..." << endl;
    Network *network = new Network();
    User *user1 = new User(0, "John Doe", 1999, 12345, vector<size_t>());
    User *user2 = new User(1, "Jane Doe", 2000, 54321, vector<size_t>());
    User *user3 = new User(2, "Bob Doe", 2001, 54321, vector<size_t>());

    network->add_user(user1);
    network->add_user(user2);
    network->add_user(user3);

    network->add_connection("John Doe", "Jane Doe");
    network->add_connection("Jane Doe", "Bob Doe");

    vector<size_t> expected_path;
    expected_path.push_back(0);
    expected_path.push_back(1);
    expected_path.push_back(2);

    assert(network->shortestPath(0, 2) == expected_path);

    cout << "Passed!\n"
         << endl;
}

void test_distanceUser()
{
    cout << "Testing distanceUser..." << endl;
    Network *network = new Network();

    User *user1 = new User(0, "John Doe", 1999, 12345, vector<size_t>());
    User *user2 = new User(1, "Jane Doe", 2000, 54321, vector<size_t>());
    User *user3 = new User(2, "Bob Doe", 2001, 54321, vector<size_t>());

    network->add_user(user1);
    network->add_user(user2);
    network->add_user(user3);

    network->add_connection("John Doe", "Jane Doe");
    network->add_connection("Jane Doe", "Bob Doe");

    vector<size_t> expected_path;
    expected_path.push_back(0);
    expected_path.push_back(1);
    expected_path.push_back(2);

    size_t distance = 2;
    size_t *to = new size_t;

    assert(network->distanceUser(0, *to, distance) == expected_path);
    assert(*to == 2);

    cout << "Passed!\n"
         << endl;
}

void test_suggestFriends()
{
    cout << "Testing suggestFriends..." << endl;
    Network *network = new Network();

    User *user1 = new User(0, "John Doe", 1999, 12345, vector<size_t>());
    User *user2 = new User(1, "Jane Doe", 2000, 54321, vector<size_t>());
    User *user3 = new User(2, "Bob Doe", 2001, 54321, vector<size_t>());
    User *user4 = new User(3, "Joe Doe", 2001, 54321, vector<size_t>());

    network->add_user(user1);
    network->add_user(user2);
    network->add_user(user3);
    network->add_user(user4);

    network->add_connection("John Doe", "Bob Doe");
    network->add_connection("John Doe", "Joe Doe");
    network->add_connection("Jane Doe", "Bob Doe");
    network->add_connection("Jane Doe", "Joe Doe");

    size_t score = 0;

    vector<size_t> expected_friends;
    expected_friends.push_back(1);

    assert(network->suggestFriends(0, score) == expected_friends);
    assert(score == 2);

    cout << "Passed!\n"
         << endl;
}

void test_groups()
{
    cout << "Testing groups..." << endl;
    Network *network = new Network();

    User *user1 = new User(0, "John Doe", 1999, 12345, vector<size_t>());
    User *user2 = new User(1, "Jane Doe", 2000, 54321, vector<size_t>());
    User *user3 = new User(2, "Bob Doe", 2001, 54321, vector<size_t>());
    User *user4 = new User(3, "Joe Doe", 2001, 54321, vector<size_t>());

    network->add_user(user1);
    network->add_user(user2);
    network->add_user(user3);
    network->add_user(user4);

    network->add_connection("John Doe", "Jane Doe");
    network->add_connection("Bob Doe", "Joe Doe");

    vector<vector<size_t> > expected_groups;
    vector<size_t> group1;
    group1.push_back(0);
    group1.push_back(1);
    vector<size_t> group2;
    group2.push_back(2);
    group2.push_back(3);
    expected_groups.push_back(group1);
    expected_groups.push_back(group2);

    assert(network->groups() == expected_groups);

    cout << "Passed!\n"
         << endl;
}

void test_post_constructors()
{
    cout << "Testing Post constructors..." << endl;
    Post *post = new Post();
    assert(post->getID() == 0);

    Post *post2 = new Post(1, "Hello World!", 0);
    assert(post2->getLikes() == 0);

    cout << "Passed!\n"
         << endl;
}

void test_post_getters()
{
    cout << "Testing Post getters..." << endl;
    Post *post = new Post(1, "Hello World!", 0);
    assert(post->getID() == 1);
    assert(post->getMessage() == "Hello World!");
    assert(post->getLikes() == 0);

    cout << "Passed!\n"
         << endl;
}

void test_post_displayPost()
{
    cout << "Testing Post displayPost..." << endl;
    Post *post = new Post(1, "Hello World!", 0);
    assert(post->displayPost() == "Hello World!\nLiked by 0 people");

    cout << "Passed!\n"
         << endl;
}

void test_incoming_post_constructors()
{
    cout << "Testing IncomingPost constructors..." << endl;
    IncomingPost *post = new IncomingPost();
    assert(post->getID() == 0);

    IncomingPost *post2 = new IncomingPost(1, "Hello World!", 0, true, "John Doe");
    assert(post2->getLikes() == 0);

    cout << "Passed!\n"
         << endl;
}

void test_incoming_post_displayPost()
{
    cout << "Testing IncomingPost displayPost..." << endl;
    IncomingPost *post = new IncomingPost(1, "Hello World!", 0, true, "John Doe");
    assert(post->displayPost() == "Public: Hello World!\nLiked by 0 people");

    cout << "Passed!\n"
         << endl;
}

int main()
{
    test_user_constructor();
    test_user_getters_setters();
    test_user_add_friend();
    test_user_delete_friend();
    test_network_constructor();
    test_add_user();
    test_add_connection();
    test_remove_connection();
    test_get_id();
    test_num_users();
    test_shortestPath();
    test_distanceUser();
    test_groups();
    test_suggestFriends();

    test_post_constructors();
    test_post_getters();
    test_post_displayPost();

    test_incoming_post_constructors();
    test_incoming_post_displayPost();

    return 0;
}