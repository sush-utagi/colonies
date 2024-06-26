#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <raylib.h>

class Environment {
public:
    Environment();
    void update();
    void drawFoodImage();
    // Environment-related methods

private:
    // Environment-related properties
    Texture2D foodImage;



};

#endif // ENVIRONMENT_H
