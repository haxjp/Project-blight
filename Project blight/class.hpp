#pragma once
#include "Utils.hpp"

class CLIENT_MODULE {
public:
	MODULEINFO mInfo;
	uintptr_t* BaseAddress;
	uintptr_t* ClientInstance;
	uintptr_t* Player;
};
