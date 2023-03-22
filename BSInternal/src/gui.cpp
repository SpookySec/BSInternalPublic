#include "../hdr/gui.h"
#include "../hdr/globals.h"
#include "../hdr/config.h"

void InitGui()
{
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;
    //io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
    io.IniFilename = nullptr;
    io.LogFilename = nullptr;
    ImGui_ImplWin32_Init(Globals::Gui::window);
    ImGui_ImplDX11_Init(Globals::Gui::pDevice, Globals::Gui::pContext);

    ImGui::StyleColorsRed();
}

LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

    if (true && ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
        return true;

    return CallWindowProc(Globals::Gui::oWndProc, hWnd, uMsg, wParam, lParam);
}

bool init = false;
bool render = true;

HRESULT __stdcall hkPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags)
{
    if (GetAsyncKeyState(VK_INSERT) & 1)
        render = !render;

    if (!init)
    {
        if (SUCCEEDED(pSwapChain->GetDevice(__uuidof(ID3D11Device), (void**)&Globals::Gui::pDevice)))
        {
            Globals::Gui::pDevice->GetImmediateContext(&Globals::Gui::pContext);
            DXGI_SWAP_CHAIN_DESC sd;
            pSwapChain->GetDesc(&sd);
            Globals::Gui::window = sd.OutputWindow;
            ID3D11Texture2D* pBackBuffer;
            pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
            Globals::Gui::pDevice->CreateRenderTargetView(pBackBuffer, NULL, &Globals::Gui::mainRenderTargetView);
            pBackBuffer->Release();
            Globals::Gui::oWndProc = (WNDPROC)SetWindowLongPtr(Globals::Gui::window, GWLP_WNDPROC, (LONG_PTR)WndProc);
            InitGui();
            init = true;
        }

        else
            return Globals::Gui::oPresent(pSwapChain, SyncInterval, Flags);
    }

    ImGui_ImplDX11_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();

    Menu(render);

    // Code for updating the ent list every frame
    Globals::Hax::playerListMutex.lock();

    // ESP CODE HERE

    // Clear list
    Globals::Hax::playerList.clear();

    // Unlock
    Globals::Hax::playerListMutex.unlock();



    ImGui::Render();

    Globals::Gui::pContext->OMSetRenderTargets(1, &Globals::Gui::mainRenderTargetView, NULL);
    ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

    return Globals::Gui::oPresent(pSwapChain, SyncInterval, Flags);
}

void Menu(bool render)
{
    ImGui::SetNextWindowPos(ImVec2());
    ImGui::SetNextWindowSize(ImVec2(300.f, 340.f), ImGuiCond_Once);
 
    if (!render)
        return;
    
    ImGui::Begin("Spooky Hax", &::render, Globals::Gui::windowFlags);

    ImGui::Checkbox("Aim assist", &Config::aim_assist);
    ImGui::Checkbox("Wallhacks", &Config::wallhackz);
    ImGui::Checkbox("Fast firerate", &Config::fast_firerate);
    ImGui::Checkbox("Quick reload", &Config::instant_reload);
    ImGui::Checkbox("No recoil", &Config::disable_recoil);
    ImGui::Checkbox("Frog mode", &Config::frog_mode);
    ImGui::Checkbox("Super speed", &Config::super_speed);
    ImGui::Checkbox("AP bullets", &Config::armor_piercing);
    ImGui::Checkbox("Explosive bullets", &Config::explosive_bullets);
    ImGui::Checkbox("Swearing bypass", &Config::swear_bypass);
    ImGui::Checkbox("Space bullets", &Config::space_bullets);
    ImGui::Checkbox("Dictatorship", &Config::dictatorship);
    ImGui::Checkbox("Full auto (beta)", &Config::full_auto);
    ImGui::Checkbox("Explosive melees (beta)", &Config::explosive_melees);
    ImGui::Checkbox("School shooter (beta)", &Config::school_shooter);
    ImGui::Checkbox("No damage (beta)", &Config::no_damage);
    ImGui::Checkbox("Spam (beta)", &Config::spam);
    ImGui::Spacing();
    ImGui::Text("* (beta) is just a fancier");
    ImGui::Text("way of saying it's broken");

    if (Config::fast_firerate)
        ImGui::SliderFloat("Fire rate", &Config::Values::firerate, 10.f, 60.f);
    else
        Config::Values::firerate = 10.f;

    if (Config::super_speed)
    {
        ImGui::SliderFloat("Movement speed", &Config::Values::movespeed, 4500.f, 15000.f);
        ImGui::SliderFloat("Air speed", &Config::Values::speedfactor, 1.f, 10.f);
    }
       
    else
    {
        Config::Values::speedfactor = 1.f;
        Config::Values::movespeed = 4500.f;
    }

    // EXCLUSIVE LOADING ANIMATIONS NEVER SEEN BEFORE!!!
    if (ImGui::Button("DISABLE ALL", ImVec2(ImGui::GetWindowContentRegionWidth() * .999, 20)))
    {
        for (bool* opt : Config::conf)
        {
            *opt = false;
        }
    }

    if (ImGui::Button("ENABLE ALL", ImVec2(ImGui::GetWindowContentRegionWidth() * .999, 20)))
    {
        for (bool* opt : Config::conf)
        {
            *opt = true;
        }
    }

    ImGui::End();
}