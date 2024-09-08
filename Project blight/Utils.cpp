#include "Utils.hpp"
MODULEINFO mInfo;
uintptr_t* Utils::GetAddressfromSignature(vector<int> signature) {
	GetModuleInformation(GetCurrentProcess(), GetModuleHandle(NULL), &mInfo, sizeof(MODULEINFO));//なんかプロセスの情報もらってくる！！
	uintptr_t end = (mInfo.SizeOfImage);
	bool found = true;
	bool finish_flag = false;
	uintptr_t n = 0;
	uintptr_t m = 1;
	for (;n < end; n++) {
		if (signature.at(0) == *(BYTE*)((uintptr_t)(BaseAddress)+n)) {//まず先頭のsigがあってるか
			for (m = 1; m <= signature.size(); m++) {//２番目以降を確かめる
				if (m == signature.size()) {//最後までいけたら２重ループ抜ける
					finish_flag = true;
					break;
				}
				if (signature.at(m) == -1)//ワイルドカードの時とばす
					continue;
				if (signature.at(m) != *(BYTE*)((uintptr_t)(BaseAddress)+n + m))//２番目以降違うとき
					break;

			}
			if (finish_flag == true) {
				break;
			}
		}
	}

	return (uintptr_t*)((uintptr_t)BaseAddress + n );
}