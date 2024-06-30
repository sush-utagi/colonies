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
    const int screenHeight = 650;

    InitWindow(screenWidth, screenHeight, "Ants");
    SetTargetFPS(60);

    Environment environment = Environment();
    Colony colony(&environment);

    // Initialize and run the simulation
    colony.initialize();
    colony.runSimulation();
    //--------------------------------------------------------------------------------------

    bool isPaused = false; // Persistent pause state

    while (!WindowShouldClose()) {
        // Check if the space bar is pressed and toggle the game pause state
        if (IsKeyPressed(KEY_SPACE)) {
            isPaused = !isPaused;
        }

        if (!isPaused) {
            // Update
            //----------------------------------------------------------------------------------
            ClearBackground(BLACK);
            colony.updateColony();
            //----------------------------------------------------------------------------------
        }

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        environment.drawFoodImage();
        colony.draw();

        std::string percentageExplored = "Percentage Explored: " + std::to_string(colony.calculatePercentageExplored()) + "%";
        std::string numLivingAnts = "Number of Living Ants: " + std::to_string(colony.getNumAliveAnts());
        DrawText(numLivingAnts.c_str(), 10, 50, 20, WHITE);
        DrawText(percentageExplored.c_str(), 10, 10, 20, WHITE);

        // Check if the "M" key is held down and call drawExplored function
        if (IsKeyDown(KEY_M)) {
            colony.drawExplored();
        }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    CloseWindow(); // Close window and OpenGL context
    return 0;
}
