/*
    Basic Banking System
    Author: Soyabbir Abu Hanif
    Master's in Embedded  Systems
    Tampere University, Finland
    mdsoyabbir.abuhanif@tuni.fi
*/

#ifndef ACCOUNTS_HH
#define ACCOUNTS_HH
#include <string>


class Account {
public:
    //constructor:
    Account (const std::string& owner, bool has_credit = false);

    //core functionality for the account
    void deposite_money (double amount);
    bool withdraw_money (double amount);
    void transfer_money( double amount);
    void set_credit_limit (double limit);
    void print() const;
   std::string iban();


private:
    //function to generate IBAN
    void generate_iban();

    //member variable:
    std::string owner_;
    std::string iban_;
    double balance_;
    bool has_credit_;
    double credit_limit_;

    //static attribute for IBAN.
    //Purpose: to ensure unique iban
    static int running_number_;
};

#endif // ACCOUNTS_HH
