#include "Player.hpp"
#include "Utils.hpp"

GameMode* Player::getGamemode() {
	return *(GameMode**)(this + 0xB18);
}

uintptr_t Player::Swing() {
	return Utils::CallVF<uintptr_t>(this, 113);
}


Level* Player::getLevel() {
	return *(Level**)(this + 0x230);
}