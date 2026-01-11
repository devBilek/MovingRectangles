#pragma once
#include "Player.hpp"
#include "PlayerInput.hpp"
#include "EventBus.hpp"

class PlayerMovementSystem {
private:
	EventBus& eventBus;
public:
	PlayerMovementSystem(EventBus& eventBus);
	void update(Player& player, PlayerInput& playerInput, float deltatime);
};