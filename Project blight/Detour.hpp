#pragma once
#include "Hooks.hpp"

void Detour_GetEntityList(uintptr_t*, DWORD*);

uintptr_t Detour_GetPlayer(uintptr_t a1);

uintptr_t Detour_GetKeymap(uintptr_t, int);

uintptr_t Detour_Update(__int64, __int64, __int64);

uintptr_t* Detour_GetServerInformation(uintptr_t*, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, int, int, int, __int64, char, char, __int64, int, __int64, __int64, char, __int64, __int64, __int64, char);
