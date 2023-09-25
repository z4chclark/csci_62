#include <iostream>
#include <string>
#include <vector>

#include "user.cpp"
#include "network.cpp"

using namespace std;

int main()
{

    Network *network = new Network();

    cout << "Input file name of social network: ";
    char filename;
    cin >> filename;
    cout << "/n/n";
    network->read_users(&filename);

    int choice;

    while (choice != 7)
    {
        cout << "Menu" << endl;
        cout << "1. Add user" << endl;
        cout << "2. Add connection" << endl;
        cout << "3. Remove connection" << endl;
        cout << "4. Print users" << endl;
        cout << "5. Print friends" << endl;
        cout << "6. Write to file" << endl;
        cout << "7. Exit" << endl;
        cin >> choice;

        
    }
}