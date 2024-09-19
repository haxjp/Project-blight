#pragma once
class Hook {
private:
	void* Target;
	void* Detour;
	MH_STATUS is_Succeed = MH_ERROR_NOT_CREATED;
	bool is_Enable = false;
public:
	void* Original;

	int Create(void* target, void* Detour);
	void Enable();
	void Disable();
	bool GetCondition();
	~Hook();
};

void SetupHooks();

extern Hook HookGetEntityList;
extern Hook HookGetPlayer;
extern Hook HookGetKeymap;
extern Hook HookUpdate;