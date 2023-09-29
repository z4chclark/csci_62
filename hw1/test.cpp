// no bugs caught

#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include "user.h"
#include "network.h"

using namespace std;

void test_user_constructor()
{
    cout << "Testing User constructor..." << endl;
    vector<size_t> friends;
    friends.push_back(1);
    friends.push_back(2);
    User *user = new User(3, "John Doe", 1999, 12345, friends);
    assert(user->get_id() == 3);

    cout << "Passed!" << endl;
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

    cout << "Passed!" << endl;
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

    cout << "Passed!" << endl;
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

    cout << "Passed!" << endl;
}

void test_network_constructor()
{
    cout << "Testing Network constructor..." << endl;
    Network *network = new Network();
    assert(network->num_users() == 0);

    cout << "Passed!" << endl;
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

    cout << "Passed!" << endl;
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

    cout << "Passed!" << endl;
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

    cout << "Passed!" << endl;
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

    cout << "Passed!" << endl;
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

    cout << "Passed!" << endl;
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
}