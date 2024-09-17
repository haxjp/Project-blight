#include "Sigs.hpp"
#include "Class.hpp"
#include "Function.hpp"

Utils::Fn<uintptr_t, __int64, __int64, __int64**, int, char>	GameTick;
Utils::Fn<uintptr_t*, uintptr_t*, int*>							GetEntityList;
Utils::Fn<Player*, ClientInstance*, uintptr_t*>					GetPlayer;
Utils::Fn<char, uintptr_t*, uintptr_t*, uintptr_t, int*>		GetKeymap;
Utils::Fn<uintptr_t, __int64, __int64, __int64>					Update;

void SetupFunctions() {
GameTick		= Utils::CreateFastCall<uintptr_t, __int64, __int64, __int64**, int, char>(Utils::GetAddressfromSignature(gametick));
GetEntityList	= Utils::CreateFastCall<uintptr_t*, uintptr_t*, int*>(Utils::GetAddressfromSignature(getentitylist));
GetPlayer		= Utils::CreateFastCall<Player*, ClientInstance*, uintptr_t*>(Utils::GetAddressfromSignature(getplayer));
GetKeymap		= Utils::CreateFastCall<char, uintptr_t*, uintptr_t*, uintptr_t, int*>(Utils::GetAddressfromSignature(getkeymap));
Update			= Utils::CreateFastCall<uintptr_t, __int64, __int64, __int64>(Utils::GetAddressfromSignature(update));
}
