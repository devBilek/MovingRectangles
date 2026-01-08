#include "Rectangle.hpp"
#include <random>

Rectangle::Rectangle(float height, float width, sf::Color color) {
	rectangle.setSize({width, height});
	rectangle.setFillColor(color);

	static std::mt19937 gen(std::random_device{}());
	std::uniform_real_distribution<float> dist(1.f, 500.f);

	rectangle.setPosition({ dist(gen), dist(gen) });

	clock.start();
	
}

void Rectangle::draw(sf::RenderWindow& window) {
	window.draw(rectangle);
}
void Rectangle::pickNewTarget() {
	static std::mt19937 gen(std::random_device{}());
	std::uniform_real_distribution<float> dist(-200.f, 200.f);

	sf::Vector2f offset(dist(gen), dist(gen));
	target = rectangle.getPosition() + offset;

	isMoving = true;

}
void Rectangle::updatePosition(float deltaTime) {
	if (isMoving == false) return;

	sf::Vector2f position = rectangle.getPosition();
	sf::Vector2f toTarget = target - position;

	
	float distance = std::sqrt(toTarget.x * toTarget.x + toTarget.y * toTarget.y);

	if (distance < 1.f) {
		rectangle.setPosition(target);
		isMoving = false;
		return;
	}

	sf::Vector2f direction = toTarget / distance;

	rectangle.move(direction * speed * deltaTime);
}

void Rectangle::rectangleRandomMove() {
	if (clock.getElapsedTime().asSeconds() > 2.f && isMoving == false) {
		pickNewTarget();
		clock.restart();
	}
}


