# Banking System Simulation in C++

## Project Overview
This project is a simple **Banking System Simulation** written in C++. It allows users to perform basic banking operations, such as viewing account details, depositing money, withdrawing money, transferring funds between accounts, and switching accounts. 

The program provides a text-based interface where users can interact with multiple bank accounts. Each account has attributes such as a name, balance, credit limit, and IBAN (International Bank Account Number). The application uses modern C++ features and object-oriented programming principles.

---

## Features
1. **View Account Details**  
   Users can check the account balance, name, credit limit, and activation status.

2. **Deposit Money**  
   Users can deposit funds into their account. 

3. **Withdraw Money**  
   Users can withdraw funds, either from their balance or using a credit limit if the balance is insufficient.

4. **Transfer Money**  
   Users can transfer money from one account to another by providing the last two digits of the target account's IBAN.

5. **Switch Accounts**  
   Users can switch between different accounts by entering the IBAN digits of the account they want to access.

6. **Error Handling**  
   - Ensures valid IBANs are selected for operations.
   - Handles insufficient funds or invalid operations gracefully.
   - Provides feedback for invalid user inputs.

---

## Algorithm Description
1. **Initialization**:  
   - Four bank accounts are created and stored in a `std::vector`. Each account is initialized with attributes such as the owner's name, balance, credit limit, and activation status.

2. **Menu System**:  
   - The user is prompted with options to perform banking operations (view, deposit, withdraw, transfer, switch account, or exit).
   - Input validation is performed to ensure valid options are chosen.

3. **Account Lookup**:  
   - A function (`find_account_by_last_two_digits`) is implemented to search for an account based on the last two digits of its IBAN. If the account is found, its index is returned. Otherwise, an error is displayed.

4. **Transactions**:
   - **Deposit**: The balance of the account is updated.
   - **Withdraw**: The balance is reduced, and if insufficient, the credit limit is used.
   - **Transfer**: Money is deducted from the source account and added to the target account.

5. **Switching Accounts**:  
   - Allows the user to switch between accounts by entering the IBAN digits of the desired account.

6. **Error Handling and Loops**:  
   - The program ensures that invalid IBANs or inputs do not cause the program to terminate abruptly. Users are prompted to re-enter valid data in such cases.

---

## Technologies and Concepts Used

1. **Object-Oriented Programming (OOP)**:
   - The `Account` class encapsulates data and functionality related to a bank account.
   - Class attributes like `balance`, `credit_limit`, and `is_active` are managed using private access specifiers and accessed via getter and setter methods.

2. **Standard Template Library (STL)**:
   - **`std::vector`**: Used to store and manage multiple bank accounts dynamically.

3. **Functions**:
   - **`find_account_by_last_two_digits`**: Reusable function to locate an account in the vector based on IBAN digits.
   - Modular functions for deposits, withdrawals, transfers, and other operations.

4. **Input and Output**:
   - Used `std::cin` and `std::cout` for user interaction.
   - Handles input validation and provides meaningful error messages.

5. **Control Structures**:
   - Loops (`do-while` and `for`) for iterating through accounts and menus.
   - `switch-case` statements for menu-driven operations.

6. **Error Handling**:
   - Prevents invalid inputs using checks and feedback.
   - Ensures proper bounds checking for vector operations.

7. **Dynamic Memory Management**:
   - No raw pointers were used; instead, the program utilizes STL containers (`std::vector`) for dynamic memory allocation and management.

---

## How to Run the Program

1. **Compile the Program**:  
   Use any modern C++ compiler (e.g., `g++` or `clang++`) to compile the code. For example:
   ```bash
   g++ main.cpp accounts.cpp -o BankingSystem

