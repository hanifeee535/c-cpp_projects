# Simple Library

## Overview
The **Simple Library** project simulates a basic library system in C++. It contains two main classes: `Date` and `Book`. The `Date` class handles the representation of a date, and the `Book` class represents a library book, including functionality for loaning, renewing, and returning books.

The `Date` class, which is pre-implemented, provides functionality for:
- Managing day, month, and year attributes.
- Advancing dates (e.g., for calculating due dates).
- Validating leap years.

The `Book` class, which is implemented as part of the assignment, provides functionality for:
- Creating and managing books with attributes like author, title, loan status, and due date.
- Loaning a book and automatically calculating the due date (28 days after the loan date).
- Renewing a loan by extending the due date.
- Returning a book and marking it as available again.
- Displaying the status of a book (available or loaned with loan and return dates).

---

## What It Does
This program simulates the basic operations of a library, specifically for managing books:
- **Loaning a Book:** When a book is loaned, the loaning date is recorded, and a due date is set to 28 days after the loaning date. The system prevents books that are already loaned from being loaned again.
- **Renewing a Book:** If a book is loaned, it can be renewed, extending the due date by 28 days.
- **Returning a Book:** A loaned book can be returned, making it available for future loans.
- **Displaying Book Status:** The status of each book is printed, showing whether it is available or loaned with associated dates.

The `Date` class is used for managing dates and advancing them, ensuring that the program correctly calculates due dates and handles the transition of months and years.

---

## Sample Input and Output
Below is an example of how the program behaves when the methods are called:

```plaintext
Author: Kivi
Title: Seitseman veljesta

Initial State:
Kivi : Seitseman veljesta
- available

Loaning the book:
Loaned: 05.05.2020
To be returned: 02.06.2020

Trying to loan a loaned book:
Already loaned: cannot be loaned
Kivi : Seitseman veljesta
- loaned: 05.05.2020
- to be returned: 02.06.2020

Renewing the book:
Renewed: new due date is 30.06.2020
Kivi : Seitseman veljesta
- loaned: 05.05.2020
- to be returned: 30.06.2020

Returning the book:
Book has been returned
Kivi : Seitseman veljesta
- available

Trying to renew an available book:
Not loaned: cannot be renewed
Kivi : Seitseman veljesta
- available

Loaning again (two weeks later):
Loaned: 19.05.2020
To be returned: 16.06.2020
Kivi : Seitseman veljesta
- loaned: 19.05.2020
- to be returned: 16.06.2020

