#include "Player.hpp"
#include "Function.hpp"

GameMode* Player::getGamemode() {
	return *(GameMode**)(this + 0xB18);
}

INT64 Player::SWING() {
	return Swing(this);
}
