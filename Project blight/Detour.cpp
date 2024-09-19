#include "Detour.hpp"
#include "Utils.hpp"

uintptr_t* DetourGetEntityList(uintptr_t* a1, int* a2) {
	auto Tramp = (Utils::Fn<uintptr_t*, uintptr_t*, int*>)HookGetEntityList.Original;
	cModule.entitylist = Tramp(a1, a2);
	return cModule.entitylist;
}