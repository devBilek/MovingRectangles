#pragma once
#include "SFML/Graphics.hpp"
#include "Rectangle.hpp"
#include <memory>
#include "Player.hpp"
#include "BulletManager.hpp"
#include "EventBus.hpp"
#include "PlayerInput.hpp"
#include "PlayerInputSystem.hpp"
#include "PlayerMovementSystem.hpp"
#include "CollisionSystem.hpp"

class Game {
public:
	Game();
	~Game() = default;

	void run();

private:
	sf::RenderWindow window;
	sf::Clock clock;

	CollisionSystem collisionSystem;

	PlayerInput playerInput;
	PlayerInputSystem playerInputSystem;
	PlayerMovementSystem playerMovementSystem;

	EventBus eventBus;
	BulletMenager bulletMenager;
	Player player;
	std::unique_ptr<Rectangle> r1;
	std::unique_ptr<Rectangle> r2;
	std::unique_ptr<Rectangle> r3;
};