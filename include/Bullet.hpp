#pragma once

#include "SFML/Graphics.hpp"

class Bullet {
private:
	sf::CircleShape bullet;
	sf::Vector2f startPosition;
	sf::Angle angle;
	sf::Vector2f direction;
	float speed = 400.f;
public:
	Bullet(sf::Vector2f startPosition, sf::Vector2f direction);
	void update(float deltaTime);
	const sf::CircleShape& getShape() const;
	bool isOutOfBounds() const;
};