#include "Bubble.hpp"

#include <iostream>
#include <assert.h>

namespace bubblegame {

Bubble::Bubble(engine2d::Game* game, Vector2 pos, int radius): Entity(pos), radius(radius), game(game) {}

#ifndef NDEBUG
Bubble::~Bubble() {
    std::cout << "Deleted bubble " << this << std::endl;
}
#else
Bubble::~Bubble() {}
#endif

void Bubble::drawEntity() {
    DrawCircleLinesV(this->pos, this->radius, WHITE);
}

void Bubble::move() {
    this->pos.x -= 1 * this->speed;
}

}
