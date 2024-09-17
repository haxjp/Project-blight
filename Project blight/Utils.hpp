#pragma once 
#include "Class.hpp"

class CLIENT_MODULE; // �O���錾
extern CLIENT_MODULE cModule; // extern�錾

namespace Utils {
	uintptr_t* GetAddressfromSignature(vector<int> signature);
	uintptr_t* FindPointer(vector<uintptr_t> pointer);

	template<typename TRet, typename... TArgs>
	using Fn = TRet(__fastcall*)(TArgs...);

	template<typename TRet, typename... TArgs>
	auto CreateFastCall(uintptr_t* Func) {
		using Fn = TRet(__fastcall*)(TArgs...);
		return reinterpret_cast<Fn>(Func);
	}
};

class Hook {
public:
	Hook();
	~Hook();
};