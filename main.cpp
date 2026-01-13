#include <complex>
#include <raylib.h>

int main() {

    // Declarations
    int windowWidth = 640;
    int windowHeight = 480;
    Color backgroundColor = DARKBLUE;

    struct player_boat_struct {
        Vector2 position;
        Vector2 velocity;
        float moveSpeed;
        float turnSpeed;
        float angle;
    } typedef player_boat;

    // Init
    InitWindow(windowWidth, windowHeight, "ship game");
    player_boat boat = {{windowWidth / 2.0f, windowHeight / 2.0f}, {0, 0}, 100, 100, 0};

    // Loop
    while (WindowShouldClose() == false) {
        // Update
        int turnDirection = IsKeyDown(KEY_A) - IsKeyDown(KEY_D);
        boat.angle += turnDirection * boat.turnSpeed * GetFrameTime();
        boat.velocity.x = boat.moveSpeed * sin(boat.angle*DEG2RAD);
        boat.velocity.y = boat.moveSpeed * cos(boat.angle*DEG2RAD);

        boat.position.x += IsKeyDown(KEY_W) * boat.velocity.x * GetFrameTime();
        boat.position.y += IsKeyDown(KEY_W) * boat.velocity.y * GetFrameTime();


        // Draw
        BeginDrawing();
        ClearBackground(backgroundColor);
        Rectangle rect = {boat.position.x, boat.position.y, 40, 20};
        DrawRectanglePro(rect, Vector2(20, 10), boat.angle, WHITE);
        EndDrawing();
    }

    // Finish
    CloseWindow();
}