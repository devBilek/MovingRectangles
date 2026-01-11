#include "PlayerInputSystem.hpp"

void PlayerInputSystem::update(PlayerInput& playerInput) {
	playerInput.moveForward = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
	playerInput.rotateLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left);
	playerInput.rotateRight = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right);
	playerInput.shoot = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space);
}