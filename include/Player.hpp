#pragma once
#include "SFML/Graphics.hpp"
#include "Bullet.hpp"
#include <vector>
#include <BulletSpawnEvent.hpp>

class Player {
private:
	sf::CircleShape playerShape;
	void control();
	sf::Angle angle;
	float deltaTime;
	std::vector<Bullet> bullets;
	sf::Clock coolDownClock;
	float speed = 180;
	sf::Vector2f direction;
	void computeDirection();
public:
	Player();
	void update(float deltaTime);
	void draw(sf::RenderWindow& window);
	std::optional<BulletSpawnEvent> pollShotEvent();
};