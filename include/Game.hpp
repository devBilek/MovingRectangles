#pragma once
#include "SFML/Graphics.hpp"
#include "Rectangle.hpp"
#include <memory>
#include "Player.hpp"
#include "BulletManager.hpp"
#include "EventBus.hpp"

class Game {
public:
	Game();
	~Game() = default;

	void run();

private:
	sf::RenderWindow window;
	sf::Clock clock;

	std::unique_ptr<EventBus> eventBus;
	std::unique_ptr<BulletMenager> bulletMenager;
	std::unique_ptr<Player> player;
	std::unique_ptr<Rectangle> r1;
	std::unique_ptr<Rectangle> r2;
	std::unique_ptr<Rectangle> r3;
};