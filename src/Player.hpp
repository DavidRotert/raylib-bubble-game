#ifndef BUBBLEGAME_PLAYER_HPP
#define BUBBLEGAME_PLAYER_HPP

#include "rayengine/components/2d/Position.hpp"
#include "rayengine/components/2d/CollisionCircle.hpp"
#include "rayengine/TextureManager.hpp"

#define PLAYER_COLLISION_RADIUS 30
#define PLAYER_MAX_POSITION_UPPER_MARGIN 0
#define PLAYER_MAX_POSITION_LOWER_MARGIN 0
#define PLAYER_POSITION_LEFT_MARGIN 30
#define PLAYER_KEYPRESS_MOVEMENT_SPEED 250

namespace bubblegame {

struct Player {
    static Player create(int windowHeight);

    Player(Vector2 position):
        positionComponent(rayengine_2d::Position(position)),
        collisionComponent(rayengine_2d::CollisionCircle(position, PLAYER_COLLISION_RADIUS)) {};
    Player(): Player(Vector2{0, 0}) {};

    void setPosition(Vector2 position) {
        this->positionComponent.position = position;
        this->collisionComponent.center = position;
    };
    void moveUp(float deltaTime);
    void moveDown(int windowHeight, float deltaTime);
    bool checkCollision(rayengine_2d::Collision& other) { return this->collisionComponent.checkCollision(other); };
    void render(rayengine::TextureManager& textureManager);

    private:
        rayengine_2d::Position positionComponent;
        rayengine_2d::CollisionCircle collisionComponent;
};

}

#endif
