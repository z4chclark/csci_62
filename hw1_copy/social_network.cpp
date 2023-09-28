#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include <iomanip>
#include <sstream>
#include <limits>

#include "user.cpp"
#include "network.cpp"

using namespace std;

void print_users(Network *network)
{
    cout << setw(7) << left << "\nID" << setw(25) << left << "Name" << setw(6) << left << "Year" << setw(5) << left << "Zip" << endl;
    cout << "========================================" << endl;

    for (size_t i = 0; i < network->num_users(); i++)
    {
        User *current_user = network->get_user(i);
        cout << setw(7) << left << current_user->get_id();
        cout << setw(25) << left << current_user->get_name();
        cout << setw(6) << left << current_user->get_birth_year();
        cout << setw(5) << left << current_user->get_zip_code() << endl;
    }
    cout << "========================================\n"
         << endl;
}

void print_friends(Network *network, string name)
{
    cout << setw(7) << left << "\nID" << setw(25) << left << "Name" << setw(6) << left << "Year" << setw(5) << left << "Zip" << endl;
    cout << "========================================" << endl;

    size_t id = network->get_id(name);
    User *user = network->get_user(id);

    vector<size_t> friends = user->get_friends();

    for (size_t i = 0; i < friends.size(); i++)
    {
        User *current_friend = network->get_user(friends[i]);

        cout << setw(7) << friends[i];
        cout << setw(25) << left << current_friend->get_name();
        cout << setw(6) << left << current_friend->get_birth_year();
        cout << setw(5) << left << current_friend->get_zip_code() << endl;
    }
}

int main()
{

    Network *network = new Network();

    cout << "Input file name of social network: ";
    string filename;
    cin >> filename;
    cout << "\n\n";
    const char *c = filename.c_str();
    network->read_users(c);

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string input;
    char choice;

    while (choice != 7)
    {
        cout << "\nMenu\n"
             << endl;
        cout << "1. Add user" << endl;
        cout << "2. Add connection" << endl;
        cout << "3. Remove connection" << endl;
        cout << "4. Print users" << endl;
        cout << "5. Print friends" << endl;
        cout << "6. Write to file" << endl;
        cout << "7. Exit\n"
             << endl;

        getline(cin, input);

        string s;
        stringstream ss(input);
        vector<string> v;

        while (getline(ss, s, ' '))
        {
            v.push_back(s);
        }

        switch (v.front()[0])
        {
        case '1':
        {
            string name = v[1] + ' ' + v[2];

            if (network->get_id(name) != -1)
            {
                User *new_user = new User(network->num_users(),
                                          name,
                                          stoi(v[3]),
                                          stoi(v[4]),
                                          vector<size_t>());

                network->add_user(new_user);
            }
            else
            {
                cout << "\nInvalid input" << endl;
            }

            break;
        }

        case '2':
        {
            string name1 = v[1] + ' ' + v[2];
            string name2 = v[3] + ' ' + v[4];

            if (network->add_connection(name1, name2))
            {
                cout << "\nConnection added successfully" << endl;
            }
            else
            {
                cout << "\nConnection already exists or person does not exist" << endl;
            }
            break;
        }

        case '3':
        {
            string name1 = v[1] + ' ' + v[2];
            string name2 = v[3] + ' ' + v[4];
            if (network->remove_connection(name1, name2))
            {
                cout << "\nConnection removed successfully" << endl;
            }
            else
            {
                cout << "\nConnection does not exist or person does not exist" << endl;
            }
            break;
        }
        case '4':
            print_users(network);
            break;

        case '5':
        {
            string name = v[1] + ' ' + v[2];

            if (network->get_id(name) != -1)
            {
                cout << "\nFriends of " << name << endl;
                print_friends(network, name);
            }
            else
            {
                cout << "\nPerson does not exist" << endl;
            }
            break;
        }

        case '6':
        {
            const char *filename = v[1].c_str();
            network->write_users(filename);
            break;
        }

        case '7':
            exit(0);

        default:
            cout << "\nInvalid input" << endl;
            break;
        }
    }

    return 0;
}
