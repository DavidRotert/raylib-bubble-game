#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Entity.hpp"
#include "Game.hpp"

#define PLAYER_CIRCLE_RADIUS 30
#define KEYPRESS_MOVEMENT_SPEED 20

namespace bubblegame {

struct Player: public engine2d::Entity {
    Player(engine2d::Game& game, Vector2);

    void drawEntity() override;

    void moveUp();
    void moveDown();

    private:
        engine2d::Game& game;
};

}

#endif
