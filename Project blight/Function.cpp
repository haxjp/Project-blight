#include "Sigs.hpp"
#include "Class.hpp"
#include "Function.hpp"

Utils::Fn<uintptr_t*, uintptr_t*, DWORD*>							GetEntityList;
Utils::Fn<Player*, ClientInstance*, uintptr_t*>					GetPlayer;
Utils::Fn<char, uintptr_t*, uintptr_t*, uintptr_t, int*>		GetKeymap;
Utils::Fn<uintptr_t, __int64, __int64, __int64>					Update;
Utils::Fn<uintptr_t*, uintptr_t*, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, int, int, int, __int64, char, char, __int64, int, __int64, __int64, char, __int64, __int64, __int64, char> GetServerInformation;

void SetupFunctions() {
GetEntityList	= Utils::CreateFastCall<uintptr_t*, uintptr_t*, DWORD*>(Utils::GetAddressfromSignature(getentitylist));
GetPlayer		= Utils::CreateFastCall<Player*, ClientInstance*, uintptr_t*>(Utils::GetAddressfromSignature(getplayer));
GetKeymap		= Utils::CreateFastCall<char, uintptr_t*, uintptr_t*, uintptr_t, int*>(Utils::GetAddressfromSignature(getkeymap));
Update			= Utils::CreateFastCall<uintptr_t, __int64, __int64, __int64>(Utils::GetAddressfromSignature(update));
GetServerInformation = Utils::CreateFastCall<uintptr_t*, uintptr_t*, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, int, int, int, __int64, char, char, __int64, int, __int64, __int64, char, __int64, __int64, __int64, char>(Utils::GetAddressfromSignature(getserverinformation));
//For debug
#if _DEBUG
cout << "SetupFunctions:\n" 
<<"GetEntityList:	"<< GetEntityList << endl
<<"GetPlayer:	" << GetPlayer << endl
<<"GetKeymap:	" << GetKeymap << endl
<<"Update:		"<<  Update << endl
<< "GetServerInformation:		" << GetServerInformation << endl;
#endif
}
