#include "src/includes.h"
#include "src/globalvars.h"

// Data
extern int windowWidth;
extern int windowHeight;
extern Color backgroundColor; 

int main() {

    // Declarations 
    Node *root = new Node();
    Player *player = new Player({windowWidth / 2, windowHeight / 2}, {0, 0}, 
                                {windowWidth / 2, windowHeight / 2, 25}, {windowWidth / 2, windowHeight / 2, 40, 20}, 100, 100);
    root->addChild(player);

    // Init
    InitWindow(windowWidth, windowHeight, "ship game");
    root->init();

    // Loop
    while (WindowShouldClose() == false) {
        // Update
        root->update(GetFrameTime());

        // Draw
        BeginDrawing();
        ClearBackground(backgroundColor);
        
        root->draw();

        EndDrawing();
    }

    // Finish
    CloseWindow();
}