```markdown
# BankAccount Class

A C++ class for representing and managing a bank account within a banking management system, featuring overloaded operators and the Rule of Three for resource management.

## Data Dictionary

| Attribute           | Data Type     | Description                                           |
|---------------------|---------------|-------------------------------------------------------|
| `accountNumber`     | `std::string` | Unique identifier string for the bank account.        |
| `accountHolderName` | `std::string` | Full name of the person or entity holding the account.|
| `accountBalance`    | `double`      | Current liquid monetary funds stored in the account.  |

## Methods List

| Method Signature                                                                               | Return Type    | Description                                                                         |
|------------------------------------------------------------------------------------------------|----------------|-------------------------------------------------------------------------------------|
| `BankAccount()`                                                                                | (Constructor)  | Default constructor initializing empty strings and a balance of 0.0.                |
| `BankAccount(const std::string& _accountNumber, const std::string& _accountHolderName, double _startingBalance)`| (Constructor)  | Parameterized constructor setting account number, name, and initial balance.        |
| `BankAccount(const BankAccount& other)`                                                        | (Constructor)  | Copy constructor to perform a deep copy of an existing account object.              |
| `~BankAccount()`                                                                               | (Destructor)   | Destructor to handle resource cleanup when an object goes out of scope.             |
| `operator=(const BankAccount& other)`                                                          | `BankAccount&` | Copy assignment operator to safely overwrite an existing object with a deep copy.   |
| `getAccountNumber() const`                                                                     | `std::string`  | Accessor method returning the unique account number.                                |
| `getAccountHolderName() const`                                                                 | `std::string`  | Accessor method returning the account holder's name.                                |
| `getAccountBalance() const`                                                                    | `double`       | Accessor method returning the current account balance.                              |
| `setAccountHolderName(const std::string& name)`                                                | `void`         | Mutator method to update the account holder's name.                                 |
| `operator==(const BankAccount& other) const`                                                   | `bool`         | Returns true if two accounts share the same account number.                         |
| `operator<(const BankAccount& other) const`                                                    | `bool`         | Returns true if this account's balance is less than the other account's balance.    |
| `operator>(const BankAccount& other) const`                                                    | `bool`         | Returns true if this account's balance is greater than the other account's balance. |
| `operator+=(double amount)`                                                                    | `BankAccount&` | Adds funds to the balance directly and returns the modified object.                 |
| `operator-=(double amount)`                                                                    | `BankAccount&` | Subtracts funds directly if sufficient balance exists, returning the object.        |
| `deposit(double amount)`                                                                       | `bool`         | Deposits funds into the account if the amount is positive.                          |
| `withdraw(double amount)`                                                                      | `bool`         | Withdraws funds from the account if positive and sufficient funds exist.            |
| `printAccount(const BankAccount& account)`                                                     | `void` (static)| Prints the formatted details of the provided account to the console.                |
| `createAccountFromInput()`                                                                     | `BankAccount` (static)| Prompts the user for data, creates, and returns a new `BankAccount` object.  |

```