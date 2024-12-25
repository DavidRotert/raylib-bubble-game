#ifndef BUBBLE_HPP
#define BUBBLE_HPP

#include "raylib.h"

#include "Entity.hpp"
#include "Game.hpp"

namespace bubblegame {

struct Bubble: public engine2d::Entity {
    Bubble(const engine2d::Game* game, Vector2 position, int radius, float speed): Entity(position), radius(radius), speed(speed), game(game) {};
    virtual ~Bubble();

    void drawEntity() override;
    void move();

    int radius;
    float speed;

    private:
        const engine2d::Game* game;
};

}

#endif
