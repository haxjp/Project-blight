#pragma once
#include "class.hpp"

class Player{
public:
	GameMode* GetGameMode() {
		return *(GameMode**)(this + 0xB00);
	}
};