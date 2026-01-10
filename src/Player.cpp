#include "Player.hpp"

Player::Player() : deltaTime(1) {
	playerShape.setPointCount(3);
	playerShape.setRadius(40.f);
	playerShape.setFillColor(sf::Color::White);
	playerShape.setPosition({ 400.f, 300.f });
	playerShape.setOrigin({ 40.f, 40.f });
	coolDownClock.start();
}

void Player::update(float deltaTime) {
	this->deltaTime = deltaTime;
	control();

	for (auto& b : bullets) {
		b.update(deltaTime);
	}

	bullets.erase(
		std::remove_if(
			bullets.begin(),
			bullets.end(),
			[deltaTime](Bullet& b) {
				b.update(deltaTime);
				return b.isOutOfBounds();
			}
		),
		bullets.end()
	);
}

void Player::draw(sf::RenderWindow& window) {
	window.draw(playerShape);
}

void Player::control() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
		float rad = angle.asRadians();
		sf::Vector2f dir( std::sin(rad), -std::cos(rad));
		playerShape.move(dir * speed * deltaTime);
		
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
		shot();
	}
}

void Player::shot() {
	bullets.push_back(Bullet(playerShape.getPosition(), angle));
	coolDownClock.restart();
}

const std::vector<Bullet>& Player::getBullets() const {
	return bullets;
}