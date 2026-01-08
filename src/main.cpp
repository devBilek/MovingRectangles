#include <SFML/Graphics.hpp>
#include "Rectangle.hpp"
#include "RectangleFactory.hpp"

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({800u, 600u}), "CMake SFML Project");
    window.setFramerateLimit(144);

    sf::Clock clock;
    Rectangle r1 = RectangleFactory::create(RectangleType::Red);
    Rectangle r2 = RectangleFactory::create(RectangleType::Green);
    Rectangle r3 = RectangleFactory::create(RectangleType::Yellow);

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

        r1.rectangleRandomMove();
        r1.updatePosition(deltaTime);

        r2.rectangleRandomMove();
        r2.updatePosition(deltaTime);

        r3.rectangleRandomMove();
        r3.updatePosition(deltaTime);

        window.clear();
        r1.draw(window);
        r2.draw(window);
        r3.draw(window);
        window.display();
    }
}
