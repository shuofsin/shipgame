//
// Created by shu on 1/14/26.
//

#include "headers/global.h"
#include "headers/node.h"
#include "headers/collisionshape.h"

/**
 * @brief Default constructor
 */
Node::Node() {
    children = std::list<Node*>();
    parent = NULL;
}

/**
 * @brief Initialize all children
 */
void Node::init() {
    for (Node *node : children) {
        node->init();
    }
}

/**
 * @brief Update all children
 * @param deltaTime The time between the last frame and the one before it, i.e. the time it took to draw the last frame
 */
void Node::update(float deltaTime) {
    for (Node *node: children) {
        node->update(deltaTime);
    }
}

/**
 * @brief Draw all children
 */
void Node::draw() {
    for (Node *node : children) {
        node->draw();
    }
}

/**
 * @return A list of this node's children
 */
std::list<Node*>& Node::getChildren() {
    return children;
}

void Node::addChild(Node *child) {
    children.push_back(child);
    child->setParent(this);
}

void Node::removeChild(Node *child) {
    int size_before = children.size();
    children.remove(child);
    if (size_before == children.size() - 1) child->setParent(NULL);
}

Node *Node::getParent() {
    return parent;
}

void Node::setParent(Node *_parent) {
    parent = _parent;
}