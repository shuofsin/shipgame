#include "src/headers/mainincludes.h"

void debug(bool isDebug);

void init();

int main() {

    // Declarations
    int windowWidth = 640;
    int windowHeight = 480;
    Color backgroundColor = DARKBLUE;
    Player *player = new Player({windowWidth / 2, windowHeight / 2}, {0, 0}, 
                                {windowWidth / 2, windowHeight / 2, 25}, {windowWidth / 2, windowHeight / 2, 40, 20}, 100, 100);


    // Init
    InitWindow(windowWidth, windowHeight, "ship game");
    player->init();

    // Loop
    while (WindowShouldClose() == false) {
        // Update
        player->update(GetFrameTime());

        // Draw
        BeginDrawing();
        ClearBackground(backgroundColor);
        player->draw();

        EndDrawing();
    }

    // Finish
    CloseWindow();
}