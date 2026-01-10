#include "Bullet.hpp"

Bullet::Bullet(sf::Vector2f startPosition, sf::Vector2f direction)  : startPosition(startPosition), direction(direction) {
	bullet.setPointCount(10);
	bullet.setRadius(10.f);
	bullet.setOrigin({10.f, 10.f});
	bullet.setFillColor(sf::Color::Magenta);
	bullet.setPosition(startPosition);
}

void Bullet::update(float deltaTime) {
	bullet.move(direction * speed * deltaTime);
}

const sf::CircleShape& Bullet::getShape() const {
	return bullet;
}

bool Bullet::isOutOfBounds() const {
	float x = bullet.getPosition().x;
	float y = bullet.getPosition().y;
	return (x < 0.f || x > 800.f || y < 0.f || y > 600.f);
}