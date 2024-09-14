#include "Utils.hpp"

CLIENT_MODULE cModule;

uintptr_t* Utils::GetAddressfromSignature(vector<int> signature) {
	bool found = true;
	bool finish_flag = false;
	uintptr_t n = 0;
	uintptr_t m = 1;
	for (;n < cModule.mInfo.SizeOfImage; n++) {
		if (signature.at(0) == *(BYTE*)((uintptr_t)(cModule.baseaddress)+n)) {//まず先頭のsigがあってるか
			for (m = 1; m <= signature.size(); m++) {//２番目以降を確かめる
				if (m == signature.size()) {//最後までいけたら２重ループ抜ける
					finish_flag = true;
					break;
				}
				if (signature.at(m) == -1)//ワイルドカードの時とばす
					continue;
				if (signature.at(m) != *(BYTE*)((uintptr_t)(cModule.baseaddress)+n + m))//２番目以降違うとき
					break;

			}
			if (finish_flag == true) {
				break;
			}
		}
	}

	return (uintptr_t*)((uintptr_t)cModule.baseaddress + n);
}

uintptr_t* Utils::FindPointer(vector<uintptr_t> pointer) {
	uintptr_t* result = reinterpret_cast<uintptr_t*>(pointer.at(0) + (uintptr_t)cModule.baseaddress);
	for (int n = 1; n < pointer.size(); n++)
		result = reinterpret_cast<uintptr_t*>(*result + pointer.at(n));
	return result;
}