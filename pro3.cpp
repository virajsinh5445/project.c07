#include <iostream>
using namespace std;

class ATM {
private:
    string accountHolder;
    int pin;
    double balance;

public:
        ATM() {
        accountHolder = "John Doe";
        pin = 5445;
        balance = 1000.0; 
    }

        void setPIN(int p) {
        this->pin = p;
    }

    void setBalance(double b) {
        this->balance = b;
    }

        double getBalance() {
        return balance;
    }

    string getAccountHolder() {
        return accountHolder;
    }

        bool authenticate(int enteredPin) {
        return this->pin == enteredPin;
    }

        void checkBalance() {
        cout << "Current Balance: $" << balance << endl;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited $" << amount << " successfully.\n";
        } else {
            cout << "Invalid deposit amount.\n";
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrew $" << amount << " successfully.\n";
        } else {
            cout << "Insufficient balance or invalid amount.\n";
        }
    }
};

int main() {
    ATM user;
    int choice, enteredPin;
    double amount;

    cout << " Enter your PIN to access ATM: ";
    cin >> enteredPin;

    if (!user.authenticate(enteredPin)) {
        cout << " Incorrect PIN. Access denied.\n";
        return 0;
    }

    do {
        cout << "\n ATM Menu:\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            user.checkBalance();
            break;
        case 2:
            cout << "Enter amount to deposit: ";
            cin >> amount;
            user.deposit(amount);
            break;
        case 3:
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            user.withdraw(amount);
            break;
        case 4:
            cout << " Thank you for using the ATM. Goodbye!\n";
            break;
        default:
            cout << " Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
