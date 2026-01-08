#include "Player.hpp"

Player::Player() : deltaTime(1) {
	playerShape.setPointCount(3);
	playerShape.setRadius(40.f);
	playerShape.setFillColor(sf::Color::White);
	playerShape.setPosition({ 400.f, 300.f });
	playerShape.setOrigin({ 40.f, 40.f });
}

void Player::update(float deltaTime) {
	this->deltaTime = deltaTime;
	control();
}

void Player::draw(sf::RenderWindow& window) {
	window.draw(playerShape);
}

void Player::control() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
		float rad = angle.asRadians();
		sf::Vector2f dir( std::sin(rad), -std::cos(rad));
		playerShape.move(dir * 70.f * deltaTime);
		
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
		angle -= sf::degrees(2.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
		angle += sf::degrees(2.f);
	}
	playerShape.setRotation(angle);
}