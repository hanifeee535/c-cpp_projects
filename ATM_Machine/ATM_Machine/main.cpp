/*
    Basic ATM Machine
    Authure: Soyabbir Abu Hanif
    Master's in Embedded  Systems
    Tampere University, Finland
    mdsoyabbir.abuhanif@tuni.fi
*/

#include <iostream>
#include <iomanip>
using namespace std;

void balance_check(double balance);
double withdraw_money();
double deposit_money();
double balance = 150;

int main() {
    double withdraw_amount, deposit_amount;
    int options;

    do {
        cout << "********************" << endl;
        cout << "Please enter your options below:" << endl;
        cout << "********************" << endl;
        cout << " 1: Balance check" << endl;
        cout << " 2: Withdraw" << endl;
        cout << " 3: Deposit" << endl;
        cout << " 4: Exit" << endl;
        cin >> options;
        //validating input:
        cin.clear();
        cin.ignore();

        switch (options) {
        case 1:
            balance_check(balance);  // Balance check without changing the balance
            break;
        case 2:
            withdraw_amount = withdraw_money();  // Call withdraw function and store return value
            if (withdraw_amount > 0) {  // Check if withdrawal was successful
                balance -= withdraw_amount;  // Update balance after withdrawal
                cout << "Withdraw successful" << endl;  // Message after successful withdrawal
                balance_check(balance);  // Print updated balance
            }
            break;
        case 3:
            deposit_amount = deposit_money();  // Call deposit function and store return value
            if (deposit_amount > 0) {  // Check if deposit was successful
                balance += deposit_amount;  // Update balance after deposit
                cout << "Deposit successful" << endl;  // Message after successful deposit
                balance_check(balance);  // Print updated balance
            }
            break;
        case 4:
            cout << "Thank you for banking with us" << endl;  // Exit message
            break;
        default:
            cout << "Invalid choice" << endl;  // Invalid option
            break;
        }

    } while (options != 4);

    return 0;
}

void balance_check(double curr_balance) {
    cout << "Your balance is: " << setprecision(2) << fixed << curr_balance << endl;
}

double withdraw_money() {
    double amount;
    cout << "How much do you want to withdraw? " << endl;
    cin >> amount;
    if (amount > balance) {
        cout << "Insufficient Balance" << endl;  // Print if withdrawal is not possible
        return 0;  // Return 0 to indicate failure
    }
    else {
        return amount;  // Return valid withdrawal amount
    }
}

double deposit_money() {
    double amount;
    cout << "How much do you want to deposit? " << endl;
    cin >> amount;
    if (amount <= 0) {
        cout << "Please enter a valid amount which is greater than 0" << endl;  // Invalid deposit message
        return 0;  // Return 0 to indicate failure
    }
    else {
        return amount;  // Return valid deposit amount
    }
}
