#pragma once
#include <SFML/Graphics.hpp>
#include "Collidable.hpp"

class Rectangle : public Collidable{
private:
	sf::RectangleShape rectangle;
	sf::Vector2f size;
	sf::Clock clock;
	sf::Vector2f target;
	float speed = 100.f;
	bool isMoving = false;
	

public:
	sf::FloatRect getBounds() const override;
	sf::Vector2f getSize() const override;
	sf::Vector2f getPosition() const override;
	void setPosition(sf::Vector2f position) override;

	Rectangle(float height, float width, sf::Color color);
	void draw(sf::RenderWindow& window);
	void updatePosition(float deltaTime);
	void rectangleRandomMove();
	void pickNewTarget();
};