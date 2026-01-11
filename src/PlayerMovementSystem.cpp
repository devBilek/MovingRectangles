#include "PlayerMovementSystem.hpp"
#include "BulletSpawnEvent.hpp"
#include "EventBus.hpp"

PlayerMovementSystem::PlayerMovementSystem(EventBus& eventBus) : eventBus(eventBus) {}

void PlayerMovementSystem::update(Player& player, PlayerInput& playerInput, float deltatime) {
	if (playerInput.moveForward) {
		player.moveForward(deltatime);
	}
	if (playerInput.rotateLeft) {
		player.rotateLeft();
	}
	if (playerInput.rotateRight) {
		player.rotateRight();
	}
	if (playerInput.shoot && player.canShoot()) {
		player.resetCoolDown();
		eventBus.publish(BulletSpawnEvent{ player.getPosition(), player.getDirection()});
		
	}
}