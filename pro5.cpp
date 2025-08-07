#include <iostream>
#include <string>
using namespace std;

class User {
private:
    string storedUsername = "user123";
    string storedPassword = "secure123";

protected:
        string getStoredUsername() {
        return storedUsername;
    }

    string getStoredPassword() {
        return storedPassword;
    }
};

class LoginSystem : public User {
public:
    void performLogin() {
        string inputUsername, inputPassword;

        cout << "\n LOGIN SYSTEM \n";
        cout << "Enter Username: ";
        cin >> inputUsername;
        cout << "Enter Password: ";
        cin >> inputPassword;

        
        if (!inputUsername.empty()) {
            if (inputUsername == getStoredUsername()) {
                if (inputPassword == getStoredPassword()) {
                    cout << "Login Successful. Welcome, " << inputUsername << "!\n";
                } else {
                    cout << "Incorrect Password.\n";
                }
            } else {
                cout << "Invalid Username.\n";
            }
        } else {
            cout << "Username cannot be empty.\n";
        }
    }
};

int main() {
    LoginSystem system;
    char choice;

    do {
        system.performLogin();

        cout << "\nDo you want to try again? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << "\n Exiting Login System. Goodbye!\n";
    return 0;
}
