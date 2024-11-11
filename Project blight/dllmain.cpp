#include "Utils.hpp"
#include "Function.hpp"
#include "Hooks.hpp"
DWORD init(HINSTANCE HI);

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

DWORD init(HINSTANCE HI) {

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
    MH_Initialize();
    GetModuleInformation(GetCurrentProcess(), GetModuleHandle(NULL), &cModule.mInfo, sizeof(MODULEINFO));//なんかプロセスの情報もらってくる！！
    cModule.baseaddress = (uintptr_t*)(cModule.mInfo.lpBaseOfDll);
    cModule.clientinstance = (ClientInstance*)Utils::FindPointer({ 0x6A98318, 0x18,0x28,0x38,0x0 });//Get ClientInstance
#if _DEBUG
    cout << "DEBUG:" << endl
        << "BaseAddress " << cModule.baseaddress << endl
        << "ClientInstance " << cModule.clientinstance << endl;
#endif
    SetupFunctions();//setting up function to hook.
    CreateHooks();


    for (;;) {
        if (GetAsyncKeyState(VK_HOME) & 1)
        {
            cout << cModule.player << endl;
            cout << cModule.player->getLevel() << endl;


            //Utils::CallVF<vector<Actor>*,void*>()
        }
        if (GetAsyncKeyState(VK_END) & 1)
            break;
    }
    system("cls");
    ShowWindow(Handle, SW_HIDE);
    FreeLibraryAndExitThread(HI, 0);
    return 0;
}