#pragma once
#include "SFML/Graphics.hpp"
#include "Rectangle.hpp"

class Game {
public:
	Game();
	~Game() = default;
	
	void run();

private:
	sf::RenderWindow window;
	sf::Clock clock;

	Rectangle r1;
	Rectangle r2;
	Rectangle r3;
};