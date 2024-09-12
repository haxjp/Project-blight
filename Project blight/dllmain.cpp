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
        if (Handle == NULL) {//null（今までにコンソールがないとき。）
            AllocConsole();
            Handle = GetConsoleWindow();

            FILE* stdinNew = nullptr;
            freopen_s(&stdinNew, "CONIN$", "r+", stdin);
            FILE* stdoutNew = nullptr;
            freopen_s(&stdoutNew, "CONOUT$", "w+", stdout);
            FILE* stderrNew = nullptr;
            freopen_s(&stderrNew, "CONOUT$", "w+", stderr);
        }
        else {//（今までにコンソールがあり、表示する。）
            ShowWindow(Handle, SW_NORMAL);
        }
    }
    GetModuleInformation(GetCurrentProcess(), GetModuleHandle(NULL), &cModule.mInfo, sizeof(MODULEINFO));//なんかプロセスの情報もらってくる！！
    cModule.BaseAddress = (uintptr_t*)(cModule.mInfo.lpBaseOfDll);
    cModule.ClientInstance = Utils::FindPointer({ 0x5AD6078, 0x0,0x60,0x10,0x0 });
    MH_Initialize();


    for (;;) {
        if (GetAsyncKeyState(VK_END) & 1)
            break;
    }
    ShowWindow(Handle, SW_HIDE);
    FreeLibraryAndExitThread(HI, 0);
    return;
}