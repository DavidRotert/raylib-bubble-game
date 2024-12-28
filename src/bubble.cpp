#include "./bubble.hpp"

namespace bubblegame {

entt::entity spawnBubble(entt::registry& registry, int windowHeight, int windowWidth) {
    entt::entity entityId = registry.create();
    registry.emplace<Bubble>(entityId);
    int radius = GetRandomValue(5, 40);
    float y = GetRandomValue(radius, windowHeight - radius);
    Vector2 position = Vector2{(float) windowWidth + radius, y};
    registry.emplace<rayengine_2d::Position>(entityId, position);
    

    return entityId;
}

}
