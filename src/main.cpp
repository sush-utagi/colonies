#include <iostream>
#include <string>
#include <vector>
#include <raylib.h>
#include "Environment.h"
#include "Colony.h"


int main() {


    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Ants");
    SetTargetFPS(60);

    Environment environment = Environment();
    Colony colony(&environment);

    // Initialize and run the simulation
    colony.initialize();
    colony.runSimulation();


    //--------------------------------------------------------------------------------------

    while (!WindowShouldClose()) 
    {
        // Update
        //----------------------------------------------------------------------------------
        ClearBackground(BLACK);
        colony.updateColony();
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        colony.draw();
        environment.drawFoodImage();

        std::string percentageExplored = "Percentage Explored: " + std::to_string(colony.calculatePercentageExplored()) + "%";
        DrawText(percentageExplored.c_str(), 10, 10, 20, WHITE);

        EndDrawing();
        //----------------------------------------------------------------------------------

    }
    return 0;
}
