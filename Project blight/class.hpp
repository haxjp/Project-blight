#pragma once
#include "ClientInstance.hpp"
#include "Player.hpp"
#include "GameMode.hpp"

class CLIENT_MODULE {
public:
	MODULEINFO mInfo;
	uintptr_t* baseaddress = nullptr;
	ClientInstance* clientinstance = nullptr;
	uintptr_t* entitylist = nullptr;
	Player* player = nullptr;
	GameMode* gamemode = nullptr;
};