#include "Colony.h"
#include <iostream>

Colony::Colony(Environment* env) : environment(env) {
    // Constructor implementation
}

void Colony::initialize() {
    // Initialize the colony with 10 ants
    for (int i = 0; i < 10; i++) {
        ants.push_back(Ant(i, GetScreenWidth()/2, GetScreenHeight()/2));
    }
}

void Colony::runSimulation() {
    // Run the simulation
    // for (int i = 0; i < 100; i++) {
    //     // Move each ant
    //     for (Ant& ant : ants) {
    //         ant.move();
    //     }

    //     // Update the environment
    //     environment->update();
    // }
}

void Colony::draw()
{
    // Draw the colony
    for (Ant& ant : ants) {
        ant.draw();
    }
}

void Colony::updateColony() {
    // Temporary vector to hold dead ants
    std::vector<Ant> deadAnts;
    int numDead = 0;

    // Iterate through each ant in the colony
    for (Ant& ant : ants) {
        ant.move();           // Move the ant
        ant.lifeSpan--;       // Decrease the lifespan

        // Check if the ant's lifespan has reached 0
        if (ant.lifeSpan <= 0) {
            deadAnts.push_back(ant); // Add dead ant to temporary vector
        }
    }

    // Remove dead ants from the colony
    for (Ant& deadAnt : deadAnts) {
        numDead++;
        ants.erase(std::remove(ants.begin(), ants.end(), deadAnt), ants.end());
    }

    replenishColony(numDead);
}

void Colony::replenishColony(int numAnts) {
    // Replenish the colony with new ants
    for (int i = 0; i < numAnts; i++) {
        int newid = rand() % 9000 + 1000;
        ants.push_back(Ant(newid, GetScreenWidth()/2, GetScreenHeight()/2));
    }
}

