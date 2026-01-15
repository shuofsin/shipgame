#include <complex>
#include <raylib.h>
#include <raymath.h>
#include <cstdio>

void debug(bool isDebug);

int main() {

    // Declarations
    int windowWidth = 640;
    int windowHeight = 480;
    Color backgroundColor = DARKBLUE;

    struct collision_struct {
        float radius;
        Color color;
    } typedef collision_shape;

    struct player_boat_struct {
        Vector2 position;
        Vector2 velocity;
        float moveSpeed;
        float turnSpeed;
        float angle;
        collision_shape collision;
    } typedef player_boat;

    // Init
    InitWindow(windowWidth, windowHeight, "ship game");
    player_boat boat = {{windowWidth / 2.0f, windowHeight / 2.0f}, {0, 0}, 100, 50, 0, {25, {0, 0, 255, 175}}};
    Rectangle boat_rect = {boat.position.x, boat.position.y, 40, 20};
    Rectangle island = {windowWidth / 4.0f, windowHeight / 4.0f, 50, 50};
    Vector2 island_to_boat = Vector2(0, 0);

    // Loop
    while (WindowShouldClose() == false) {
        // Update
        int turnDirection = IsKeyDown(KEY_A) - IsKeyDown(KEY_D);
        boat.angle += /*IsKeyDown(KEY_W) * */turnDirection * boat.turnSpeed * GetFrameTime();
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

        // Check if colliding, if so, bounce
        if (CheckCollisionCircleRec(boat.position, boat.collision.radius, island)) {
            island_to_boat = Vector2Subtract(boat.position, Vector2(island.x, island.y));
            boat.velocity = Vector2Add(boat.velocity, island_to_boat);
        }

        // Draw
        BeginDrawing();
        ClearBackground(backgroundColor);

        // Draw boat
        boat_rect = {boat.position.x, boat.position.y, 40, 20};
        DrawRectanglePro(boat_rect, Vector2(20, 10), boat.angle, WHITE);
        DrawCircle(boat.position.x, boat.position.y, boat.collision.radius, boat.collision.color);

        // Draw island
        DrawRectangleRec(island, BROWN);

        // debug
        if (false) {
            char str[32];
            sprintf(str, "Debug");
            DrawText(str, 0, 0, 20, WHITE);
        }

        EndDrawing();
    }

    // Finish
    CloseWindow();
}