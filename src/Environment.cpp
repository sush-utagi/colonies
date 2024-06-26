#include "Environment.h"

Environment::Environment() {
    // Constructor implementation
    foodImage = LoadTexture("resources/antFood.png");
    drawFoodImage();
}

void Environment::update()
{
    // check if ants are on food
    // if so, remove food and increase ant's health
    // if not, decrease ant's health
    

    
    
}

void Environment::drawFoodImage()
{
    DrawTexture(foodImage, 200, 200, WHITE);
}
