#include "global.h"

void debug(bool isDebug);

void init();

int main() {

    // Declarations
    int windowWidth = 640;
    int windowHeight = 480;
    Color backgroundColor = DARKBLUE;
    int score = 0;
    bool spawnItems = false;

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

    struct water_struct {
        Vector2 position;
        Vector2 velocity;
        float moveSpeed;
        float turnSpeed;
        float angle;
        collision_shape collision;
        player_boat player;
    } typedef debris;

    struct target_struct {
        Vector2 position;
        collision_shape collision;
    } typedef target;

    bool isAttached = false;
    Vector2 boat_to_debris = Vector2Zero();

    // Init
    InitWindow(windowWidth, windowHeight, "ship game");
    player_boat boat = {{windowWidth / 2.0f, windowHeight / 2.0f}, {0, 0}, 100, 75, 0, {25, {0, 0, 255, 175}}};
    Rectangle boat_rect = {boat.position.x, boat.position.y, 40, 20};
    Rectangle island = {windowWidth / 4.0f, windowHeight / 4.0f, 50, 50};
    Vector2 island_to_boat = Vector2Zero();

    debris newDebris = {{windowWidth / 4.0f * 3, windowHeight / 4.0f}, {0, 0}, 0, 0, 0, {25, {0, 0, 255, 175}} };

    target newTarget = {{windowWidth / 4.0f, windowHeight / 4.0f * 3}, {30, {0, 175, 0, 75}}};

    // Loop
    while (WindowShouldClose() == false) {
        // Update
        int turnDirection = IsKeyDown(KEY_D) - IsKeyDown(KEY_A);
        boat.angle += turnDirection * boat.turnSpeed * GetFrameTime();
        float dx = boat.moveSpeed * cos(boat.angle*DEG2RAD);
        float dy = boat.moveSpeed * sin(boat.angle*DEG2RAD);

        if (IsKeyDown(KEY_W)) {
            boat.velocity.x = Lerp(boat.velocity.x, dx, 1 - pow(0.5f, GetFrameTime() * 0.8f));
            boat.velocity.y = Lerp(boat.velocity.y, dy, 1 - pow(0.5f, GetFrameTime() * 0.8f));
        } else {
            boat.velocity.x = Lerp(boat.velocity.x, 0, 1 - pow(0.5f, GetFrameTime() * 0.8f));
            boat.velocity.y = Lerp(boat.velocity.y, 0, 1 - pow(0.5f, GetFrameTime() * 0.8f));
        }

        boat.position.x += boat.velocity.x * GetFrameTime();
        boat.position.y += boat.velocity.y * GetFrameTime();

        // Check if colliding, if so, bounce
        if (CheckCollisionCircleRec(boat.position, boat.collision.radius, island)) {
            island_to_boat = Vector2Subtract(boat.position, {island.x, island.y});
            boat.velocity = Vector2Add(boat.velocity, island_to_boat);
        }

        if (CheckCollisionCircles(boat.position, boat.collision.radius, newDebris.position, newDebris.collision.radius)) {
            Vector2 collisionVector = Vector2Subtract(boat.position, newDebris.position);
            boat.velocity = Vector2Add(boat.velocity, collisionVector);
        }

        if (CheckCollisionPointCircle(newDebris.position, newTarget.position, newTarget.collision.radius)) {
            score += 1;
            int new_x, new_y;
            do {
                isAttached = false;
                new_x = rand() % ((windowWidth - 25) - (25) + 1) + 25;
                new_y = rand() % ((windowHeight - 25) - (25) + 1) + 25;
                newDebris.position.x = new_x;
                newDebris.position.y = new_y;
                newDebris.velocity = Vector2Zero();
            } while (CheckCollisionCircles(boat.position, boat.collision.radius, newDebris.position,
                                            newDebris.collision.radius));
            do {
                new_x = rand() % ((windowWidth - 25) - (25) + 1) + 25;
                new_y = rand() % ((windowHeight - 25) - (25) + 1) + 25;
                newTarget.position.x = new_x;
                newTarget.position.y = new_y;
            } while (CheckCollisionCircles(newTarget.position, newTarget.collision.radius, newDebris.position,
                                            newDebris.collision.radius));
            do {
                new_x = rand() % ((windowWidth - 25) - (25) + 1) + 25;
                new_y = rand() % ((windowHeight - 25) - (25) + 1) + 25;
                island.x = new_x;
                island.y = new_y;
            } while (CheckCollisionCircleRec(boat.position, boat.collision.radius, island)
                || CheckCollisionCircleRec(newTarget.position, newTarget.collision.radius, island)
                || CheckCollisionCircleRec(newDebris.position, newDebris.collision.radius, island));
        }


        boat_to_debris = Vector2Subtract(boat.position, newDebris.position);
        if (((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointCircle(GetMousePosition(), newDebris.position, 20))
            || IsKeyPressed(KEY_SPACE)) && (Vector2Length(boat_to_debris) < 125)) {
            isAttached = !isAttached;
        }

        if (isAttached && Vector2Length(boat_to_debris) > 100) {
            float dx = boat_to_debris.x;
            float dy = boat_to_debris.y;
            newDebris.velocity.x = Lerp(newDebris.velocity.x, dx, 1 - pow(0.5f, GetFrameTime() * 0.9f));
            newDebris.velocity.y = Lerp(newDebris.velocity.y, dy, 1 - pow(0.5f, GetFrameTime() * 0.9f));
        } else {
            newDebris.velocity.x = Lerp(newDebris.velocity.x, 0, 1 - pow(0.5f, GetFrameTime() * 0.9f));
            newDebris.velocity.y = Lerp(newDebris.velocity.y, 0, 1 - pow(0.5f, GetFrameTime() * 0.9f));
        }

        newDebris.position.x += newDebris.velocity.x * GetFrameTime();
        newDebris.position.y += newDebris.velocity.y * GetFrameTime();

        // Draw
        BeginDrawing();
        ClearBackground(backgroundColor);

        // Draw boat
        boat_rect = {boat.position.x, boat.position.y, 40, 20};
        DrawRectanglePro(boat_rect, {20, 10}, boat.angle, WHITE);
        DrawCircle(boat.position.x, boat.position.y, boat.collision.radius, boat.collision.color);

        // Draw island
        DrawRectangleRec(island, BROWN);

        // Draw debris
        DrawCircle(newDebris.position.x, newDebris.position.y, 20, GREEN);
        DrawCircle(newDebris.position.x, newDebris.position.y, newDebris.collision.radius, newDebris.collision.color);

        // Draw Target
        DrawCircle(newTarget.position.x, newTarget.position.y, newTarget.collision.radius, newTarget.collision.color);

        // Draw connection
        if (isAttached) DrawLineV(boat.position, newDebris.position, RED);

        char str[32];
        sprintf(str, "Cargo Moved: %d", score);
        DrawText(str, windowWidth / 2 - 75, 0, 20, BLACK);

        // debug
        if (false) {
            char str[32];
            sprintf(str, "Angle: %f", newDebris.angle*RAD2DEG);
            DrawText(str, 0, 0, 20, WHITE);

            DrawLineV(Vector2Zero(), boat.position, RED);
            DrawLineV(Vector2Zero(), newDebris.position, YELLOW);
            DrawLineV(newDebris.position, boat.position, GREEN);
        }

        EndDrawing();
    }

    // Finish
    CloseWindow();
}