/*
Name: Bohdan Andrashko
Task: Assignment 2
Due: Mar 21, 2025
Course section: CIS121-703
Name of the program: bankingSystem.cpp
Purpose of the program: Banking System Simulator that lets user create an account, deposit, withdraw, and check balance. 
*/


#include <iostream>
using namespace std;

// Variables
string name; // to store user's name
int choice; // to store user's menu choice
double balance = 0.0; // to store user's account balance

// Function prototypes
int createAccount();
int deposit();
int withdraw();
void checkBalance();

int main() {
    
    cout << "Welcome to the Sunrise Banking System! \n" << endl;

    
    createAccount(); // call create account function

    // Menu 
    do {
        cout << "\nMenu:" << endl;
        cout << "1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Check Balance" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                deposit(); // call deposit function
                break;
            case 2:
                withdraw(); // call withdraw function
                break;
            case 3:
                checkBalance(); // call check balance function
                break;
            case 4:
                cout << "\nThank you for using the Sunrise Banking System. Goodbye!" << endl;
                break;
            default:
                cout << "\nInvalid choice. Please try again." << endl;
        }
    } while (choice != 4);




    return 0;
}


// Create account function
int createAccount(){
    cout << "Please create a new account: " << endl;
    cout << "Enter your name: ";
    cin >> name;
    cout << "\nEnter your initial deposit: ";
    cin >> balance;
    cout << "\nAccount created successfully!" << endl;
    return 0;
}


// Deposit function
int deposit() {
    double amount;
    cout << "Enter the amount to deposit: ";
    cin >> amount;
    if (amount > 0) {
        balance += amount;
        cout << "\nDeposited: $" << amount << endl;
    } else {
        cout << "\nInvalid deposit amount." << endl;
    }
    return 0;
}


// Withdraw function
int withdraw() {
    double amount;
    cout << "Enter the amount to withdraw: ";
    cin >> amount;
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        cout << "\nWithdrawn: $" << amount << endl;
    } else {
        cout << "\nInvalid withdrawal amount or insufficient funds." << endl;
    }
    return 0;
}

void checkBalance() {
    cout << "\nCurrent balance: $" << balance << endl;
}
// End of program
