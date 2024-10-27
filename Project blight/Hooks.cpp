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

Hook Hook_getPlayer;
Hook Hook_getKeymap;
Hook Hook_getCurrentSwingDuration;
Hook Hook_getItemHanded;
Hook Hook_Update;
Hook Hook_ConnectionRequest;

void CreateHooks() {
	Hook_getKeymap.Create(reinterpret_cast<void*>(getKeymap), reinterpret_cast<void*>(Detour_getKeymap));
	Hook_getPlayer.Create(reinterpret_cast<void*>(getPlayer), reinterpret_cast<void*>(Detour_getPlayer));
	Hook_Update.Create(reinterpret_cast<void*>(Update), reinterpret_cast<void*>(Detour_Update));
	Hook_ConnectionRequest.Create(reinterpret_cast<void*>(ConnectionRequest), reinterpret_cast<void*>(Detour_ConnectionRequest));
	Hook_getCurrentSwingDuration.Create(reinterpret_cast<void*>(getCurrentSwingDuration), reinterpret_cast<void*>(Detour_getCurrentSwingDuration));
	Hook_getItemHanded.Create(reinterpret_cast<void*>(getItemHanded), reinterpret_cast<void*>(Detour_getItemHanded));


}