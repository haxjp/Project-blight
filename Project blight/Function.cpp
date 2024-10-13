#include "Sigs.hpp"
#include "Class.hpp"
#include "Function.hpp"

Utils::Fn<uintptr_t*, uintptr_t*, DWORD*>						getEntityList;
Utils::Fn<Player*, ClientInstance*, uintptr_t*>					getPlayer;
Utils::Fn<char, uintptr_t*, uintptr_t*, uintptr_t, int*>		getKeymap;
Utils::Fn<uintptr_t, __int64, __int64, __int64>					Update;
Utils::Fn<uintptr_t*, uintptr_t*, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, int, int, int, __int64, char, char, __int64, int, __int64, __int64, char, __int64, __int64, __int64, char> ConnectionRequest;
Utils::Fn<uintptr_t, Player*>										getCurrentSwingDuration;
Utils::Fn<uintptr_t, GameMode*, uintptr_t*>								G_BaseUseItem;

void SetupFunctions() {
getEntityList	= Utils::CreateFastCall<uintptr_t*, uintptr_t*, DWORD*>(Utils::GetAddressfromSignature(getentitylist));
getPlayer		= Utils::CreateFastCall<Player*, ClientInstance*, uintptr_t*>(Utils::GetAddressfromSignature(getplayer));
getKeymap		= Utils::CreateFastCall<char, uintptr_t*, uintptr_t*, uintptr_t, int*>(Utils::GetAddressfromSignature(getkeymap));
Update			= Utils::CreateFastCall<uintptr_t, __int64, __int64, __int64>(Utils::GetAddressfromSignature(update));
ConnectionRequest = Utils::CreateFastCall<uintptr_t*, uintptr_t*, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, int, int, int, __int64, char, char, __int64, int, __int64, __int64, char, __int64, __int64, __int64, char>(Utils::GetAddressfromSignature(connectionrequest));
getCurrentSwingDuration = Utils::CreateFastCall<uintptr_t, Player*>(Utils::GetAddressfromSignature(getcurrentswingduration));
G_BaseUseItem		= Utils::CreateFastCall<uintptr_t, GameMode*, uintptr_t*>(Utils::GetAddressfromSignature(baseuseitem));
//For debug
#if _DEBUG
cout << "SetupFunctions:\n"
<< "getEntityList:		" << getEntityList << endl
<< "getPlayer:		" << getPlayer << endl
<< "getKeymap:		" << getKeymap << endl
<< "Update:			" << Update << endl
<< "ConnectionRequest:		" << ConnectionRequest << endl
<< "getCurrentSwingDuration:		" << getCurrentSwingDuration << endl
<< "BaseUseItem:		"<< G_BaseUseItem << endl;
#endif
}
