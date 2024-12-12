#ifndef BUBBLE_HPP
#define BUBBLE_HPP

#include "raylib.h"

#include "Entity.hpp"
#include "Game.hpp"

namespace bubblegame {

struct Bubble: public engine2d::Entity {
    int radius;
    float speed;

    Bubble(engine2d::Game* game, Vector2 position, int radius, float speed);
    virtual ~Bubble();

    void drawEntity() override;
    void move();

    private:
        engine2d::Game* game;
};

}

#endif
