#pragma once
#include "SFML/Graphics.hpp"
#include "Bullet.hpp"
#include <vector>

class Player {
private:
	sf::CircleShape playerShape;
	void control();
	sf::Angle angle;
	float deltaTime;
	std::vector<Bullet> bullets;
	sf::Clock coolDownClock;
	float speed = 180;
public:
	Player();
	void update(float deltaTime);
	void draw(sf::RenderWindow& window);
	void shot();
	const std::vector<Bullet>& getBullets() const;
};