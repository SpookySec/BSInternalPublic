#include <MinHook.h>
#include <iostream>
#include <mutex>
#include "../hdr/offsets.h"
#include "../hdr/hax.h"
#include "../hdr/config.h"
#include "../hdr/globals.h"

//#define DEBUG

void __stdcall hkReload(Firearms_o* __this, float time, int32_t spinAmount, MethodInfo* method)
{
#ifdef DEBUG
    printf("[+] Firearms.Reload() called!\n");
#endif

    if (Config::instant_reload)
    {
        time = 0.f;
        spinAmount = 0;
        __this->fields.reloadTime = 0.f;
    }

    return oReload(__this, time, spinAmount, method);
}

void __stdcall hkCreateBullet(Firearms_o* __this, UnityEngine_Vector3_o point, MethodInfo* method)
{
#ifdef DEBUG
    printf("[+] Firearms.CreateBullet() called!\n");
#endif

    if (Config::explosive_bullets)
    {
        Globals::Hax::oCreateExplosiveBullet(__this, point, method);
    }

    return oCreateBullet(__this, point, method);
}

void __stdcall hkGunHit(Firearms_o* __this, UnityEngine_RaycastHit_o hit, bool wall, MethodInfo* method)
{
#ifdef DEBUG
    printf("[+] Firearms.Gunhit() called!\n");
#endif
    if (Config::explosive_bullets)
    {
        Globals::Hax::oCreateExplosiveBullet(__this, hit.fields.m_Point, method);
    }

    return oGunHit(__this, hit, wall, method);
}

void __stdcall hkHit(Firearms_o* __this, UnityEngine_RaycastHit_o hit, bool wall, MethodInfo* method)
{
#ifdef DEBUG
    printf("[+] Firearms.Hit() called!\n");
#endif
    if (Config::explosive_melees)
    {
        Globals::Hax::oCreateExplosiveBullet(__this, hit.fields.m_Point, method);
    }

    return oHit(__this, hit, wall, method);
}

bool __stdcall hkCheckMultiplayerGameModeStarted(Multiplayer_NetworkManager_o* __this, MethodInfo* method)
{
#ifdef DEBUG
    printf("[+] Multiplayer.CheckMultiplayerGameModeStarted() called!\n");
#endif

    if (Config::school_shooter)
        return false;

    return oCheckMultiplayerGameModeStarted(__this, method);
}

void __stdcall hkFirearms_Update(Firearms_o* __this, MethodInfo* method)
{
#ifdef DEBUG
    printf("[+] Firearms.Update() called!\n");
#endif

    if (Config::fast_firerate)
        __this->fields.fireRate = Config::Values::firerate;
    else
        __this->fields.fireRate = 10.f;

    if (Config::disable_recoil)
    {
        __this->fields.recoilX = 0.f;
        __this->fields.recoilY = 0.f;
        __this->fields.recoilZ = 0.f;

        __this->fields.force = 0.f;
        __this->fields._multiplayerWeapon->fields.gunDrag = 0.f;
        __this->fields.shootBack = 0.f;

        __this->fields.spreadAngle = 0.f;
        __this->fields.runSpread = 0.f;
        __this->fields.normalSpread = 0.f;
        __this->fields.bobSpeed = 0.f;
    }
    else
    {
        __this->fields.recoilX = -0.1f;
        __this->fields.recoilY = 0.1f;
        __this->fields.recoilZ = 0.05f;

        __this->fields.force = 1000.f;
        __this->fields._multiplayerWeapon->fields.gunDrag = 0.2f;
        __this->fields.shootBack = 1.f;

        // __this->fields.spreadAngle = DYNAMICALLY CALCULATED, SO NO NEED TO RESET
        // __this->fields.runSpread = DYNAMICALLY CALCULATED, SO NO NEED TO RESET
        // __this->fields.normalSpread = DYNAMICALLY CALCULATED, SO NO NEED TO RESET
        __this->fields.bobSpeed = 0.45f;
    }

    if (Config::space_bullets)
        __this->fields.useGravity = false;
    else
        __this->fields.useGravity = true;

    if (Config::full_auto)
        __this->fields.semiAuto = false;

    return oFirearms_Update(__this, method);
}

System_String_o* __stdcall hkSwearCheck(Chat_o* __this, System_String_o* str, MethodInfo* method)
{
    if (Config::swear_bypass)
        return str;


    return oSwearCheck(__this, str, method);
}

