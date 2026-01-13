#pragma once
#include "SFML/Graphics.hpp"

class Collidable {
public:
	virtual sf::FloatRect getBounds() const = 0;
	virtual sf::Vector2f getSize() const = 0;
	virtual sf::Vector2f getPosition() const = 0;
	virtual void setPosition(sf::Vector2f position) = 0;
	virtual ~Collidable() = default;
};
