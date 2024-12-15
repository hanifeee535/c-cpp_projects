/*
    Basic Banking System
    Author: Soyabbir Abu Hanif
    Master's in Embedded  Systems
    Tampere University, Finland
    mdsoyabbir.abuhanif@tuni.fi
*/


#include "accounts.hh"
#include <iostream>
//#include <fstream>
//#include <sstream>
#include <string>
#include <vector>


//function to print options:
void print_options (){
    std::cout << "********************************" <<std::endl;
    std::cout << "Please enter one of your options below: " <<std::endl;
    std::cout << "1. Show account status " <<std::endl;
    std::cout << "2. Withdraw Money " <<std::endl;
    std::cout << "3. Deposite money " <<std::endl;
    std::cout << "4. Transfer Money " <<std::endl;
    std::cout << "5. Switch account " <<std::endl;
    std::cout << "0. Exit " <<std::endl;
}

// Function to find an account based on the last two digits of the IBAN
int find_account_by_last_two_digits(const std::vector<Account*>& accounts, const std::string& last_two_digits, bool& account_found) {
    int tmp_account_index =-1;
    for (Account* account:accounts){
        if(last_two_digits == account->iban()){
            tmp_account_index= std::stoi(last_two_digits)-1;
            //cout <<account_index<<endl;
            account_found = true;
            break;
       }

    }
    return tmp_account_index;
}


int main()
{
    int options;
    int account_index = -1;
    int transfer_index;
    double withdraw_ammount, deposit_amount, transfer_amount;

    std::string last_two_digit;
    std::string targeted_last_two_digit;
    std::string switch_account_last_two_digit;

    bool account_found = false;
    bool transfer_possible  = false ;

    //creating multiple account instances:
    Account account1("S. A. Hanif", true);
    Account account2 ("Bob Marle");
    Account account3 ("John Denver", true);
    Account account4 ("Chester Bennington");



    //credit card limit setting for accounts:
    account1.set_credit_limit(1000);
    account2.set_credit_limit(1500);


    //creating a dynamic array of the account objects:
    std::vector <Account*> accounts = {&account1, &account2, &account3, &account4};

    // Keep asking for a valid IBAN until the user enters a correct one
       do {
           std::cout << "Please enter the last two digits of the IBAN number of the account: " << std::endl;
           std::getline(std::cin, last_two_digit);
           account_index = find_account_by_last_two_digits(accounts, last_two_digit, account_found);

           if (!account_found) {
               std::cout << "Invalid IBAN! Please try again." << std::endl;
           }
       } while (!account_found);



       do{
           //printing the menu options:
           print_options();
           std::cin >>options;
           //validating input:
           std::cin.clear();
           std::cin.ignore();

           switch (options) {
           case 1: //showing account details and balance
               accounts[account_index]->print();
               break;

           case 2: //withdraw money
               std::cout<<"Enter the amount for withdraw: " <<std::endl;
               std::cin >>withdraw_ammount;
               accounts[account_index]->withdraw_money(withdraw_ammount);
               std::cout <<withdraw_ammount<< " euros are withdrawn successfully " <<std::endl;
               break;

           case 3://deposite money
               std::cout<<"Enter the deposit amount: " <<std::endl;
               std::cin >>deposit_amount;
               accounts[account_index]->deposite_money(deposit_amount);
               break;

             case 4: //transfer money to another account
               std::cout <<"Enter the targeted account last two digit" <<std::endl;
               std::cin >>targeted_last_two_digit;
               transfer_index = find_account_by_last_two_digits(accounts, targeted_last_two_digit, account_found);
               std::cout<<"Enter the transfer amount: " <<std::endl;
               std::cin >>transfer_amount;
               transfer_possible = accounts[account_index]->withdraw_money(transfer_amount);
               if(transfer_possible){
                   accounts[transfer_index]->transfer_money(transfer_amount);
               }
               else{
                   std::cout<<"Insufficient credit amount"<<std::endl;
               }

               break;

           case 5:  // Switch account

               std::cout << "Enter the last two digits of the account you want to switch to: " << std::endl;
               std::cin >> switch_account_last_two_digit;
               account_index = find_account_by_last_two_digits(accounts, switch_account_last_two_digit, account_found);
               if (!account_found) {
                   std::cout << "Account not found!" << std::endl;
               }
               break;

           case 0:
               std::cout<< "Thank your for using our banking service" <<std::endl;
               break;

           default:
               std::cout << "Invalid option. Please try again." << std::endl;
               break;

           }



       }while (options != 0);



    return 0;
}
