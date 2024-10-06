#include "Function.hpp"
#include "Hooks.hpp"
#include "Detour.hpp"

int Hook::Create(void* target, void* hooker) {
	this->Target = target;
	this->Detour = hooker;
	if (MH_CreateHook(this->Target, this->Detour, &this->Original) != MH_OK)
		this->~Hook();
	MH_EnableHook(this->Target);
	return 0;
}

Hook::~Hook() {
	MH_DisableHook(this->Target);
	MH_RemoveHook(this->Target);
}

Hook Hook_GetEntityList;
Hook Hook_GetPlayer;
Hook Hook_GetKeymap;
Hook Hook_Update;
Hook Hook_GetServerInformation;

void CreateHooks() {
	Hook_GetKeymap.Create(reinterpret_cast<void*>(GetKeymap), reinterpret_cast<void*>(Detour_GetKeymap));
	Hook_GetEntityList.Create(reinterpret_cast<void*>(GetEntityList), reinterpret_cast<void*>(Detour_GetEntityList));
	Hook_GetPlayer.Create(reinterpret_cast<void*>(GetPlayer), reinterpret_cast<void*>(Detour_GetPlayer));
	Hook_Update.Create(reinterpret_cast<void*>(Update), reinterpret_cast<void*>(Detour_Update));
	Hook_GetServerInformation.Create(reinterpret_cast<void*>(GetServerInformation), reinterpret_cast<void*>(Detour_GetServerInformation));
}