#include "Utils.hpp"
#include "Sigs.hpp"
void init(HINSTANCE HI);

BOOL APIENTRY DllMain(
    HINSTANCE hInstance,
    DWORD dReason,
    LPVOID lpvReserved) {

    if (dReason == DLL_PROCESS_ATTACH) {
        CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)init, hInstance, 0, nullptr);
    }
    return TRUE;
}

uintptr_t* BaseAddress = (uintptr_t*)GetModuleHandle("minecraft.windows.exe");
void init(HINSTANCE HI) {
    //initialize and something...
    HWND Handle = GetConsoleWindow(); // create console for debug
    {
        if (Handle == NULL) {//null�i���܂łɃR���\�[�����Ȃ��Ƃ��B�j
            AllocConsole();
            Handle = GetConsoleWindow();

            FILE* stdinNew = nullptr;
            freopen_s(&stdinNew, "CONIN$", "r+", stdin);
            FILE* stdoutNew = nullptr;
            freopen_s(&stdoutNew, "CONOUT$", "w+", stdout);
            FILE* stderrNew = nullptr;
            freopen_s(&stderrNew, "CONOUT$", "w+", stderr);
        }
        else {//�i���܂łɃR���\�[��������A�\������B�j
            ShowWindow(Handle, SW_NORMAL);
        }
    }
    MH_Initialize();
    
    cout << Utils::GetAddressfromSignature(gametick) << endl;
    cout << Utils::GetAddressfromSignature(entitylist) << endl;

    for (;;) {
        if (GetAsyncKeyState(VK_END) & 1)
            break;
    }
    ShowWindow(Handle, SW_HIDE);
    FreeLibraryAndExitThread(HI, 0);
    return;
}