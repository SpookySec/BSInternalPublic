#pragma once

#include "il2cpp.h"
#include "gui.h"
#include <vector>
#include <mutex>

namespace Globals
{
    namespace Hax
    {
        inline uintptr_t gameAssembly{ NULL };
        inline Multiplayer_Client_ClientPlayer_o* localPlayer{ NULL };
        inline std::mutex playerListMutex{};
        inline std::vector<Multiplayer_Client_ClientPlayer_o*> playerList{ NULL };

        inline tCreateExplosiveBullet oCreateExplosiveBullet{ NULL };
        inline tAddChat oAddChat{ NULL };
    }

    namespace Gui
    {
        inline Present oPresent;
        inline HWND window = NULL;
        inline WNDPROC oWndProc;
        inline ID3D11Device* pDevice = NULL;
        inline ID3D11DeviceContext* pContext = NULL;
        inline ID3D11RenderTargetView* mainRenderTargetView;

        inline ImGuiWindowFlags windowFlags = ImGuiWindowFlags_NoSavedSettings |
            ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoResize | 
            ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_AlwaysAutoResize |
            ImGuiWindowFlags_NoCollapse;

    }

    // Let's hope I don't need to use this
    namespace Backup
    {

    }
}