/*
 * Name: Jason Suits
 * Date: September 27, 2026
 * Assignment: Objects & Classes Lab - Bank Account Management System
 * Purpose: Driver program managing a collection of BankAccount objects using std::vector.
 */
#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "BankAccount.h"

int findAccount(const std::vector<BankAccount>& accounts, const std::string& accountNumber) {
    for (size_t i = 0; i < accounts.size(); ++i) {
        if (accounts[i].getAccountNumber() == accountNumber) {
            return static_cast<int>(i);
        }
    }
    return -1; // Account not found
}

int main() {
    // Your code here
    int userSelection;
    std::vector<BankAccount> accounts;
    std::string accountNumber, accountHolderName;
    double transactionAmount;

    do {
        std::cout << "\nBank Account Management System\n";
        std::cout << "1. Create a new account\n";
        std::cout << "2. Deposit funds\n";
        std::cout << "3. Withdraw funds\n";
        std::cout << "4. Display account balance\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> userSelection;

        switch (userSelection) {
            case 1: {
                BankAccount newAccount = BankAccount::createAccountFromInput();
                accounts.push_back(newAccount);
                std::cout << "Account created successfully.\n";
                break;
            }
            case 2: {
                std::cout << "Enter account number for deposit: ";
                std::cin >> accountNumber;
                int index = findAccount(accounts, accountNumber);
                if (index != -1) {
                    std::cout << "Enter amount to deposit: ";
                    std::cin >> transactionAmount;
                    
                    // NEW: Using the overloaded += operator instead of .deposit()
                    accounts[index] += transactionAmount; 
                    
                    std::cout << "Deposit processed. New balance: $" << accounts[index].getAccountBalance() << "\n";
                } else {
                    std::cout << "Account not found.\n";
                }
                break;
            }
            case 3: {
                std::cout << "Enter account number for withdrawal: ";
                std::cin >> accountNumber;
                int index = findAccount(accounts, accountNumber);
                if (index != -1) {
                    std::cout << "Enter amount to withdraw: ";
                    std::cin >> transactionAmount;
                    
                    // NEW: Using the overloaded -= operator instead of .withdraw()
                    accounts[index] -= transactionAmount; 
                    
                    std::cout << "Withdrawal processed. New balance: $" << accounts[index].getAccountBalance() << "\n";
                } else {
                    std::cout << "Account not found.\n";
                }
                break;
            }
            case 4: {
                std::cout << "Enter account number to display balance: ";
                std::cin >> accountNumber;
                int index = findAccount(accounts, accountNumber);
                if (index != -1) {
                    BankAccount::printAccount(accounts[index]);
                } else {
                    std::cout << "Account not found.\n";
                }
                break;
            }
            case 5:
                std::cout << "Exiting the program.\n";
                break;
        }
    } while (userSelection != 5);

    return 0;
}