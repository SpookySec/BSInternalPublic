#pragma once
#include "il2cpp.h"

namespace Config
{
    inline bool spam = false; // Supposed to allow for chat spam, still in testing phase
    inline bool full_auto = false; // Makes all guns shoot full auto
    inline bool frog_mode = false; // Infinite jumps
    inline bool no_damage = false; // Takes no damage
    inline bool aim_assist = false; // Gives you aim assist (NOT AIMBOT BUT AIM ASSIST)
    inline bool super_speed = false; // Makes you the Flash
    inline bool dictatorship = false; // So you a fan of putin?
    inline bool swear_bypass = false; // Bypasses the cursing check (aka I can freely say niggas in paris)
    inline bool space_bullets = false; // Removes the gravity from all bullets
    inline bool fast_firerate = false; // Makes the fire rate EXTRAAA FAST
    inline bool school_shooter = false; // Lol this one allows you to shoot in the lobby and while the game count down is on
    inline bool disable_recoil = false; // No recoil as the name suggests
    inline bool instant_reload = false; // Makes the reload time to 0.f;
    inline bool armor_piercing = false; // Increases bullet wall penetration (seemingly allowing you to shoot through walls)
    inline bool explosive_melees = false; // Supposed to spawn explosive bullets but currently not working
    inline bool explosive_bullets = false; // My personal favorite, makes all your bullets explosive lol
    inline bool* conf[] = {
        &spam, &full_auto, &frog_mode, &no_damage, &aim_assist, &super_speed, &swear_bypass,
        &space_bullets, &fast_firerate, &school_shooter, &disable_recoil, &instant_reload,
        &armor_piercing, &explosive_melees, &explosive_bullets, &dictatorship 
    }; // PLEASE NEVER LISTEN TO VANY AGAIN (more emphasis on this btw)

    namespace Values
    {
        inline float firerate = 10.f;
        inline float speedfactor = 1.f;
        inline float movespeed = 4500.f;
    }
}