#pragma once
#include "Hooks.hpp"

uintptr_t Detour_getPlayer(uintptr_t a1);

uintptr_t Detour_getKeymap(uintptr_t, int);

uintptr_t Detour_getCurrentSwingDuration(Player*);

int Detour_getItemHanded(uintptr_t*, uintptr_t*, uintptr_t, BYTE);

uintptr_t Detour_Update(uintptr_t, uintptr_t, uintptr_t);

uintptr_t* Detour_ConnectionRequest(uintptr_t*, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, int, int, int, __int64, char, char, __int64, int, __int64, __int64, char, __int64, __int64, __int64, char);



