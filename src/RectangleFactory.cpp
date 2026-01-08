#include "RectangleFactory.hpp"

Rectangle RectangleFactory::create(RectangleType type) {
	switch (type) {
		case RectangleType::Red:
			return Rectangle( 100.f, 100.f, sf::Color::Red );

		case RectangleType::Yellow:
			return Rectangle( 75.f, 75.f, sf::Color::Yellow );

		case RectangleType::Green:
			return Rectangle( 50.f, 50.f, sf::Color::Green );

		default:
			return Rectangle( 20.f, 20.f, sf::Color::White );
	}
	
}
