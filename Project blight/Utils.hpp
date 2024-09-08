#pragma once 
#include <Windows.h>
#include <TlHelp32.h>
#include <Psapi.h>
#include <iostream>
#include <vector>
#include "minhook.h"

using namespace std;

extern MODULEINFO mInfo;
extern uintptr_t* BaseAddress;

namespace Utils {
	uintptr_t* GetAddressfromSignature(vector<int> signature);

};