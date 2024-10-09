#include "Detour.hpp"
#include "Utils.hpp"

void Detour_getEntityList(uintptr_t* a1, DWORD* a2) {
	auto Tramp = (Utils::Fn<void, uintptr_t*, DWORD*>)Hook_getEntityList.Original;
	cModule.entitylist = a1;
}

uintptr_t Detour_getPlayer(uintptr_t a1) {
	auto Tramp = (Utils::Fn<Player*, uintptr_t>)Hook_getPlayer.Original;
	cModule.player = Tramp(a1);
	if(cModule.player!=nullptr)
	cModule.gamemode = cModule.player->getGamemode();
	return (uintptr_t)cModule.player;
}

uintptr_t Detour_getKeymap(uintptr_t a1, int a2) {
	auto Tramp = (Utils::Fn<uintptr_t, uintptr_t, int>)Hook_getKeymap.Original;
	return Tramp(a1,a2);
}
uintptr_t Detour_Update(__int64 a1, __int64 a2, __int64 a3) {
	auto Tramp = (Utils::Fn<uintptr_t, __int64 , __int64 , __int64>)Hook_Update.Original;
	if (GetAsyncKeyState(VK_HOME) & 1) {
		for(int n = 0;n<2;n++)
		cModule.gamemode->attack(cModule.player);
		cModule.player->SWING();
	}
	return Tramp(a1, a2, a3);
}

uintptr_t* Detour_ConnectionRequest(uintptr_t* a1,__int64 a2,__int64 a3,__int64 a4, __int64 a5,__int64 a6,__int64 a7,__int64 a8,__int64 a9,__int64 a10,__int64 a11,int a12,int a13,int a14,__int64 a15,char a16,char a17,__int64 a18,int a19,__int64 a20, __int64 a21,char a22,__int64 a23,__int64 a24,__int64 a25,char a26) {
	auto Tramp = (Utils::Fn<uintptr_t*, uintptr_t*, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, int, int, int, __int64, char, char, __int64, int, __int64, __int64, char, __int64, __int64, __int64, char>)Hook_ConnectionRequest.Original;
#if _DEBUG
	cout << "Server IP(Port): ";

	if (*(SHORT*)a5 == 0x303A)
		cout << "Local World";
	else if (*((BYTE*)a5 + 7)== NULL)
		cout << *(char**)a5;
	else
		cout << (char*)a5;

	cout << endl << "UserID: " << (char*)a21 << endl;
#endif
	return Tramp(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26);
}

uintptr_t Detour_getCurrentSwingDuration(Player* a1) {
	if (a1 != cModule.player) {
	auto Tramp = (Utils::Fn<uintptr_t,Player*>)Hook_getCurrentSwingDuration.Original;
	return Tramp(a1);
	}
	else
	return 12;
}

