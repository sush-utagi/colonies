#include "Ant.h"
#include <iostream>

Ant::Ant(int id) : id(id), x(0), y(0), lifeSpan(rand() % 901 + 100) {
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
    } else {
        lifeSpan = 0;
        // x = GetScreenWidth() / 2;
        // y = GetScreenHeight() / 2;
    }

    // std::cout << "Ant " << id << " moved to (" << x << ", " << y << ")" << std::endl;
}

void Ant::moveTo(int newX, int newY)
{
    if (newX >= 0 && newX <= GetScreenWidth() && newY >= 0 && newY <= GetScreenHeight()) {
        x = newX;
        y = newY;
    } else {
        x = GetScreenWidth() / 2;
        y = GetScreenHeight() / 2;
        lifeSpan = 0;
    }
}

void Ant::moveLeft()
{
    if (x > 0) x--;
    else {
        moveRight();
        // x = GetScreenWidth()/2;
        // lifeSpan = 0;
    }
}

void Ant::moveRight()
{
    if (x < GetScreenWidth()) x++;
    else {
        moveLeft();
        // x = GetScreenWidth()/2;
        // lifeSpan = 0;
    }
}

void Ant::moveUp()
{
    if (y > 0) y--;
    else {
        moveDown();
        // y = GetScreenHeight()/2;
        // lifeSpan = 0;
    }
}

void Ant::moveDown()
{
    if (y < GetScreenHeight()) y++;
    else {
        moveUp();
        // y = GetScreenHeight()/2;
        // lifeSpan = 0;
    }
}

void Ant::moveUpLeft()
{
    if (x > 0 && y > 0) {
        x--;
        y--;
    } else {
        moveDownRight();
        // x = GetScreenWidth()/2;
        // y = GetScreenHeight()/2;
        // lifeSpan = 0;
    }
}

void Ant::moveUpRight()
{
    if (x < GetScreenWidth() && y > 0) {
        x++;
        y--;
    } else {
        moveDownLeft();
        // x = GetScreenWidth()/2;
        // y = GetScreenHeight()/2;
        // lifeSpan = 0;
    }
}

void Ant::moveDownLeft()
{
    if (x > 0 && y < GetScreenHeight()) {
        x--;
        y++;
    } else {
        moveUpRight();
        // x = GetScreenWidth()/2;
        // y = GetScreenHeight()/2;
        // lifeSpan = 0;
    }
}

void Ant::moveDownRight()
{
    if (x < GetScreenWidth() && y < GetScreenHeight()) {
        x++;
        y++;
    } else {
        moveUpLeft();
        // x = GetScreenWidth()/2;
        // y = GetScreenHeight()/2;
        // lifeSpan = 0;
    }
}

bool Ant::operator==(const Ant& other) const {
    return id == other.id;
}

