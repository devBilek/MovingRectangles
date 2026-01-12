#include "CollisionSystem.hpp"
#include "SFML/Graphics.hpp"

void CollisionSystem::resolvePlayerBoundsCollision(Player& player, const sf::FloatRect& bounds) {
    auto position = player.getPosition();
    
    float clampedX = std::clamp(position.x, bounds.position.x, bounds.size.x);
    float clampedY = std::clamp(position.y, bounds.position.y, bounds.size.y);

    player.setPosition({ clampedX, clampedY });
}
