#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

bool isPasswordStrong(const string& password) {
    if (password.length() < 8 || password.length() > 16)
        return false;

    bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;

    for (int i = 0; i < password.length(); i++) {
        char ch = password[i];
        if (isupper(ch)) hasUpper = true;
        else if (islower(ch)) hasLower = true;
        else if (isdigit(ch)) hasDigit = true;
        else if (ch == '@' || ch == '#' || ch == '$' || ch == '%' || ch == '&' || ch == '!' || ch == '^' || ch == '*')
            hasSpecial = true;
    }

    return hasUpper && hasLower && hasDigit && hasSpecial;
}

bool userExists(const string& username) {
    ifstream file(username + ".txt");
    return file.is_open();
}

void registerUser() {
    string username, password;

    cout << "\nRegistration\n";
    cout << "Enter a username: ";
    cin >> username;

    if (userExists(username)) {
        cout << "This username already exists. Please choose another.\n";
        return;
    }

    cout << "Create a strong password (8-16 characters, must include uppercase, lowercase, digit, and special character): ";
    cin >> password;

    if (!isPasswordStrong(password)) {
        cout << "Password is too weak. Please follow the rules.\n";
        return;
    }

    ofstream userFile(username + ".txt");
    if (userFile.is_open()) {
        userFile << username << endl;
        userFile << password << endl;
        userFile.close();
        cout << "Registration successful!\n";
    }
    else {
        cout << "Error saving user data.\n";
    }
}

void loginUser() {
    string username, password, fileUsername, filePassword;

    cout << "\nLogin\n";
    cout << "Username: ";
    cin >> username;

    ifstream userFile(username + ".txt");
    if (!userFile.is_open()) {
        cout << "No user found with this username.\n";
        return;
    }

    getline(userFile, fileUsername);
    getline(userFile, filePassword);
    userFile.close();

    cout << "Password: ";
    cin >> password;

    if (password == filePassword) {
        cout << "Login successful! Welcome, " << username << ".\n";
    }
    else {
        cout << "Incorrect password. Try again.\n";
    }
}

int main() {
    int choice;

    while (true) {
        cout << "\nChoose an option:\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
            registerUser();
        else if (choice == 2)
            loginUser();
        else if (choice == 3) {
            cout << "Goodbye!\n";
            break;
        }
        else
            cout << "Invalid choice. Please try again.\n";
    }

    return 0;
}
