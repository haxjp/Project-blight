#pragma once 
#include <Windows.h>
#include <TlHelp32.h>
#include <Psapi.h>
#include <iostream>
#include <vector>
#include <initializer_list>
#include "minhook.h"
#include "class.hpp"
#include "Hooks.hpp"

#include "ClientInstance.hpp"
#include "GameMode.hpp"
#include "Player.hpp"

using namespace std;

class CLIENT_MODULE; // ‘O•ûéŒ¾
extern CLIENT_MODULE cModule; // externéŒ¾

namespace Utils {
	uintptr_t* GetAddressfromSignature(vector<int> signature);
	uintptr_t* FindPointer(vector<uintptr_t> pointer);


	template<typename TRet, typename... TArgs>
	auto CreateFastCall(uintptr_t* Func) {
		using Fn = TRet(__fastcall*)(TArgs...);
		return reinterpret_cast<Fn>(Func);
	}
};