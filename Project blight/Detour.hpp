#pragma once
#include "Hooks.hpp"

void Detour_getEntityList(uintptr_t*, DWORD*);

uintptr_t Detour_getPlayer(uintptr_t a1);

uintptr_t Detour_getKeymap(uintptr_t, int);

uintptr_t Detour_Update(__int64, __int64, __int64);

uintptr_t* Detour_ConnectionRequest(uintptr_t*, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, int, int, int, __int64, char, char, __int64, int, __int64, __int64, char, __int64, __int64, __int64, char);

uintptr_t Detour_getCurrentSwingDuration(Player*);