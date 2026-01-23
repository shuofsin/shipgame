//
// Created by shu on 1/22/26.
//

#ifndef SHIPGAME_GLOBAL_H
#define SHIPGAME_GLOBAL_H

#include <complex>
#include <raylib.h>
#include <raymath.h>
#include <cstdio>
#include <list>

typedef struct Circle {
    int x;
    int y;
    float radius;
} Circle;

typedef union Shape {
    Circle c;
    Rectangle r;
} Shape;

#endif //SHIPGAME_GLOBAL_H