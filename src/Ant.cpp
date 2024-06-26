#include "Ant.h"
#include <iostream>

Ant::Ant(int id) : id(id), x(0), y(0), lifeSpan(rand() % 901 + 100){
    // Constructor implementation
    // history.push_back({x, y});
}

Ant::Ant(int id, int x, int y) : id(id), x(x), y(y), lifeSpan(rand() % 901 + 100){
    // Constructor implementation
}

void Ant::draw()
{
    DrawRectangle(x, y, 1, 1, WHITE);
}

void Ant::move() {
    int newX, newY;

    // Generate random values for x and y coordinates
    int randomX = rand() % 3 - 1; // Random value between -1 and 1
    int randomY = rand() % 3 - 1; // Random value between -1 and 1

    // Calculate the new position
    newX = x + randomX;
    newY = y + randomY;

    // Check if the new position is within the window screen bounds and not in the history
    if (newX >= 0 && newX <= GetScreenWidth() && newY >= 0 && newY <= GetScreenHeight()) {
        x = newX;
        y = newY;
    }

    // std::cout << "Ant " << id << " moved to (" << x << ", " << y << ")" << std::endl;
}

void Ant::moveTo(int newX, int newY)
{
    if (newX >= 0 && newX <= GetScreenWidth() && newY >= 0 && newY <= GetScreenHeight()) {
        x = newX;
        y = newY;
    }
}

bool Ant::operator==(const Ant& other) const {
    return id == other.id;
}

