#include "Game.hpp"
#include "Rectangle.hpp"
#include "RectangleFactory.hpp"
#include "RectangleType.hpp"

Game::Game() 
    : window(sf::RenderWindow(sf::VideoMode({ 800u, 600u }), "CMake SFML Project")),
    playerMovementSystem(eventBus),
    bulletMenager(BulletMenager(eventBus)),
    player(Player(eventBus)),
    r1(std::make_unique<Rectangle>(RectangleFactory::create(RectangleType::Red))),
    r2(std::make_unique<Rectangle>(RectangleFactory::create(RectangleType::Yellow))),
    r3(std::make_unique<Rectangle>(RectangleFactory::create(RectangleType::Green)))
{    
    window.setFramerateLimit(60);      
}

void Game::run() {
    while (window.isOpen()) {
        float deltaTime = clock.restart().asSeconds();

        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }

        }

        playerInputSystem.update(playerInput);
        playerMovementSystem.update(player, playerInput, deltaTime);

        bulletMenager.update(deltaTime);
        
        collisionSystem.resolvePlayerBoundsCollision(player, { {0, 0}, {800, 600} });
        collisionSystem.resolvePlayerRectanglesCollision(player, {r1.get(), r2.get(), r3.get()});

        r1->rectangleRandomMove();
        r1->updatePosition(deltaTime);

        r2->rectangleRandomMove();
        r2->updatePosition(deltaTime);

        r3->rectangleRandomMove();
        r3->updatePosition(deltaTime);

        window.clear();
        bulletMenager.draw(window);
        player.draw(window);
        r1->draw(window);
        r2->draw(window);
        r3->draw(window);
        

        window.display();
    }
};