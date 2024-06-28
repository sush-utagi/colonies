#include "Colony.h"
#include <iostream>

Colony::Colony(Environment* env) : environment(env), idNums(0) {
    // Constructor implementation
    initializeExplored(GetScreenWidth(), GetScreenHeight());
}

void Colony::initialize() {
    // Initialize the colony with 10 ants
    for (int i = 0; i < 150; i++) {
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
        traverseExplored(ant);

        if (ant.lifeSpan > 0) {
            ant.move();
            ant.lifeSpan--; // Decrease the lifespan

            // Update the explored vector and transposed explored vector
            if (ant.getX() >= 0 && ant.getX() < GetScreenWidth() && ant.getY() >= 0 && ant.getY() < GetScreenHeight()) {
                explored[ant.getY()][ant.getX()] = 1;
                transposedExplored[ant.getX()][ant.getY()] = 1;
            }
        }
    }

    // Remove dead ants from the vector
    auto new_end = std::remove_if(ants.begin(), ants.end(), [](const Ant& ant) {
        return ant.lifeSpan <= 0;
    });

    numDead = std::distance(new_end, ants.end());
    ants.erase(new_end, ants.end());

    std::cout << "Ants dead: " << numDead << std::endl;

    replenishColony(numDead);
}


void Colony::replenishColony(int numAnts) {
    // Replenish the colony with new ants
    for (int i = 0; i < numAnts; i++) {
        int newid = idNums;
        ants.push_back(Ant(newid, GetScreenWidth()/2, GetScreenHeight()/2));
        idNums++;

        std::cout << "Ant replenished current count: " << (int)ants.size() << std::endl;

    }
}

enum Direction {
    LEFT,
    RIGHT,
    UP,
    DOWN
};

std::pair<int, int> Colony::calculateAntNextPosition(Ant& ant)
{
    int antX = ant.getX();
    int antY = ant.getY();

    Direction randomDirection = static_cast<Direction>(rand() % 4);
    int nextX = antX; // Default to current position if no suitable position is found
    int nextY = antY;

    // Evaluate direction and find the new position
    switch (randomDirection) {
        case LEFT:
            // Start from the beginning of the row to current X position, find the first '1'
            for (int x = 0; x < antX; ++x) {
                if (explored[antY][x]) {
                    nextX = x; // Found the leftmost explored cell
                    break; // Exit once the first '1' is found
                }
            }
            break;
        case RIGHT:
            // Start from current X position to the end of the row, find the first '1'
            for (int x = (explored[0].size()-1); x > antX; x--) {
                if (explored[antY][x]) {
                    nextX = x;
                    break;
                }
            }
            break;
        case UP:
            // Start from the beginning of the column to current Y position, find the first '1'
            for (int y = 0; y < antY; ++y) {
                if (transposedExplored[antX][y]) {
                    nextY = y;
                    break;
                }
            }
            break;
        case DOWN:
            for (int y = (transposedExplored[0].size()-1); y > antY; y--) {
                if (transposedExplored[antX][y]) {
                    nextY = y;
                    break;
                }
            }
            break;
    }

    // Ensure the ant moves to a valid new position within the boundaries
    if ((nextX >= 0 && nextX < GetScreenWidth()) && (nextY >= 0 && nextY < GetScreenHeight())) {
        return std::make_pair(nextX, nextY);
    }

    // If no valid or new position is found, return the current position
    return std::make_pair(antX, antY);
}

void Colony::traverseExplored(Ant &ant)
{
    int antX = ant.getX();
    int antY = ant.getY();

    Direction randomDirection = static_cast<Direction>(rand() % 4);
    int nextX = antX; // Default to current position if no suitable position is found
    int nextY = antY;

    // Evaluate direction and find the new position
    switch (randomDirection) {
        case LEFT: {
            while(explored[antY][antX] == 1) {
                ant.moveLeft();
                ant.lifeSpan--;
                antX = ant.getX();
            }
            break;
        }
        case RIGHT:
            while(explored[antY][antX] == 1) {
                ant.moveRight();
                ant.lifeSpan--;
                antX = ant.getX();
            }
            break;
        case UP:
            while(explored[antY][antX] == 1) {
                ant.moveUp();
                ant.lifeSpan--;
                antY = ant.getY();
            }
            break;
        case DOWN:
            while(explored[antY][antX] == 1) {
                ant.moveDown();
                ant.lifeSpan--;
                antY = ant.getY();
            }
            break;
    }
}

void Colony::initializeExplored(int width, int height) {
    explored.resize(height);  // Resize the vector to the height of the screen
    for (auto& row : explored) {
        row.resize(width, 0);  // Resize each row to the width of the screen and initialize with 0
    }

    // Set the center of the screen as explored
    explored[width/2][height/2] = 1;
    std::cout << "Explored vector dimensions: " << explored.size() << " rows" << " x " << explored[0].size() << "/row" << std::endl;

    transposedExplored = transpose(explored);
    std::cout << "Transposed explored dimensions: " << transposedExplored.size() << " rows" << " x " << transposedExplored[0].size() << "/row" << std::endl;
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

void Colony::drawExplored()
{
    for (int y = 0; y < GetScreenHeight(); y++) {
        for (int x = 0; x < GetScreenWidth(); x++) {
            if (explored[y][x] == 1) {
                DrawRectangle(x, y, 1, 1, RED);
            }
        }
    }
}

std::vector<std::vector<int>> Colony::transpose(const std::vector<std::vector<int>> &matrix)
{
    if (matrix.empty()) return {}; // Handle empty matrix case
    
    int rows = matrix.size();
    int cols = matrix[0].size();

    // Initialize the transposed vector with dimensions switched
    std::vector<std::vector<int>> transposed(cols, std::vector<int>(rows));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transposed[j][i] = matrix[i][j];
        }
    }

    return transposed;
}



/*

void Colony::updateColony() {
    int numDead = 0;

    // Iterate through each ant in the colony
    for (Ant& ant : ants) {
        // ant.move();           // Move the ant
        std::pair<int, int> nextPos = calculateAntNextPosition(ant);
        if (nextPos.first == ant.getX() && nextPos.second == ant.getY()) {
            ant.move();
        } else {
            ant.moveTo(nextPos.first, nextPos.second);
            ant.lifeSpan--;       // Decrease the lifespan
            std::cout << "Ant " << ant.getId() << " moved to (" << ant.getX() << ", " << ant.getY() << ")" << std::endl;
        }

        // update the explored vector and transposed explored vector
        if (ant.getX() >= 0 && ant.getX() < GetScreenWidth() && ant.getY() >= 0 && ant.getY() < GetScreenHeight()) {
            explored[ant.getY()][ant.getX()] = 1;
            transposedExplored[ant.getX()][ant.getY()] = 1;
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

*/