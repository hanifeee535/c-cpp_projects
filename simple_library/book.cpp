/*
    Simple library
    Author: Soyabbir Abu Hanif
    Master's in Embedded  Systems
    Tampere University, Finland
    mdsoyabbir.abuhanif@tuni.fi
*/



#include "book.hh"
#include <iostream>

Book::Book(const std::string& author, const std::string& title)
    : author_(author), title_(title), is_loaned_(false) {
}

Book::~Book() {
}

void Book::loan(const Date& loan_date) {
    if (!is_loaned_) {
        is_loaned_ = true;
        loan_date_ = loan_date;
        due_date_ = loan_date_;
        due_date_.advance(28);
        std::cout << "Loaned: ";
        loan_date_.print();
        std::cout << "To be returned: ";
        due_date_.print();
    } else {
        std::cout << "Already loaned: cannot be loaned" << std::endl;
    }
}

void Book::renew() {
    if (can_be_loaned_or_renewed()) {
        due_date_.advance(28);
        std::cout << "Renewed: new due date is ";
        due_date_.print();
    } else {
        std::cout << "Not loaned: cannot be renewed" << std::endl;
    }
}

void Book::give_back() {
    if (is_loaned_) {
        is_loaned_ = false;
        std::cout << "Book has been returned" << std::endl;
    } else {
        std::cout << "Not loaned: cannot be returned" << std::endl;
    }
}

void Book::print() const {
    std::cout << author_ << " : " << title_ << std::endl;
    if (is_loaned_) {
        std::cout << "- loaned: ";
        loan_date_.print();
        std::cout << "- to be returned: ";
        due_date_.print();
    } else {
        std::cout << "- available" << std::endl;
    }
}

bool Book::can_be_loaned_or_renewed() const {
    return is_loaned_;
}
