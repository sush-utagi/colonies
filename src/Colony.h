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
    std::pair<int, int> calculateAntNextPosition(Ant& ant);
    void traverseExplored(Ant& ant);
    int calculatePercentageExplored();
    void drawExplored();
    int getNumAliveAnts();

private:
    int idNums;
    std::vector<std::vector<int>> explored;
    std::vector<std::vector<int>> transposedExplored;
    std::vector<Ant> ants;
    bool foundFood = false;
    Environment* environment;

    void initializeExplored(int width, int height);
    std::vector<std::vector<int>> transpose(const std::vector<std::vector<int>>& matrix);
};


#endif // COLONY_H
