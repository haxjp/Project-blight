#include "Utils.hpp"

CLIENT_MODULE cModule;

uintptr_t* Utils::GetAddressfromSignature(vector<int> signature) {
	bool found = true;
	bool finish_flag = false;
	uintptr_t n = 0;
	uintptr_t m = 1;
	for (;n < cModule.mInfo.SizeOfImage; n++) {
		if (signature.at(0) == *(BYTE*)((uintptr_t)(cModule.baseaddress)+n)) {//�܂��擪��sig�������Ă邩
			for (m = 1; m <= signature.size(); m++) {//�Q�Ԗڈȍ~���m���߂�
				if (m == signature.size()) {//�Ō�܂ł�������Q�d���[�v������
					finish_flag = true;
					break;
				}
				if (signature.at(m) == -1)//���C���h�J�[�h�̎��Ƃ΂�
					continue;
				if (signature.at(m) != *(BYTE*)((uintptr_t)(cModule.baseaddress)+n + m))//�Q�Ԗڈȍ~�Ⴄ�Ƃ�
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