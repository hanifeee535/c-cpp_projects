/*
    Simple library
    Author: Soyabbir Abu Hanif
    Master's in Embedded  Systems
    Tampere University, Finland
    mdsoyabbir.abuhanif@tuni.fi
*/



#ifndef BOOK_HH
#define BOOK_HH

#include "date.hh"
#include <string>

class Book {
public:
    // Constructor
    Book(const std::string& author, const std::string& title);

    // Destructor
    ~Book();

    // Loan the book on a specific date
    void loan(const Date& loan_date);

    // Renew the loan if possible
    void renew();

    // Give back the book
    void give_back();

    // Print information about the book
    void print() const;

private:
    // Attributes
    std::string author_;
    std::string title_;
    bool is_loaned_;
    Date loan_date_;
    Date due_date_;

    // Helper function to check if a book can be loaned or renewed
    bool can_be_loaned_or_renewed() const;
};

#endif // BOOK_HH
