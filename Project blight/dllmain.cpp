#include "Utils.hpp"
#include "Sigs.hpp"
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
    cModule.clientinstance = (ClientInstance*)Utils::FindPointer({ 0x5AD6078, 0x0,0x58,0x0,0x0 });//Get ClientInstance
    if (cModule.clientinstance == nullptr)
        return -1;
    auto GetPlayer = Utils::CreateFastCall<Player*, ClientInstance*, uintptr_t*>(Utils::GetAddressfromSignature(getplayer));
    cModule.player = GetPlayer(cModule.clientinstance, nullptr);//Get LocalPlayer
    if (cModule.player == nullptr)
        return -1;
    cModule.gamemode = cModule.player->GetGameMode();//Get GameMode
    if (cModule.gamemode == nullptr)
        return -1;

    for (;;) {
        if (GetAsyncKeyState(VK_END) & 1)
            break;
    }

    ShowWindow(Handle, SW_HIDE);
    FreeLibraryAndExitThread(HI, 0);
    return 0;
}