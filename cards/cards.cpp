/*
    Cards
    Author: Soyabbir Abu Hanif
    Master's in Embedded  Systems
    Tampere University, Finland
    mdsoyabbir.abuhanif@tuni.fi
*/

#include "cards.hh"

// Constructor: Initializes the top card as nullptr.
Cards::Cards(): top_(nullptr)
{
    std::cout << "constructor" << std::endl;
}

// Destructor: Automatically called when the object is destroyed.
Cards::~Cards()
{
    std::cout << "destructor" << std::endl;
    // No need for manual memory management as we're using shared_ptr
}

// Adds a new card with the given id as the topmost element.
void Cards::add(int id)
{
    std::shared_ptr<Card_data> new_card = std::make_shared<Card_data>();
    new_card->data = id;
    new_card->next = top_;  // Link the new card to the current top card
    top_ = new_card;  // Update the top to be the new card
}

// Removes the topmost card and returns its value through the reference id.
// Returns false if the deck is empty.
bool Cards::remove(int& id)
{
    if (top_ == nullptr) {
        return false;  // The deck is empty
    }
    id = top_->data;  // Set the reference to the top card's data
    top_ = top_->next;  // Update the top to the next card in the deck
    return true;
}

// Prints the content of the deck from top to bottom.
void Cards::print_from_top_to_bottom(std::ostream& s)
{
    std::shared_ptr<Card_data> current = top_;
    int index = 1;
    while (current != nullptr) {
        s << index << ": " << current->data << std::endl;
        current = current->next;
        index++;
    }
}

// Recursive helper function for printing the deck from bottom to top.
int Cards::recursive_print(std::shared_ptr<Card_data> card, std::ostream& s)
{
    if (card == nullptr) {
        return 0;  // Base case: empty deck
    }

    int index = recursive_print(card->next, s) + 1;  // Recursive call
    s << index << ": " << card->data << std::endl;  // Print after recursion unwinds
    return index;
}

// Prints the content of the deck from bottom to top.
void Cards::print_from_bottom_to_top(std::ostream& s)
{
    recursive_print(top_, s);
}

// Moves the topmost card to the bottom of the deck.
bool Cards::top_to_bottom()
{
    if (top_ == nullptr || top_->next == nullptr) {
        return false;  // Empty or single card deck doesn't need modification
    }

    std::shared_ptr<Card_data> current = top_;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = top_;  // Link the last card to the current top

    top_ = top_->next;  // Update the top to the second card
    current->next->next = nullptr;  // The old top becomes the last card

    return true;
}

// Reverses the order of the deck.
void Cards::reverse()
{
    if (top_ == nullptr || top_->next == nullptr) {
        return;  // No need to reverse if the deck is empty or has one card
    }

    std::shared_ptr<Card_data> prev = nullptr;
    std::shared_ptr<Card_data> current = top_;
    std::shared_ptr<Card_data> next = nullptr;

    while (current != nullptr) {
        next = current->next;  // Store the next card
        current->next = prev;  // Reverse the pointer
        prev = current;  // Move prev and current forward
        current = next;
    }

    top_ = prev;  // Update top to the new first card
}
