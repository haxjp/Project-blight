#include "Utils.hpp"

CLIENT_MODULE cModule;

uintptr_t* Utils::GetAddressfromSignature(string& signature) {
	//string to vector
	vector<int> v;
	for (int n = 0; n < signature.size(); n++) {
		if (signature.at(n) == ' ')
			for (int m = 1; m <= 3; m++) {
				if (n + m >= signature.size()) {
					n = signature.size();
					break;
				}
				else if (signature.at(n + m) == ' ') {
					if (signature.substr(n + 1, m) == "? ") {
						v.push_back(-1);
						break;
					}
					else
						v.push_back(stoi(signature.substr(n + 1, m - 1), 0, 16));
				}
			}
	}

	bool found = false;
	bool finish_flag = false;
	uintptr_t n = 0;
	uintptr_t m = 1;
	for (;n < cModule.mInfo.SizeOfImage; n++) {
		if (v.at(0) == *(BYTE*)((uintptr_t)(cModule.baseaddress)+n)) {//�܂��擪��sig�������Ă邩
			found = true;;
			for (m = 1; m <= v.size(); m++) {//�Q�Ԗڈȍ~���m���߂�
				if (m == v.size()) {//�Ō�܂ł�������Q�d���[�v������
					found = true;
					finish_flag = true;
					break;
				}
				if (v.at(m) == -1)//���C���h�J�[�h�̎��Ƃ΂�
					continue;
				if (v.at(m) != *(BYTE*)((uintptr_t)(cModule.baseaddress) + n + m)) {//�Q�Ԗڈȍ~�Ⴄ�Ƃ�
					found = false;
					break;
				}

			}
			if (finish_flag == true) {
				break;
			}
		}
	}
#if _DEBUG
	if (found == false)
		cout << "sig not found" << endl;
#endif
	return (uintptr_t*)((uintptr_t)cModule.baseaddress + n);
}

uintptr_t* Utils::FindPointer(vector<uintptr_t> pointer) {
	uintptr_t* result = reinterpret_cast<uintptr_t*>(pointer.at(0) + (uintptr_t)cModule.baseaddress);
	for (int n = 1; n < pointer.size(); n++)
		result = reinterpret_cast<uintptr_t*>(*result + pointer.at(n));
	return result;
}