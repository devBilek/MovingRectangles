#include "BulletMenager.hpp"

void BulletMenager::spawnBullet(sf::Vector2f startPosition, sf::Vector2f direction) {
	bullets.push_back(Bullet(startPosition, direction));
}

void BulletMenager::draw(sf::RenderWindow& window) const {
	for (const auto& b : bullets) {
		window.draw(b.getShape());
	}
}

void BulletMenager::update(float deltatime) {
	for (auto& b : bullets) {
		b.update(deltatime);
	}

	bullets.erase(
		std::remove_if(
			bullets.begin(),
			bullets.end(),
			[deltatime](Bullet& b) {
				//b.update(deltatime);
				return b.isOutOfBounds();
			}
		),
		bullets.end()
	);
}
