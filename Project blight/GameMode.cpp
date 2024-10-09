#include "GameMode.hpp"
#include "Utils.hpp"

void GameMode::attack(Actor* a2) {
	Utils::CallVF<void, Actor*>(this, 14, a2);
}