#pragma once
#include <vector>
#include "Bullet.hpp"

class BulletMenager {
private:
	std::vector<Bullet> bullets;
public:
	void draw(sf::RenderWindow& window) const;
	void update(float deltaTime);
	void spawnBullet(sf::Vector2f startPosition, sf::Vector2f direction);
};