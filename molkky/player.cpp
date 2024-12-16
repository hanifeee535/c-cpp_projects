/*
    molkky
    Author: Soyabbir Abu Hanif
    Master's in Embedded  Systems
    Tampere University, Finland
    mdsoyabbir.abuhanif@tuni.fi
*/


#include "player.hh"
#include <iostream>
#include <cstdlib>

Player::Player(const std::string& name) : name_(name), points_(0) {}

std::string Player::get_name() const {
    return name_;
}

int Player::get_points() const {
    return points_;
}

bool Player::has_won() const {
    return points_ >= 50;
}

void Player::add_points(int points) {
    if (points < 0) {
        // Handle negative points (penalty)
        points_ -= abs(points);
        if (points_ < 0) {
            points_ = 0;
            std::cout << name_ << " gets penalty points!" << std::endl;
        }
    } else {
        // Handle positive points
        points_ += points;

        std::cout << "Scoreboard after turn:" << std::endl;
        std::cout << name_ << ": " << points_ << "p" << std::endl;

        if (has_won()) {
            std::cout << "Game over! The winner is " << name_ << "!" << std::endl;
        }
    }
    // Check for exceeding 50 points and reset to 25 if needed
    if (points_ > 50) {
        points_ = 25;
        std::cout << "Score exceeded 50 points. Reset to 25 points!" << std::endl;
    }
}

