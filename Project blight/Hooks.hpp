#pragma once
#include "Utils.hpp"
class Hook {
private:
	void* Target;
	void* Detour;
	MH_STATUS is_Succeed = MH_ERROR_NOT_CREATED;
	bool is_Enable = false;
public:
	void* Original;

	int Create(void* target, void* Detour);
	void Enable();
	void Disable();
	bool GetCondition();
	~Hook();
};

void CreateHooks();

extern Hook Hook_GetEntityList;
extern Hook Hook_GetPlayer;
extern Hook Hook_GetKeymap;
extern Hook Hook_Update;
extern Hook Hook_GetServerInformation;
