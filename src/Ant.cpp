#include "Ant.h"
#include <iostream>

Ant::Ant(int id) : id(id), x(0), y(0), lifeSpan(rand() % 901 + 100), maxHistory(10){
    // Constructor implementation
    history.push_back({x, y});
}

Ant::Ant(int id, int x, int y) : id(id), x(x), y(y), lifeSpan(rand() % 901 + 100), maxHistory(10){
    // Constructor implementation
}

void Ant::draw()
{
    DrawRectangle(x, y, 4, 4, RED);
}

void Ant::move() {
    int newX, newY;
    bool moved = false;

    for (int attempts = 0; attempts < 10 && !moved; ++attempts) { // Limit the number of attempts to find a new position
        // Generate random values for x and y coordinates
        int randomX = rand() % 3 - 1; // Random value between -1 and 1
        int randomY = rand() % 3 - 1; // Random value between -1 and 1

        // Calculate the new position
        newX = x + randomX;
        newY = y + randomY;

        // Check if the new position is within the window screen bounds and not in the history
        if (newX >= 0 && newX <= GetScreenWidth() && newY >= 0 && newY <= GetScreenHeight() && isValidMove(newX, newY)) {
            x = newX;
            y = newY;
            moved = true; // Successfully moved to a new position

            // Add the new position to history
            history.push_back({x, y});
            if (history.size() > maxHistory) {
                history.pop_front(); // Remove the oldest position if history is too long
            }
        }
    }

    if (!moved) {
        // Handle the case where the ant couldn't find a valid move (optional)
        std::cout << "Ant " << id << " couldn't find a new position to move to." << std::endl;
        lifeSpan = 0; // Kill the ant
    }
}

bool Ant::operator==(const Ant& other) const {
    return id == other.id;
}

bool Ant::isValidMove(int newX, int newY) {
    // Check if the new position is in the history
    for (const auto& pos : history) {
        if (pos.first == newX && pos.second == newY) {
            return false; // Position is in history, not a valid move
        }
    }
    return true;
}
