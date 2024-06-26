#ifndef ANT_H
#define ANT_H

#include <raylib.h>
#include <deque>
#include <utility> // For std::pair


class Ant {
public:
    int lifeSpan;
    
    Ant(int id);
    Ant(int id, int x, int y);

    void draw();
    void move();
    // Other ant-related methods

    bool operator==(const Ant& other) const;


private:
    int id;
    int x;
    int y;
    int maxHistory;
    std::deque<std::pair<int, int>> history; // History of positions

    bool isValidMove(int newX, int newY);

    // Other ant-related properties
};

#endif // ANT_H
// 