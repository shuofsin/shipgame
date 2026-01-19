//
// Created by shu on 1/14/26.
//

#include "node.h"

/**
 * @brief Default constructor
 */
Node::Node() = default;

/**
 * @brief Initialize all children
 */
void Node::init() {
    for (Node node : children) {
        node.init();
    }
}

/**
 * @brief Update all children
 * @param deltaTime The time between the last frame and the one before it, i.e. the time it took to draw the last frame
 */
void Node::update(float deltaTime) {
    for (Node node: children) {
        node.update(deltaTime);
    }
}

/**
 * @brief Draw all children
 */
void Node::draw() {
    for (Node node : children) {
        node.draw();
    }
}