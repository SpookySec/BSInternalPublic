// dllmain.cpp : Defines the entry point for the DLL application.
#include <Windows.h>
#include <cstdio>
#include <cstdlib>
#include <conio.h>
#include <iostream>
#include <thread>
#include <MinHook.h>
#include <d3d11.h>
#include <string>

#include "../hdr/utils.h"
#include "../hdr/offsets.h"
#include "../hdr/hax.h"
#include "../hdr/config.h"
#include "../hdr/globals.h"

void HackThread(LPVOID hModule)
{
    Globals::Hax::gameAssembly = (uintptr_t)GetModuleHandle("GameAssembly.dll");

    FILE* fp;
    MH_STATUS hax_status;
    bool kiero_status = false;

    //fp = CreateConsole();

    printf("[+] DLL injected!\n");

    do
    {
        try
        {

            if (kiero::init(kiero::RenderType::D3D11) == kiero::Status::Success)
            {
                printf("[+] Kiero init success\n");
                kiero::bind(8, (void**)&Globals::Gui::oPresent, hkPresent);
                kiero_status = true;
            }

        }
        catch (...) {
            printf("FAILED\n");
        }


    } while (!kiero_status);

    printf("[+] Kiero hooks created successfully!\n");
    InitHooks();
    printf("[+] Cheat hooks created successfully!\n");

    //FreeConsole();
    //fclose(fp);
    while (!GetAsyncKeyState(VK_END))
        Sleep(200);
    
    kiero::shutdown();
    MH_DisableHook(MH_ALL_HOOKS);
    FreeLibraryAndExitThread(static_cast<HMODULE>(hModule), EXIT_SUCCESS);
}

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
    {
        DisableThreadLibraryCalls(hModule);
        const HANDLE hThread = CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)HackThread, hModule, NULL, NULL);
        
        if (hThread)
            CloseHandle(hThread); // so?
    }

    return TRUE;
}

