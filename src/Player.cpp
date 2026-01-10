#include "Player.hpp"

Player::Player(EventBus& bus) : bus(bus), deltaTime(1) {
	playerShape.setPointCount(3);
	playerShape.setRadius(40.f);
	playerShape.setFillColor(sf::Color::White);
	playerShape.setPosition({ 400.f, 300.f });
	playerShape.setOrigin({ 40.f, 40.f });
	coolDownClock.start();

	float rad = angle.asRadians();
	direction = sf::Vector2(std::sin(rad), -std::cos(rad));
}

void Player::update(float deltaTime) {
	this->deltaTime = deltaTime;
	control();
}

void Player::draw(sf::RenderWindow& window) {
	window.draw(playerShape);
}

void Player::control() {
	computeDirection();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
		playerShape.move(direction * speed * deltaTime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
		angle -= sf::degrees(4.f);
		playerShape.setRotation(angle);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
		angle += sf::degrees(4.f);
		playerShape.setRotation(angle);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && coolDownClock.getElapsedTime().asMilliseconds() >= 100) {
		coolDownClock.restart();
		bus.publish(BulletSpawnEvent{ playerShape.getPosition(), direction });
	}
}

void Player::computeDirection() {
	float rad = angle.asRadians();
	direction = sf::Vector2(std::sin(rad), -std::cos(rad));
}