void __stdcall hkBullet_Initialization(Bullet_o* __this, UnityEngine_Vector3_o dir, float bulletSpeed, int32_t damage, UnityEngine_LayerMask_o layerMask, bool local, bool useGravity, MethodInfo* method)
{
#ifdef DEBUG
    printf("[+] Bullet.Initialize() called!\n");
#endif

    if (Config::armor_piercing)
        __this->fields.penetrationAmount = 9999.f;
    else
        __this->fields.penetrationAmount = 15.f;

    return oBullet_Initialization(__this, dir, bulletSpeed, damage, layerMask, local, useGravity, method);
}

void __stdcall hkClientPlayer_Update(Multiplayer_Client_ClientPlayer_o* __this, MethodInfo* method)
{
#ifdef DEBUG
    printf("[+] ClientPlayer.Update() called!\n");
#endif
    if (!__this || !__this->fields.m_CachedPtr)
        return oClientPlayer_Update(__this, method);

    bool in_list = false;
    for (auto client : Globals::Hax::playerList)
        if (client == __this)
            in_list = true;

    if (!in_list)
    {

        if (__this->fields._IsLocal_k__BackingField)
            Globals::Hax::localPlayer = __this;
        else
        {
            Globals::Hax::playerListMutex.lock();
            Globals::Hax::playerList.push_back(__this);
            Globals::Hax::playerListMutex.unlock();
        }
    }

    // Nothing here yet
    return oClientPlayer_Update(__this, method);
}

void __stdcall hkPlayerMovement_Update(PlayerMovement_o* __this, MethodInfo* method)
{
#ifdef DEBUG
    printf("[+] PlayerMovement.Update() called!\n");
#endif
    if (Config::aim_assist)
        __this->fields.aimAssist = true;
    else
        __this->fields.aimAssist = false;

    if (Config::frog_mode)
        __this->fields.jumpLeft = 2.f;
        // Since this gets called every Update() setting it to 2 is sufficient, but also allows for disabling
    
    if (Config::super_speed)
    {
        __this->fields.moveSpeed = Config::Values::movespeed;
        __this->fields.maxAirSpeed = Config::Values::speedfactor;
        __this->fields.moveSpeedFactor = Config::Values::speedfactor;
    }
    else
    {
        __this->fields.moveSpeed = 4500.f;
        __this->fields.maxAirSpeed = 1.f;
        __this->fields.moveSpeedFactor = 1.f;
    }

    return oPlayerMovement_Update(__this, method);
}

void __stdcall hkClientPlayer_TakeDamage(Multiplayer_Client_ClientPlayer_o* __this, int32_t damage, UnityEngine_Vector3_o point, UnityEngine_Vector3_o normal, uint16_t fromClient, bool hitMarket, MethodInfo* method)
{
    printf("[+] ClientPlayer.TakeDamage() called!\n");
    if (Config::no_damage)
    {
        return;
        damage = 0;
        __this->fields.health = 9999;
        __this->fields.maxHealth = 9999;
    }
    
    return oClientPlayer_TakeDamage(__this, damage, point, normal, fromClient, hitMarket, method);
}

void __stdcall hkKickVote_Update(KickVote_o* __this, MethodInfo* method)
{
    if (Config::dictatorship)
    {
        if (__this->klass->static_fields->VoteKicking)
            __this->klass->static_fields->VoteKicking->fields.disAgreeCount = 69;


        //__this->klass->static_fields->VoteKicking = NULL;
    }
}

