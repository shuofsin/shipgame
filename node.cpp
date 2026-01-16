//
// Created by shu on 1/14/26.
//

#include "node.h"

Node::Node() = default;

void Node::init() {
    for (Node node : children) {
        node.init();
    }
}

void Node::update(float deltaTime) {
    for (Node node: children) {
        node.update(deltaTime);
    }
}

void Node::draw() {
    for (Node node : children) {
        node.draw();
    }
}