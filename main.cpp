#include <complex>
#include <raylib.h>
#include <cstdio>

void debug(bool isDebug);
float lerp(float a, float b, float f);

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
    player_boat boat = {{windowWidth / 2.0f, windowHeight / 2.0f}, {0, 0}, 100, 25, 0};

    // Loop
    while (WindowShouldClose() == false) {
        // Update
        int turnDirection = IsKeyDown(KEY_A) - IsKeyDown(KEY_D);
        boat.angle += IsKeyDown(KEY_W) * turnDirection * boat.turnSpeed * GetFrameTime();
        float dx = boat.moveSpeed * cos(boat.angle*DEG2RAD);
        float dy = boat.moveSpeed * sin(boat.angle*DEG2RAD);

        if (IsKeyDown(KEY_W)) {
            boat.velocity.x = lerp(boat.velocity.x, dx, 2 * GetFrameTime());
            boat.velocity.y = lerp(boat.velocity.y, dy, 2 * GetFrameTime());
        } else {
            boat.velocity.x = lerp(boat.velocity.x, 0, 2 * GetFrameTime());
            boat.velocity.y = lerp(boat.velocity.y, 0, 2 * GetFrameTime());
        }

        boat.position.x += boat.velocity.x * GetFrameTime();
        boat.position.y += boat.velocity.y * GetFrameTime();


        // Draw
        BeginDrawing();
        ClearBackground(backgroundColor);
        Rectangle rect = {boat.position.x, boat.position.y, 40, 20};
        DrawRectanglePro(rect, Vector2(20, 10), boat.angle, WHITE);

        // debug
        if (true) {
            char str[32];
            sprintf(str, "Velocity: (%f, %f)", boat.velocity.x, boat.velocity.y);
            DrawText(str, 0, 0, 20, WHITE);
        }

        EndDrawing();
    }

    // Finish
    CloseWindow();
}

float lerp(float a, float b, float f) {
    return a * (1.0f - f) + b * f;
}