#pragma once

#include <Windows.h>
#include <cstdio>
#include <MinHook.h>
#include "./il2cpp.h"

#define GUN    0x00000000
#define KNIFE  0x00000001
#define LASER  0x00000002
#define BOOMER 0x00000003

inline void(__fastcall* oReload)(Firearms_o*, float, int32_t, MethodInfo*);
void __stdcall hkReload(Firearms_o* __this, float time, int32_t spinAmount, MethodInfo* method);

inline void(__fastcall* oCreateBullet)(Firearms_o*, UnityEngine_Vector3_o, MethodInfo*);
void __stdcall hkCreateBullet(Firearms_o* __this, UnityEngine_Vector3_o point, MethodInfo* method);

inline void(__fastcall* oGunHit)(Firearms_o*, UnityEngine_RaycastHit_o, bool, MethodInfo*);
void __stdcall hkGunHit(Firearms_o* __this, UnityEngine_RaycastHit_o hit, bool wall, MethodInfo* method);

inline void(__fastcall* oHit)(Firearms_o*, UnityEngine_RaycastHit_o, bool, MethodInfo*);
void __stdcall hkHit(Firearms_o* __this, UnityEngine_RaycastHit_o hit, bool wall, MethodInfo* method);

inline bool(__fastcall* oCheckMultiplayerGameModeStarted)(Multiplayer_NetworkManager_o*, MethodInfo*);
bool __stdcall hkCheckMultiplayerGameModeStarted(Multiplayer_NetworkManager_o* __this, MethodInfo* method);

inline void(__fastcall* oFirearms_Update)(Firearms_o*, MethodInfo*);
void __stdcall hkFirearms_Update(Firearms_o* __this, MethodInfo* method);

inline System_String_o* (__fastcall* oSwearCheck)(Chat_o*, System_String_o*, MethodInfo*);
System_String_o* __stdcall hkSwearCheck(Chat_o* __this, System_String_o* str, MethodInfo* method);

inline void(__fastcall* oBullet_Initialization)(Bullet_o*, UnityEngine_Vector3_o, float, int32_t, UnityEngine_LayerMask_o, bool, bool, MethodInfo*);
void __stdcall hkBullet_Initialization(Bullet_o* __this, UnityEngine_Vector3_o dir, float bulletSpeed, int32_t damage, UnityEngine_LayerMask_o layerMask, bool local, bool useGravity, MethodInfo* method);

inline void(__fastcall* oClientPlayer_Update)(Multiplayer_Client_ClientPlayer_o*, MethodInfo*);
void __stdcall hkClientPlayer_Update(Multiplayer_Client_ClientPlayer_o* __this, MethodInfo* method);

inline void(__fastcall* oClientPlayer_TakeDamage)(Multiplayer_Client_ClientPlayer_o*, int32_t, UnityEngine_Vector3_o, UnityEngine_Vector3_o, uint16_t, bool, MethodInfo*);
void __stdcall hkClientPlayer_TakeDamage(Multiplayer_Client_ClientPlayer_o* __this, int32_t damage, UnityEngine_Vector3_o point, UnityEngine_Vector3_o normal, uint16_t fromClient, bool hitMarket, MethodInfo* method);


inline void(__fastcall* oPlayerMovement_Update)(PlayerMovement_o*, MethodInfo*);
void __stdcall hkPlayerMovement_Update(PlayerMovement_o* __this, MethodInfo* method);


MH_STATUS InitHooks();