#include "Player.hpp"
#include "Function.hpp"

GameMode* Player::getGamemode() {
	return *(GameMode**)(this + 0xB18);
}

uintptr_t Player::Swing() {
	return Utils::CallVF<uintptr_t>(this, 115);
}

void Player::setSneaking(bool a1) {
	Utils::CallVF<uintptr_t,bool>(this, 45,a1);
}