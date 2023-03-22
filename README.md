# A Banana shooter internal C++ cheat

## Features
Current features are as seen in `config.h`:

```c++
namespace Config
{
    inline bool spam = false; // Supposed to allow for chat spam, still in testing phase
    inline bool frog_mode = false; // Infinite jumps
    inline bool aim_assist = false; // Gives you aim assist (NOT AIMBOT BUT AIM ASSIST)
    inline bool super_speed = false; // Makes you the Flash
    inline bool swear_bypass = false; // Bypasses the cursing check (aka I can freely say niggas in paris)
    inline bool space_bullets = false; // Removes the gravity from all bullets
    inline bool fast_firerate = false; // Makes the fire rate EXTRAAA FAST
    inline bool school_shooter = false; // Lol this one allows you to shoot in the lobby and while the game count down is on
    inline bool disable_recoil = false; // No recoil as the name suggests
    inline bool instant_reload = false; // Makes the reload time to 0.f;
    inline bool armor_piercing = false; // Increases bullet wall penetration (seemingly allowing you to shoot through walls)
    inline bool explosive_melees = false; // Supposed to spawn explosive bullets but currently not working
    inline bool explosive_bullets = false; // My personal favorite, makes all your bullets explosive lol
}
```

## TODO
- [x] Add a proper IMGUI menu
- [ ] Think of more features (can use some help and inspiration)
- [x] Add ESP
- [x] Again make some way to enable/disable cheats on runtime, currently the only way to enable them is through the `config.h`
which requires recompiliation which is stupid
- [x] Figure out why it's sometimes crashing upon injection???
- [ ] Aimbot?
- [ ] Add hitbox enlargement

## Compiling
Honestly if you don't know how to compile a C++ project, then maybe you shouldn't be here.

Open the .sln file in Visual Studio, Ctrl + Shift + B to compile solution, find the produced DLL under `BSInternal/build/BSInternal.dll`

Use any injector, the game has no anti cheat so even Process Hacker's DLL injector should work fine.

## Demos
[![Demo Video](https://github.com/SpookySec/BSInternalPublic/raw/master/img/Banana_shooter_internal_showcase.gif)](https://youtu.be/j3O7KYmS2kk)

![IMGUI Menu](https://github.com/SpookySec/BSInternalPublic/blob/master/img/image.png)
