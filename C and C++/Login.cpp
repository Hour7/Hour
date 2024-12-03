#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

// Simple hash function for obfuscation (not secure for production use)
string basicHash(const string& password) {
    unsigned long hash = 5381;
    for (char c : password) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    stringstream ss;
    ss << hex << hash;
    return ss.str();
}

// Function to register a new user
void registerUser() {
    string username, password;
    cout << "Enter a username: ";
    cin >> username;

    cout << "Enter a password: ";
    cin >> password;

    // Apply the basic hash function
    string hashedPassword = basicHash(password);

    // Check if username already exists
    ifstream infile("users.txt");
    string line;
    while (getline(infile, line)) {
        if (line.find(username + " ") == 0) {
            cout << "Username already exists. Please try another.\n";
            infile.close();
            return;
        }
    }
    infile.close();

    // Save username and hashed password to file
    ofstream outfile("users.txt", ios::app);
    outfile << username << " " << hashedPassword << "\n";
    outfile.close();

    cout << "Registration successful! You can now log in.\n";
}

// Function to log in an existing user
bool loginUser() {
    string username, password;
    cout << "Enter your username: ";
    cin >> username;

    cout << "Enter your password: ";
    cin >> password;

    // Apply the basic hash function for comparison
    string hashedPassword = basicHash(password);

    // Check credentials
    ifstream infile("users.txt");
    string line;
    while (getline(infile, line)) {
        istringstream iss(line);
        string fileUsername, fileHashedPassword;
        iss >> fileUsername >> fileHashedPassword;

        if (fileUsername == username && fileHashedPassword == hashedPassword) {
            cout << "Login successful! Welcome, " << username << "!\n";
            infile.close();
            return true;
        }
    }
    infile.close();

    cout << "Invalid username or password. Please try again.\n";
    return false;
}

// Main program function with login/register integration
void mainMenu() {
    int choice;
    bool loggedIn = false;

    do {
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loggedIn = loginUser();
                if (loggedIn) {
                    cout << "Accessing reservation system...\n";
                    // Call reservation system functions here if login is successful
                }
                break;
            case 3:
                cout << "Exiting...\n";
                return;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 3);
}

int main() {
    mainMenu();
    return 0;
}
