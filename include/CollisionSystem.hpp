#pragma once
#include "Player.hpp"
#include <vector>
#include "Rectangle.hpp"

class CollisionSystem {
public:
    void resolvePlayerBoundsCollision(Player& player, const sf::FloatRect& bounds);
    void resolvePlayerRectanglesCollision(Player& player,const std::vector<Rectangle*>& rectangles);
};
