#include "Utils.hpp"
MODULEINFO mInfo;
uintptr_t* Utils::GetAddressfromSignature(vector<int> signature) {
	GetModuleInformation(GetCurrentProcess(), GetModuleHandle(NULL), &mInfo, sizeof(MODULEINFO));//�Ȃ񂩃v���Z�X�̏�������Ă���I�I
	uintptr_t end = (mInfo.SizeOfImage);
	bool found = true;
	bool finish_flag = false;
	uintptr_t n = 0;
	uintptr_t m = 1;
	for (;n < end; n++) {
		if (signature.at(0) == *(BYTE*)((uintptr_t)(BaseAddress)+n)) {//�܂��擪��sig�������Ă邩
			for (m = 1; m <= signature.size(); m++) {//�Q�Ԗڈȍ~���m���߂�
				if (m == signature.size()) {//�Ō�܂ł�������Q�d���[�v������
					finish_flag = true;
					break;
				}
				if (signature.at(m) == -1)//���C���h�J�[�h�̎��Ƃ΂�
					continue;
				if (signature.at(m) != *(BYTE*)((uintptr_t)(BaseAddress)+n + m))//�Q�Ԗڈȍ~�Ⴄ�Ƃ�
					break;

			}
			if (finish_flag == true) {
				break;
			}
		}
	}

	return (uintptr_t*)((uintptr_t)BaseAddress + n );
}