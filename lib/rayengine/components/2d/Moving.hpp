#ifndef RAYENGINE_COMPONENTS_2D_MOVING
#define RAYENGINE_COMPONENTS_2D_MOVING

#include "raylib.h"
#include "./Movable.hpp"

namespace rayengine_2d {

template<typename... T> class Moving {
    public:
        Moving(T... args, Vector2 direction): objects(args...), direction(direction) {};

        void move(float deltaTime) {
            for (auto obj: this->objects) {
                obj.move(Vector2Multiply(this->direction, Vector2{deltaTime, deltaTime}));
            }

            //this->moveHelper(deltaTime);
        }
    private:
        std::tuple<T...> objects;
        Vector2 direction;

        template<std::size_t... Is> void moveHelper(float deltaTime) {
            (std::get<Is>(this->objects).move(Vector2Multiply(this->direction, Vector2{deltaTime, deltaTime})), ...);
        }
};

}

#endif
