#pragma once
#include"Mob.hpp"
#include "GameMode.hpp"

class Player:public Mob{
public:
	GameMode* getGamemode();
	INT64 SWING();
};