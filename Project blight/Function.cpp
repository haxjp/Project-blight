#include "Sigs.hpp"
#include "Class.hpp"
#include "Function.hpp"

Utils::Fn<Player*, ClientInstance*, uintptr_t*>					getPlayer;
Utils::Fn<char, uintptr_t*, uintptr_t*, uintptr_t, int*>		getKeymap;
Utils::Fn<uintptr_t, Player*>									getCurrentSwingDuration;
Utils::Fn<int, uintptr_t*, uintptr_t*, uintptr_t, BYTE>			getItemHanded;
Utils::Fn<uintptr_t, __int64>									Update;
Utils::Fn<uintptr_t*, uintptr_t*, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, int, int, int, __int64, char, char, __int64, int, __int64, __int64, char, __int64, __int64, __int64, char> ConnectionRequest;
Utils::Fn<uintptr_t, GameMode*, uintptr_t*>						G_BaseUseItem;


void SetupFunctions() {
getPlayer		= Utils::CreateFastCall<Player*, ClientInstance*, uintptr_t*>(Utils::GetAddressfromSignature(getplayer));
getKeymap		= Utils::CreateFastCall<char, uintptr_t*, uintptr_t*, uintptr_t, int*>(Utils::GetAddressfromSignature(getkeymap));
getCurrentSwingDuration = Utils::CreateFastCall<uintptr_t, Player*>(Utils::GetAddressfromSignature(getcurrentswingduration));
getItemHanded	= Utils::CreateFastCall<int, uintptr_t*, uintptr_t*, uintptr_t, BYTE>(Utils::GetAddressfromSignature(getitemhanded));
Update			= Utils::CreateFastCall<uintptr_t, __int64>(Utils::GetAddressfromSignature(update));
ConnectionRequest = Utils::CreateFastCall<uintptr_t*, uintptr_t*, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, int, int, int, __int64, char, char, __int64, int, __int64, __int64, char, __int64, __int64, __int64, char>(Utils::GetAddressfromSignature(connectionrequest));
G_BaseUseItem	= Utils::CreateFastCall<uintptr_t, GameMode*, uintptr_t*>(Utils::GetAddressfromSignature(baseuseitem));


//For debug
#if _DEBUG
cout << "SetupFunctions:\n"
<< "getPlayer:		" << getPlayer << endl
<< "getKeymap:		" << getKeymap << endl
<< "getCurrentSwingDuration:" << getCurrentSwingDuration << endl
<< "getItemHanded		" << getItemHanded << endl
<< "Update:			" << Update << endl
<< "ConnectionRequest:	" << ConnectionRequest << endl
<< "BaseUseItem:		" << G_BaseUseItem << endl;
#endif
}
