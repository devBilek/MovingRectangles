#include "Game.hpp"
#include "Rectangle.hpp"
#include "RectangleFactory.hpp"
#include "RectangleType.hpp"

Game::Game() 
    : window(sf::RenderWindow(sf::VideoMode({ 800u, 600u }), "CMake SFML Project")),
    r1(std::make_unique<Rectangle>(RectangleFactory::create(RectangleType::Red))),
    r2(std::make_unique<Rectangle>(RectangleFactory::create(RectangleType::Yellow))),
    r3(std::make_unique<Rectangle>(RectangleFactory::create(RectangleType::Green)))
{    
    window.setFramerateLimit(60);      
}

void Game::run() {
    while (window.isOpen())
    {
        float deltaTime = clock.restart().asSeconds();

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        r1->rectangleRandomMove();
        r1->updatePosition(deltaTime);

        r2->rectangleRandomMove();
        r2->updatePosition(deltaTime);

        r3->rectangleRandomMove();
        r3->updatePosition(deltaTime);

        window.clear();
        r1->draw(window);
        r2->draw(window);
        r3->draw(window);
        window.display();
    }
};