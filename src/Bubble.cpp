#include "Bubble.hpp"

#include <iostream>
#include <assert.h>

namespace bubblegame {

#ifndef NDEBUG
Bubble::~Bubble() {
    std::cout << "Deleted bubble " << this << std::endl;
}
#else
Bubble::~Bubble() {}
#endif

void Bubble::drawEntity() {
    DrawCircleLinesV(this->position, this->radius, WHITE);
}

void Bubble::move() {
    this->position.x -= this->game->calcMovementSpeed(this->speed);
}

}
