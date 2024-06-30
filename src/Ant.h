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
    void moveTo(int x, int y);
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    void moveUpLeft();
    void moveUpRight();
    void moveDownLeft();
    void moveDownRight();
    // Other ant-related methods

    int getX() const { return x; }
    int getY() const { return y; }
    int getId() const { return id; }

    bool operator==(const Ant& other) const;


private:
    int id;
    int x;
    int y;

    // Other ant-related properties
};

#endif // ANT_H
// 