#include "Player.hpp"
#include "Utils.hpp"

GameMode* Player::getGamemode() {
	return *(GameMode**)(this + 0xB28);
}

uintptr_t Player::Swing() {
	return Utils::CallVF<uintptr_t>(this, 114);
}

void Player::setSneaking(bool a1) {
	Utils::CallVF<uintptr_t,bool>(this, 45,a1);
}

Level* Player::getLevel() {
	return *(Level**)(this + 0x230);
}