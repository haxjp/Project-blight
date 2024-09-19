#include "Function.hpp"
#include "Hooks.hpp"
#include "Detour.hpp"

int Hook::Create(void* target,void* hooker) {
	this->Target = target;
	this->Detour = hooker;
	
	if (MH_CreateHook(this->Target, this->Detour, &this->Original) != MH_OK)
		this->~Hook();
	return 0;
}
void Hook::Enable() {
	MH_EnableHook(this->Target);
	is_Enable = true;
}
void Hook::Disable() {
	MH_DisableHook(this->Target);
	is_Enable = false;
}
bool Hook::GetCondition() {
	return this->is_Enable;
}
Hook::~Hook() {
	MH_RemoveHook(this->Target);
}

Hook HookGetEntityList;
void SetupHooks() {
	HookGetEntityList.Create(reinterpret_cast<void*>(GetEntityList), reinterpret_cast<void*>(DetourGetEntityList));
}