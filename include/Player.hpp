#pragma once
#include "SFML/Graphics.hpp"
#include "Bullet.hpp"
#include <vector>
#include <BulletSpawnEvent.hpp>
#include "EventBus.hpp"

class Player {
private:
	sf::CircleShape playerShape;
	void control();
	sf::Angle angle;
	std::vector<Bullet> bullets;
	sf::Clock coolDownClock;
	float speed = 180;
	sf::Vector2f direction;
	void updateDirection();

	EventBus& bus;
public:
	Player(EventBus& bus);
	void update();
	void draw(sf::RenderWindow& window);
	void resetCoolDown();
	bool canShoot();

	sf::Vector2f getDirection() const;
	sf::Vector2f getPosition() const;

	void moveForward(float deltaTime);
	void rotateLeft();
	void rotateRight();

};