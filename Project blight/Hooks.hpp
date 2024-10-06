#pragma once
#include "Utils.hpp"
class Hook {
private:
	void* Target;
	void* Detour;
public:
	void* Original;

	int Create(void* target, void* Detour);
	~Hook();
};

void CreateHooks();

extern Hook Hook_GetEntityList;
extern Hook Hook_GetPlayer;
extern Hook Hook_GetKeymap;
extern Hook Hook_Update;
extern Hook Hook_GetServerInformation;