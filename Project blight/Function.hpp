#include "Utils.hpp"

void SetupFunctions();

extern Utils::Fn<uintptr_t*, uintptr_t*, int*>							GetEntityList;
extern Utils::Fn<Player*, ClientInstance*, uintptr_t*>					GetPlayer;
extern Utils::Fn<char, uintptr_t*, uintptr_t*, uintptr_t, int*>			GetKeymap;
extern Utils::Fn<uintptr_t, __int64, __int64, __int64>					Update;