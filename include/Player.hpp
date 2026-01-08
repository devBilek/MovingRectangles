#pragma once
#include "SFML/Graphics.hpp"

class Player {
private:
	sf::CircleShape playerShape;
	void control();
	sf::Angle angle;
	float deltaTime;
public:
	Player();
	void update(float deltaTime);
	void draw(sf::RenderWindow& window);
};