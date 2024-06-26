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

private:
    std::vector<Ant> ants;
    bool foundFood = false;
    int idPool;
    Environment* environment;
};


#endif // COLONY_H
