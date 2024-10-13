#pragma once
#include"Mob.hpp"
#include "GameMode.hpp"

class Player:public Mob{
public:
	GameMode* getGamemode();
	uintptr_t Swing();
	void setSneaking(bool);
};