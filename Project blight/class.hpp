#pragma once
#include "ClientInstance.hpp"
#include "GameMode.hpp"
#include "Player.hpp"

class CLIENT_MODULE {
public:
	MODULEINFO mInfo;
	uintptr_t* baseaddress = nullptr;
	ClientInstance* clientinstance = nullptr;
	uintptr_t* entitylist = nullptr;
	Player* player = nullptr;
	GameMode* gamemode = nullptr;
	uintptr_t* item = nullptr;
};