MH_STATUS InitHooks()
{
    std::vector<MH_STATUS> hooks_status{};

    Globals::Hax::oCreateExplosiveBullet = (tCreateExplosiveBullet)(Globals::Hax::gameAssembly + Offsets::Firearms::CreateExplosiveBullet);
    Globals::Hax::oAddChat = (tAddChat)(Globals::Hax::gameAssembly + Offsets::Chat::AddChat);
    MH_STATUS status = MH_OK;

    // INSTA RELOAD
    hooks_status.push_back(MH_CreateHook(reinterpret_cast<LPVOID*>(Globals::Hax::gameAssembly + Offsets::Firearms::Reload), &hkReload, (LPVOID*)&oReload));
    hooks_status.push_back(MH_EnableHook(reinterpret_cast<LPVOID*>(Globals::Hax::gameAssembly + Offsets::Firearms::Reload)));

    // NO HITSCAN
    hooks_status.push_back(MH_CreateHook(reinterpret_cast<LPVOID*>(Globals::Hax::gameAssembly + Offsets::Firearms::CreateBullet), &hkCreateBullet, (LPVOID*)&oCreateBullet));
    hooks_status.push_back(MH_EnableHook(reinterpret_cast<LPVOID*>(Globals::Hax::gameAssembly + Offsets::Firearms::CreateBullet)));

    // ON HITSCAN
    hooks_status.push_back(MH_CreateHook(reinterpret_cast<LPVOID*>(Globals::Hax::gameAssembly + Offsets::Firearms::GunHit), &hkGunHit, (LPVOID*)&oGunHit));
    hooks_status.push_back(MH_EnableHook(reinterpret_cast<LPVOID*>(Globals::Hax::gameAssembly + Offsets::Firearms::GunHit)));

    // AVAILABLE TO SHOOT
    hooks_status.push_back(MH_CreateHook(reinterpret_cast<LPVOID*>(Globals::Hax::gameAssembly + Offsets::CheckMultiplayerGameModeStarted), &hkCheckMultiplayerGameModeStarted, (LPVOID*)&oCheckMultiplayerGameModeStarted));
    hooks_status.push_back(MH_EnableHook(reinterpret_cast<LPVOID*>(Globals::Hax::gameAssembly + Offsets::CheckMultiplayerGameModeStarted)));

    // EVERYTHING FIREARMS RELATED
    hooks_status.push_back(MH_CreateHook(reinterpret_cast<LPVOID*>(Globals::Hax::gameAssembly + Offsets::Firearms::Firearms_Update), &hkFirearms_Update, (LPVOID*)&oFirearms_Update));
    hooks_status.push_back(MH_EnableHook(reinterpret_cast<LPVOID*>(Globals::Hax::gameAssembly + Offsets::Firearms::Firearms_Update)));

    // SWEAR CHECK
    hooks_status.push_back(MH_CreateHook(reinterpret_cast<LPVOID*>(Globals::Hax::gameAssembly + Offsets::Chat::SwearCheck), &hkSwearCheck, (LPVOID*)&oSwearCheck));
    hooks_status.push_back(MH_EnableHook(reinterpret_cast<LPVOID*>(Globals::Hax::gameAssembly + Offsets::Chat::SwearCheck)));

    // AP BULLETS
    hooks_status.push_back(MH_CreateHook(reinterpret_cast<LPVOID*>(Globals::Hax::gameAssembly + Offsets::Bullet::Initialization), &hkBullet_Initialization, (LPVOID*)&oBullet_Initialization));
    hooks_status.push_back(MH_EnableHook(reinterpret_cast<LPVOID*>(Globals::Hax::gameAssembly + Offsets::Bullet::Initialization)));

    // CLIENT UPDATE
    //MH_CreateHook(reinterpret_cast<LPVOID*>(Globals::Hax::gameAssembly + Offsets::ClientPlayer::Update), &hkClientPlayer_Update, (LPVOID*)&oClientPlayer_Update);

    // PLAYERMOVEMENT UPDATE
    hooks_status.push_back(MH_CreateHook(reinterpret_cast<LPVOID*>(Globals::Hax::gameAssembly + Offsets::PlayerMovement::Update), &hkPlayerMovement_Update, (LPVOID*)&oPlayerMovement_Update));
    hooks_status.push_back(MH_EnableHook(reinterpret_cast<LPVOID*>(Globals::Hax::gameAssembly + Offsets::PlayerMovement::Update)));
    
    // TAKE DAMAGE
    hooks_status.push_back(MH_CreateHook(reinterpret_cast<LPVOID*>(Globals::Hax::gameAssembly + Offsets::ClientPlayer::TakeDamage), &hkClientPlayer_TakeDamage, (LPVOID*)&oClientPlayer_TakeDamage));
    hooks_status.push_back(MH_EnableHook(reinterpret_cast<LPVOID*>(Globals::Hax::gameAssembly + Offsets::ClientPlayer::TakeDamage)));

    hooks_status.push_back(MH_CreateHook(reinterpret_cast<LPVOID*>(Globals::Hax::gameAssembly + Offsets::VoteKicking::Update), &hkKickVote_Update, (LPVOID*)&oKickVote_Update));
    hooks_status.push_back(MH_EnableHook(reinterpret_cast<LPVOID*>(Globals::Hax::gameAssembly + Offsets::VoteKicking::Update)));
    
    for (auto status : hooks_status)
    {
        if (status != MH_OK)
            exit(1);
    }

    return MH_OK;
}