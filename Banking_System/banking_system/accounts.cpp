/*
    Basic Banking System
    Author: Soyabbir Abu Hanif
    Master's in Embedded  Systems
    Tampere University, Finland
    mdsoyabbir.abuhanif@tuni.fi
*/



#include "accounts.hh"
#include <iostream>

//initial value for the static attribute
int Account::running_number_ = 0;

//constructor setting
Account::Account (const std::string& owner, bool has_credit){
    generate_iban();
    owner_ = owner;
    has_credit_ =has_credit;
    balance_ = 0;
    credit_limit_ = 0;

}

std::string  Account::iban(){
    std::string iban ;
    iban = iban_.substr(iban_.size() - 2);
    //std::cout<<iban;
    return iban;
}

//generating an unique iban for the account holders
//for example: "FI00 1234 00" "FI00 1234 01" ..."FI00 1234 99"
void Account::generate_iban(){
    ++running_number_;
    std::string suffix = "";
    if (running_number_ <10){
        suffix.append("0"); //If the counter is less than 10, a leading zero is added for proper formatting
    }
    else if(running_number_>99){
        std::cout <<"Too many account. Maximum account number is 100"<<std::endl;

    }

    suffix.append(std::to_string(running_number_));

    iban_ = "FI00 1234 ";
    iban_.append(suffix);
}


//save money
void Account::deposite_money(double amount){
    balance_ +=amount;
}

//withdraw money
bool Account::withdraw_money(double amount){
    //validating balance for withdraw:
    //first checks if the account has enough balance
    //if it doesn't have enough balance, it checks if the account
    //has a credit limit and if the balance minus the the withdrawal ammount doesn't
    //cross the credit limit
    if(balance_ >=amount || (has_credit_ && balance_ -amount)>=-credit_limit_){
        balance_ -=amount;
        std::cout<< " New balance of " <<iban_ << " is " << balance_ <<" euros " <<std::endl;
        return true;
    }
    else{
        std::cout << " Can not withdraw money " ;
        if(has_credit_){
            std::cout <<"credit limit overflow"<<std::endl;
        }
        else {
            std::cout << "Insufficient balance"<<std::endl;
        }
        return false;
    }
}


//transfer money from one account to another:
void Account::transfer_money(double amount){
    balance_ += amount;
    std::cout<<amount <<" Euros transfer successfull"<< std::endl;

}

//information of the bank account and balance check:
void Account::print() const{
    std::cout<<"******************************"<<std::endl;
    std::cout <<"Owner: " <<owner_ <<std::endl;
    std::cout << "\t" <<"IBAN: " << iban_ << "\t"  <<"Balance: " << balance_ << " euros" <<std::endl;
    std::cout<<"******************************"<<std::endl;

}

//setting the credit limit
void Account::set_credit_limit(double limit){
    if(has_credit_){
        credit_limit_ = limit;
    }
    else{
        std::cout << "Cannot set credit limit: the account has not credit card" << std::endl;
    }
}
