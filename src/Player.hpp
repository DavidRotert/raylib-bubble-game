#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Entity.hpp"
#include "Game.hpp"

#include "raylib.h"

#define PLAYER_CIRCLE_RADIUS 30
#define KEYPRESS_MOVEMENT_SPEED 20

namespace bubblegame {

struct Player: public engine2d::Entity {
    Player(const engine2d::Game* game, Vector2 position): Entity(position), game(game), texture(LoadTexture("resources/submarine.png")) {};
    Player(): Entity({}), game(nullptr), texture({}) {};

    void drawEntity() override;
    void moveUp();
    void moveDown();
    void unloadTexture() { UnloadTexture(this->texture); };

    static const int playerCircleRadius;

    private:
        const engine2d::Game* game;
        Texture2D texture;
};

}

#endif
