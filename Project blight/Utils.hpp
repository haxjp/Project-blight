#pragma once 
#include "Class.hpp"

class CLIENT_MODULE; // �O���錾
extern CLIENT_MODULE cModule; // extern�錾

namespace Utils {
	uintptr_t* GetAddressfromSignature(string& signature);
	uintptr_t* FindPointer(vector<uintptr_t> pointer);

	template<typename TRet, typename... TArgs>
	using Fn = TRet(__fastcall*)(TArgs...);

	template<typename TRet, typename... TArgs>
	auto CreateFastCall(uintptr_t* Func) {
		using Fn = TRet(__fastcall*)(TArgs...);
		return reinterpret_cast<Fn>(Func);
	}
	template<typename TRet, typename... TArgs>
	TRet CallVF(void* thisptr, size_t index, TArgs... argList) {
		using TFunc = TRet(__fastcall*)(void*, TArgs...);
		TFunc* vtable = *reinterpret_cast<TFunc**>(thisptr);
		return vtable[index](thisptr, argList...);
	}
};