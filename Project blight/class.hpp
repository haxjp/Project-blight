#pragma once

//class declaration
class ClientInstance;
class Player;
class GameMode;


class CLIENT_MODULE {
public:
	MODULEINFO mInfo;
	uintptr_t* baseaddress;
	ClientInstance* clientinstance;
	uintptr_t* entitylist;
	Player* player;
	GameMode* gamemode;
};
