#pragma once
#include "SFML/Graphics.hpp"
#include "Bullet.hpp"
#include <vector>
#include <BulletSpawnEvent.hpp>
#include "EventBus.hpp"
#include "Collidable.hpp"

class Player : public Collidable {
private:
	sf::CircleShape playerShape;
	sf::Angle angle;
	std::vector<Bullet> bullets;
	sf::Clock coolDownClock;
	float speed = 180;
	sf::Vector2f direction;
	void updateDirection();

	EventBus& bus;
public:
	sf::FloatRect getBounds() const override;
	sf::Vector2f getSize() const override;
	sf::Vector2f getPosition() const override;
	void setPosition(sf::Vector2f position) override;

	Player(EventBus& bus);
	void draw(sf::RenderWindow& window);
	void resetCoolDown();
	bool canShoot();

	sf::Vector2f getDirection() const;

	void moveForward(float deltaTime);
	void rotateLeft();
	void rotateRight();

};