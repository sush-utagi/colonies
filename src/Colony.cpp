#include "Colony.h"
#include <iostream>

Colony::Colony(Environment* env) : environment(env), idNums(0) {
    // Constructor implementation
    initializeExplored(GetScreenWidth(), GetScreenHeight());
}

void Colony::initialize() {
    // Initialize the colony with 10 ants
    for (int i = 0; i < 100; i++) {
        int newId = idNums;
        ants.push_back(Ant(newId, GetScreenWidth()/2, GetScreenHeight()/2));
        idNums++;
    }
}

void Colony::runSimulation() {
    std::cout << "Simulation started >>>" << std::endl;
}

void Colony::draw()
{
    // Draw the colony
    for (Ant& ant : ants) {
        ant.draw();
    }
}

void Colony::updateColony() {
    int numDead = 0;

    // Iterate through each ant in the colony
    for (Ant& ant : ants) {
        ant.move();           // Move the ant
        ant.lifeSpan--;       // Decrease the lifespan

        // update the explored vector
        if (ant.getX() >= 0 && ant.getX() < GetScreenWidth() && ant.getY() >= 0 && ant.getY() < GetScreenHeight()) {
            explored[ant.getY()][ant.getX()] = 1;
        }
    }

    for (Ant& ant : ants) {
        if (ant.lifeSpan <= 0) {
            ants.erase(std::remove(ants.begin(), ants.end(), ant), ants.end());
            numDead++;
        }
    }

    replenishColony(numDead);
}

void Colony::replenishColony(int numAnts) {
    // Replenish the colony with new ants
    for (int i = 0; i < numAnts; i++) {
        int newid = idNums;
        ants.push_back(Ant(newid, GetScreenWidth()/2, GetScreenHeight()/2));
        idNums++;

        // std::cout << "Ant replenished" << std::endl;
    }
}


void Colony::initializeExplored(int width, int height) {
    explored.resize(height);  // Resize the vector to the height of the screen
    for (auto& row : explored) {
        row.resize(width, 0);  // Resize each row to the width of the screen and initialize with 0
    }

    // Set the center of the screen as explored
    explored[GetScreenHeight()/2][GetScreenWidth()/2] = 1;
}

int Colony::calculatePercentageExplored() {
    int totalCells = GetScreenWidth() * GetScreenHeight();
    int exploredCells = 0;

    for (auto& row : explored) {
        for (int cell : row) {
            if (cell == 1) {
                exploredCells++;
            }
        }
    }

    return (exploredCells * 100) / totalCells;
}
