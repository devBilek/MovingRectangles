#include "CollisionSystem.hpp"
#include "SFML/Graphics.hpp"

void CollisionSystem::resolvePlayerBoundsCollision(Player& player, const sf::FloatRect& bounds) {
    auto position = player.getPosition();
    
    float clampedX = std::clamp(position.x, bounds.position.x, bounds.size.x);
    float clampedY = std::clamp(position.y, bounds.position.y, bounds.size.y);
    
    player.setPosition({ clampedX, clampedY });
}

void CollisionSystem::resolvePlayerRectanglesCollision(Player& player,const std::vector<Rectangle*>& rectangles)
{
    for (auto& rectangle : rectangles) {
        sf::FloatRect playerBounds = player.getBounds();
        sf::FloatRect rectangleBounds = rectangle->getBounds();
        
            if (playerBounds.findIntersection(rectangleBounds)) {
                sf::Vector2f playerCenter = playerBounds.getCenter();
                sf::Vector2f rectangleCenter = rectangleBounds.getCenter();

                sf::Vector2f toPlayer = playerCenter - rectangleCenter;

                float overlapX = (playerBounds.size.x / 2.f + rectangleBounds.size.x / 2.f) - std::abs(toPlayer.x);
                float overlapY = (playerBounds.size.y / 2.f + rectangleBounds.size.y / 2.f) - std::abs(toPlayer.y);

                sf::Vector2f mtv;

                if (overlapX > overlapY) {
                    if (toPlayer.y > 0) {
                        mtv.y = overlapY;
                    }
                    else {
                        mtv.y = -overlapY;
                    }
                }
                else {
                    if (toPlayer.x > 0) {
                        mtv.x = overlapX;
                    }
                    else {
                        mtv.x = -overlapX;
                    }
                }
                player.setPosition(player.getPosition() + mtv);
        
            }
    }
    
}

