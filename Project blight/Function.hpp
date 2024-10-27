#include "Utils.hpp"

void SetupFunctions();

extern Utils::Fn<Player*, ClientInstance*, uintptr_t*>					getPlayer;
extern Utils::Fn<char, uintptr_t*, uintptr_t*, uintptr_t, int*>			getKeymap;
extern Utils::Fn<uintptr_t, Player*>									getCurrentSwingDuration;
extern Utils::Fn<int, uintptr_t*, uintptr_t*, uintptr_t, BYTE>			getItemHanded;
extern Utils::Fn<uintptr_t, __int64>									Update;
extern Utils::Fn<uintptr_t*, uintptr_t*, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, int, int, int, __int64, char, char, __int64, int, __int64, __int64, char, __int64, __int64, __int64, char> ConnectionRequest;
extern Utils::Fn<uintptr_t, GameMode*, uintptr_t*>								G_BaseUseItem;
