#pragma once
#include <vector>
#include "Bullet.hpp"
#include "EventBus.hpp"
#include "BulletSpawnEvent.hpp"

class BulletMenager {
private:
	std::vector<Bullet> bullets;

	EventBus& bus;
public:
	BulletMenager(EventBus& bus);
	void draw(sf::RenderWindow& window) const;
	void update(float deltaTime);
};