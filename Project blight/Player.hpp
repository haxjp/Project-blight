#pragma once
#include "Class.hpp"

class Player{
public:
	GameMode* GetGameMode() {
		return *(GameMode**)(this + 0xB00);
	}
};