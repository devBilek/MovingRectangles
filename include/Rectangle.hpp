#pragma once
#include <SFML/Graphics.hpp>

class Rectangle {
private:
	sf::RectangleShape rectangle;
	sf::Clock clock;
	sf::Vector2f target;
	float speed = 100.f;
	bool isMoving = false;

public:
	Rectangle(float height, float width, sf::Color color);
	void draw(sf::RenderWindow& window);
	void updatePosition(float deltaTime);
	void rectangleRandomMove();
	void pickNewTarget();
};