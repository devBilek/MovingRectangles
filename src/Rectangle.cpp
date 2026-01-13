#include "Rectangle.hpp"
#include <random>

Rectangle::Rectangle(float height, float width, sf::Color color) {
	rectangle.setSize({width, height});
	rectangle.setFillColor(color);
	size = rectangle.getSize();

	static std::mt19937 gen(std::random_device{}());
	std::uniform_real_distribution<float> distX(1.f, 800.f - size.x);
	std::uniform_real_distribution<float> distY(1.f, 600.f - size.y);

	rectangle.setPosition({ distX(gen), distY(gen) });
	
	clock.start();
	
}

void Rectangle::draw(sf::RenderWindow& window) {
	window.draw(rectangle);
}
void Rectangle::pickNewTarget() {
	static std::mt19937 gen(std::random_device{}());
	std::uniform_real_distribution<float> dist(-200.f, 200.f);

	do {
		sf::Vector2f offset(dist(gen), dist(gen));
		target = rectangle.getPosition() + offset;
	} while (target.x < 0 || target.x + size.x > 800 || target.y < 0 || target.y + size.y > 600);
	

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
sf::FloatRect Rectangle::getBounds() const {
	return rectangle.getGlobalBounds();
}
sf::Vector2f Rectangle::getSize() const {
	return rectangle.getSize();
}
sf::Vector2f Rectangle::getPosition() const {
	return rectangle.getPosition();
}
void Rectangle::setPosition(sf::Vector2f position) {
	rectangle.setPosition(position);
}

