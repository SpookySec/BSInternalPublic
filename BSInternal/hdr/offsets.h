#pragma once

#include <Windows.h>

namespace Offsets {
    inline uintptr_t CheckMultiplayerGameModeStarted = 0x3e3090;

    namespace Chat
    {
        inline uintptr_t SwearCheck = 0x33e470;
        inline uintptr_t AddChat = 0x33ce00;
    }

    namespace Firearms
    {
        inline uintptr_t Reload = 0x3b5ae0;
        inline uintptr_t CreateBullet = 0x3adf90;
        inline uintptr_t CreateExplosiveBullet = 0x3ae4f0;
        inline uintptr_t GunHit = 0x3b2750;
        inline uintptr_t Hit = 0x3b3880;
        inline uintptr_t CalculateRecoil = 0x3b8a60;
        inline uintptr_t Firearms_Update = 0x3b6920;
    }

    namespace Bullet
    {
        inline uintptr_t Initialization = 0x3ab3b0;
    }

    namespace ClientPlayer
    {
        inline uintptr_t Update = 0x40fe70;
        inline uintptr_t TakeDamage = 0x40f130;
    }

    namespace PlayerMovement
    {
        inline uintptr_t Update = 0x3a2a20;
    }

    namespace VoteKicking
    {
        inline uintptr_t Update = 0x36aed0;
    }

    namespace Unity
    {
        inline uintptr_t transform = 0x1ca2650;
        inline uintptr_t position = 0x1cce680;
        inline uintptr_t current = 0x1c80bd0;
        inline uintptr_t WorldToScreen = 0x1c80810;
    }

    namespace Outline
    {
        inline uintptr_t onEnable = 0x34d780;
        inline uintptr_t onDisable = 0x34d660;
    }
}