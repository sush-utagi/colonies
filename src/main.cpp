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

        EndDrawing();
        //----------------------------------------------------------------------------------

    }
    return 0;
}
