#include "Player.hpp"

Player::Player(EventBus& bus) : bus(bus) {
	playerShape.setPointCount(3);
	playerShape.setRadius(40.f);
	playerShape.setFillColor(sf::Color::White);
	playerShape.setPosition({ 400.f, 300.f });
	playerShape.setOrigin({ 40.f, 40.f });
	coolDownClock.start();

	float rad = angle.asRadians();
	direction = sf::Vector2(std::sin(rad), -std::cos(rad));
}

void Player::draw(sf::RenderWindow& window) {
	window.draw(playerShape);
}

void Player::updateDirection() {
	float rad = angle.asRadians();
	direction = sf::Vector2(std::sin(rad), -std::cos(rad));
}

void Player::resetCoolDown() {
	coolDownClock.restart();
}

bool Player::canShoot() {
	if (coolDownClock.getElapsedTime().asMilliseconds() >= 100) {
		return true;
	}
	return false;
}

void Player::moveForward(float deltaTime) {
	playerShape.move(direction * speed * deltaTime);
}
void Player::rotateLeft() {
	angle -= sf::degrees(4.f);
	updateDirection();
	playerShape.setRotation(angle);
}
void Player::rotateRight() {
	angle += sf::degrees(4.f);
	updateDirection();
	playerShape.setRotation(angle);
}
sf::Vector2f Player::getDirection() const {
	return direction;
}
sf::FloatRect Player::getBounds() const {
	return playerShape.getGlobalBounds();
}
sf::Vector2f Player::getSize() const {
	sf::FloatRect rect = playerShape.getGlobalBounds();
	return { rect.size.x, rect.size.y };
}
sf::Vector2f Player::getPosition() const {
	return playerShape.getPosition();
}
void Player::setPosition(sf::Vector2f position) {
	playerShape.setPosition(position);
}