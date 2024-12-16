# Cards Deck Management

## Author: Soyabbir Abu Hanif  
Master's in Embedded Systems  
Tampere University, Finland  
mdsoyabbir.abuhanif@tuni.fi

## Project Overview

This project implements a dynamic card deck using pointers and dynamic memory management in C++. The deck allows for various operations such as adding, removing, moving, reversing, and printing cards. The project aims to help understand dynamic memory management and pointer usage without relying on the C++ Standard Template Library (STL) containers or other high-level features.

### Program Features

1. **Card Deck Operations**:
    - **add(int id)**: Adds a new card with the given integer ID on top of the deck.
    - **remove(int& id)**: Removes the topmost card from the deck and returns its ID via reference.
    - **top_to_bottom()**: Moves the topmost card to the bottom of the deck.
    - **reverse()**: Reverses the order of cards in the deck.
    - **print_from_top_to_bottom(std::ostream& s)**: Prints the cards from top to bottom.
    - **print_from_bottom_to_top(std::ostream& s)**: Prints the cards from bottom to top using recursion.

2. **Dynamic Memory Management**:
    - The deck uses a linked list structure, where each card points to the next card using smart pointers (`std::shared_ptr`), ensuring proper memory management without manual `new` and `delete` calls.
    
3. **Testing**:
    - The functionality of the class is tested using the provided `main.cpp`. The main program allows the user to interact with the deck, adding and removing cards, and printing the results.

---

## Technical Documentation

### Data Structure: `Card_data`
The deck is implemented using a linked list, where each node represents a card. The `Card_data` structure contains:
- **data (int)**: The integer value representing the card ID.
- **next (std::shared_ptr<Card_data>)**: A shared pointer to the next card in the deck.

### Class: `Cards`

#### Member Variables:
- **top_ (std::shared_ptr<Card_data>)**: A shared pointer to the topmost card in the deck. It is initialized to `nullptr`, indicating that the deck is initially empty.

#### Methods:

1. **Constructor: `Cards()`**  
   Initializes the deck with no cards. The top pointer is set to `nullptr`.

2. **Destructor: `~Cards()`**  
   Automatically called when the `Cards` object is destroyed. Due to the use of `std::shared_ptr`, the memory is automatically managed.

3. **add(int id)**  
   Adds a new card with the specified `id` to the top of the deck. This creates a new `Card_data` instance and updates the `top_` pointer.

4. **remove(int& id)**  
   Removes the topmost card from the deck and sets the provided reference `id` to the card's data value. Returns `false` if the deck is empty.

5. **top_to_bottom()**  
   Moves the topmost card to the bottom of the deck. If the deck has fewer than two cards, this operation does nothing.

6. **reverse()**  
   Reverses the order of cards in the deck. It does this by iterating through the deck and changing the `next` pointers to point to the previous card.

7. **print_from_top_to_bottom(std::ostream& s)**  
   Prints the cards in the deck from top to bottom with their ordinal position.

8. **print_from_bottom_to_top(std::ostream& s)**  
   A recursive method that prints the cards in the deck from bottom to top by recursively calling a helper method (`recursive_print`).

9. **recursive_print(std::shared_ptr<Card_data> card, std::ostream& s)**  
   A private recursive helper function used by `print_from_bottom_to_top` to traverse the deck from bottom to top.

---

## Code Walkthrough

### Constructor
The constructor of the `Cards` class initializes the deck to be empty, setting `top_` to `nullptr`.

### Adding Cards
When a card is added, a new `Card_data` instance is created with the specified ID. The new card is linked to the current top card, and the `top_` pointer is updated to point to the new card.

### Removing Cards
To remove a card, the `remove` method checks if the deck is empty by verifying if `top_` is `nullptr`. If the deck is not empty, the data of the top card is saved in the `id` reference, and `top_` is updated to point to the next card.

### Moving Cards (Top to Bottom)
The `top_to_bottom` method moves the topmost card to the bottom. It works by finding the last card in the deck and linking it to the current top card while updating the `top_` pointer to the second card in the deck.

### Reversing the Deck
The `reverse` method reverses the order of cards by iterating through the deck and updating the `next` pointers of the cards to point to the previous card. After all pointers are reversed, the `top_` pointer is updated to point to the new first card.

### Printing Cards
The deck can be printed in two ways:
- **From top to bottom**: The `print_from_top_to_bottom` method iterates through the deck and prints each card along with its ordinal position.
- **From bottom to top**: The `print_from_bottom_to_top` method calls the recursive helper function `recursive_print`, which traverses the deck recursively to print the cards in reverse order.

---


