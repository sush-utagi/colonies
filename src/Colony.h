#ifndef COLONY_H
#define COLONY_H

#include <vector>
#include "Ant.h"
#include "Environment.h"

class Colony {
public:
    Colony(Environment* env);
    void initialize();
    void runSimulation();
    void draw();
    void updateColony();
    void replenishColony(int numAnts);
    int calculatePercentageExplored();

private:
    int idNums;
    std::vector<std::vector<int>> explored;
    std::vector<Ant> ants;
    bool foundFood = false;
    Environment* environment;

    void initializeExplored(int width, int height);
};


#endif // COLONY_H
