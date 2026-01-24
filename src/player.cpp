//
// Created by shu 1/24/26
//

#include "headers/player.h"

Player::Player() : KinematicBody() {
    texture = {};
    maxSpeed = 0;
    turnSpeed = 0;
    angle = 0;
}

Player::Player(Vector2 _position, Vector2 _velocity, Shape _shape, Rectangle _texture, float _maxSpeed, float _turnSpeed) 
: KinematicBody(_position, _velocity, _shape) {
    texture = _texture; // TODO: Convert to image texture
    maxSpeed = _maxSpeed;
    turnSpeed = _turnSpeed;
    angle = 0;
}

void Player::init() {
    KinematicBody::init();
}

void Player::update(float deltaTime) {
    KinematicBody::update(deltaTime);

    // Get direction
    int turnDirection = IsKeyDown(KEY_D) - IsKeyDown(KEY_A);
    angle += turnDirection * turnSpeed * deltaTime;

    // Move player
    float dx = maxSpeed * cos(angle*DEG2RAD) * IsKeyDown(KEY_W);
    float dy = maxSpeed * sin(angle*DEG2RAD) * IsKeyDown(KEY_W);

    velocity.x = Lerp(velocity.x, dx, 1 - pow(0.5f, GetFrameTime() * 0.8f));
    velocity.y = Lerp(velocity.y, dy, 1 - pow(0.5f, GetFrameTime() * 0.8f));

    if (velocity.x < 5 && !IsKeyDown(KEY_W)) velocity.x = 0;
    if (velocity.y < 5 && !IsKeyDown(KEY_W)) velocity.y = 0;

    KinematicBody::moveAndCollide(deltaTime);
}

void Player::draw() {
    KinematicBody::draw();
    
    // Draw player
    texture = {position.x, position.y, texture.width, texture.height};
    DrawRectanglePro(texture, {texture.width / 2, texture.height / 2}, angle, WHITE);
}