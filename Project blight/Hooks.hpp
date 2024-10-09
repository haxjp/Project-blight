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

extern Hook Hook_getEntityList;
extern Hook Hook_getPlayer;
extern Hook Hook_getKeymap;
extern Hook Hook_Update;
extern Hook Hook_ConnectionRequest;
extern Hook Hook_getCurrentSwingDuration;

