#pragma once

#include <cstdint>
#include <iostream>

typedef void(*Il2CppMethodPointer)();

struct MethodInfo;

struct VirtualInvokeData
{
    Il2CppMethodPointer methodPtr;
    const MethodInfo* method;
};

struct Il2CppType
{
    void* data;
    unsigned int bits;
};

struct Il2CppClass;

struct Il2CppObject
{
    Il2CppClass* klass;
    void* monitor;
};

union Il2CppRGCTXData
{
    void* rgctxDataDummy;
    const MethodInfo* method;
    const Il2CppType* type;
    Il2CppClass* klass;
};

struct Il2CppRuntimeInterfaceOffsetPair
{
    Il2CppClass* interfaceType;
    int32_t offset;
};
struct Il2CppClass_1
{
    void* image;
    void* gc_desc;
    const char* name;
    const char* namespaze;
    Il2CppType byval_arg;
    Il2CppType this_arg;
    Il2CppClass* element_class;
    Il2CppClass* castClass;
    Il2CppClass* declaringType;
    Il2CppClass* parent;
    void* generic_class;
    void* typeMetadataHandle;
    void* interopData;
    Il2CppClass* klass;
    void* fields;
    void* events;
    void* properties;
    void* methods;
    Il2CppClass** nestedTypes;
    Il2CppClass** implementedInterfaces;
    Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
};

struct Il2CppClass_2
{
    Il2CppClass** typeHierarchy;
    void* unity_user_data;
    uint32_t initializationExceptionGCHandle;
    uint32_t cctor_started;
    uint32_t cctor_finished;
    size_t cctor_thread;
    void* genericContainerHandle;
    uint32_t instance_size;
    uint32_t actualSize;
    uint32_t element_size;
    int32_t native_size;
    uint32_t static_fields_size;
    uint32_t thread_static_fields_size;
    int32_t thread_static_fields_offset;
    uint32_t flags;
    uint32_t token;
    uint16_t method_count;
    uint16_t property_count;
    uint16_t field_count;
    uint16_t event_count;
    uint16_t nested_type_count;
    uint16_t vtable_count;
    uint16_t interfaces_count;
    uint16_t interface_offsets_count;
    uint8_t typeHierarchyDepth;
    uint8_t genericRecursionDepth;
    uint8_t rank;
    uint8_t minimumAlignment;
    uint8_t naturalAligment;
    uint8_t packingSize;
    uint8_t bitflags1;
    uint8_t bitflags2;
};

struct Il2CppClass
{
    Il2CppClass_1 _1;
    void* static_fields;
    Il2CppRGCTXData* rgctx_data;
    Il2CppClass_2 _2;
    VirtualInvokeData vtable[255];
};

typedef uintptr_t il2cpp_array_size_t;
typedef int32_t il2cpp_array_lower_bound_t;
struct Il2CppArrayBounds
{
    il2cpp_array_size_t length;
    il2cpp_array_lower_bound_t lower_bound;
};

typedef void (*InvokerMethod)(Il2CppMethodPointer, const MethodInfo*, void*, void**, void*);
struct MethodInfo
{
    Il2CppMethodPointer methodPointer;
    Il2CppMethodPointer virtualMethodPointer;
    InvokerMethod invoker_method;
    const char* name;
    Il2CppClass* klass;
    const Il2CppType* return_type;
    const Il2CppType** parameters;
    union
    {
        const Il2CppRGCTXData* rgctx_data;
        const void* methodMetadataHandle;
    };
    union
    {
        const void* genericMethod;
        const void* genericContainerHandle;
    };
    uint32_t token;
    uint16_t flags;
    uint16_t iflags;
    uint16_t slot;
    uint8_t parameters_count;
    uint8_t bitflags;
};

struct __declspec(align(8)) UnityEngine_Object_Fields {
    intptr_t m_CachedPtr;
};

struct UnityEngine_Component_Fields : UnityEngine_Object_Fields {
};

struct UnityEngine_Behaviour_Fields : UnityEngine_Component_Fields {
};

struct UnityEngine_MonoBehaviour_Fields : UnityEngine_Behaviour_Fields {
};

struct __declspec(align(8)) System_String_Fields {
    int32_t _stringLength;
    uint16_t _firstChar;
};
struct System_String_VTable {
    VirtualInvokeData _0_Equals;
    VirtualInvokeData _1_Finalize;
    VirtualInvokeData _2_GetHashCode;
    VirtualInvokeData _3_ToString;
    VirtualInvokeData _4_CompareTo;
    VirtualInvokeData _5_System_Collections_IEnumerable_GetEnumerator;
    VirtualInvokeData _6_System_Collections_Generic_IEnumerable_System_Char__GetEnumerator;
    VirtualInvokeData _7_CompareTo;
    VirtualInvokeData _8_Equals;
    VirtualInvokeData _9_GetTypeCode;
    VirtualInvokeData _10_System_IConvertible_ToBoolean;
    VirtualInvokeData _11_System_IConvertible_ToChar;
    VirtualInvokeData _12_System_IConvertible_ToSByte;
    VirtualInvokeData _13_System_IConvertible_ToByte;
    VirtualInvokeData _14_System_IConvertible_ToInt16;
    VirtualInvokeData _15_System_IConvertible_ToUInt16;
    VirtualInvokeData _16_System_IConvertible_ToInt32;
    VirtualInvokeData _17_System_IConvertible_ToUInt32;
    VirtualInvokeData _18_System_IConvertible_ToInt64;
    VirtualInvokeData _19_System_IConvertible_ToUInt64;
    VirtualInvokeData _20_System_IConvertible_ToSingle;
    VirtualInvokeData _21_System_IConvertible_ToDouble;
    VirtualInvokeData _22_System_IConvertible_ToDecimal;
    VirtualInvokeData _23_System_IConvertible_ToDateTime;
    VirtualInvokeData _24_ToString;
    VirtualInvokeData _25_System_IConvertible_ToType;
    VirtualInvokeData _26_Clone;
};
struct System_String_c {
    Il2CppClass_1 _1;
    struct System_String_StaticFields* static_fields;
    Il2CppRGCTXData* rgctx_data;
    Il2CppClass_2 _2;
    System_String_VTable vtable;
};
struct System_String_o {
    System_String_c* klass;
    void* monitor;
    System_String_Fields fields;
};
struct System_String_StaticFields {
    struct System_String_o* Empty;
};

struct __declspec(align(8)) System_Collections_Generic_List_string__Fields {
    struct System_String_array* _items;
    int32_t _size;
    int32_t _version;
    Il2CppObject* _syncRoot;
};
struct System_Collections_Generic_List_string__VTable {
    VirtualInvokeData _0_Equals;
    VirtualInvokeData _1_Finalize;
    VirtualInvokeData _2_GetHashCode;
    VirtualInvokeData _3_ToString;
    VirtualInvokeData _4_unknown;
    VirtualInvokeData _5_set_Item;
    VirtualInvokeData _6_IndexOf;
    VirtualInvokeData _7_Insert;
    VirtualInvokeData _8_unknown;
    VirtualInvokeData _9_unknown;
    VirtualInvokeData _10_System_Collections_Generic_ICollection_T__get_IsReadOnly;
    VirtualInvokeData _11_Add;
    VirtualInvokeData _12_unknown;
    VirtualInvokeData _13_Contains;
    VirtualInvokeData _14_CopyTo;
    VirtualInvokeData _15_Remove;
    VirtualInvokeData _16_System_Collections_Generic_IEnumerable_T__GetEnumerator;
    VirtualInvokeData _17_System_Collections_IEnumerable_GetEnumerator;
    VirtualInvokeData _18_System_Collections_IList_get_Item;
    VirtualInvokeData _19_System_Collections_IList_set_Item;
    VirtualInvokeData _20_System_Collections_IList_Add;
    VirtualInvokeData _21_System_Collections_IList_Contains;
    VirtualInvokeData _22_Clear;
    VirtualInvokeData _23_System_Collections_IList_get_IsReadOnly;
    VirtualInvokeData _24_System_Collections_IList_get_IsFixedSize;
    VirtualInvokeData _25_System_Collections_IList_IndexOf;
    VirtualInvokeData _26_System_Collections_IList_Insert;
    VirtualInvokeData _27_System_Collections_IList_Remove;
    VirtualInvokeData _28_RemoveAt;
    VirtualInvokeData _29_System_Collections_ICollection_CopyTo;
    VirtualInvokeData _30_unknown;
    VirtualInvokeData _31_System_Collections_ICollection_get_SyncRoot;
    VirtualInvokeData _32_System_Collections_ICollection_get_IsSynchronized;
    VirtualInvokeData _33_get_Item;
    VirtualInvokeData _34_get_Count;
};
struct System_Collections_Generic_List_string__c {
    Il2CppClass_1 _1;
    struct System_Collections_Generic_List_string__StaticFields* static_fields;
    Il2CppRGCTXData* rgctx_data;
    Il2CppClass_2 _2;
    System_Collections_Generic_List_string__VTable vtable;
};
struct System_Collections_Generic_List_string__o {
    System_Collections_Generic_List_string__c* klass;
    void* monitor;
    System_Collections_Generic_List_string__Fields fields;
};
struct System_Collections_Generic_List_string__StaticFields {
    struct System_String_array* s_emptyArray;
};

struct System_Type_StaticFields {
    struct System_Reflection_Binder_o* s_defaultBinder;
    uint16_t Delimiter;
    struct System_Type_array* EmptyTypes;
    Il2CppObject* Missing;
    struct System_Reflection_MemberFilter_o* FilterAttribute;
    struct System_Reflection_MemberFilter_o* FilterName;
    struct System_Reflection_MemberFilter_o* FilterNameIgnoreCase;
};

struct System_IntPtr_array {
    Il2CppObject obj;
    Il2CppArrayBounds* bounds;
    il2cpp_array_size_t max_length;
    intptr_t m_Items[65535];
};
struct System_Char_array {
    Il2CppObject obj;
    Il2CppArrayBounds* bounds;
    il2cpp_array_size_t max_length;
    uint16_t m_Items[65535];
};
struct System_Int32_array {
    Il2CppObject obj;
    Il2CppArrayBounds* bounds;
    il2cpp_array_size_t max_length;
    int32_t m_Items[65535];
};
struct System_Int64_array {
    Il2CppObject obj;
    Il2CppArrayBounds* bounds;
    il2cpp_array_size_t max_length;
    int64_t m_Items[65535];
};
struct System_Byte_array {
    Il2CppObject obj;
    Il2CppArrayBounds* bounds;
    il2cpp_array_size_t max_length;
    uint8_t m_Items[65535];
};
struct System_Object_array {
    Il2CppObject obj;
    Il2CppArrayBounds* bounds;
    il2cpp_array_size_t max_length;
    Il2CppObject* m_Items[65535];
};
struct System_String_array {
    Il2CppObject obj;
    Il2CppArrayBounds* bounds;
    il2cpp_array_size_t max_length;
    System_String_o* m_Items[65535];
};

struct UnityEngine_Vector3_Fields {
    float x;
    float y;
    float z;
};
struct UnityEngine_Vector3_VTable {
    VirtualInvokeData _0_Equals;
    VirtualInvokeData _1_Finalize;
    VirtualInvokeData _2_GetHashCode;
    VirtualInvokeData _3_ToString;
    VirtualInvokeData _4_Equals;
    VirtualInvokeData _5_ToString;
};
struct UnityEngine_Vector3_c {
    Il2CppClass_1 _1;
    struct UnityEngine_Vector3_StaticFields* static_fields;
    Il2CppRGCTXData* rgctx_data;
    Il2CppClass_2 _2;
    UnityEngine_Vector3_VTable vtable;
};
struct UnityEngine_Vector3_o {
    UnityEngine_Vector3_Fields fields;
};
struct UnityEngine_Vector3_StaticFields {
    struct UnityEngine_Vector3_o zeroVector;
    struct UnityEngine_Vector3_o oneVector;
    struct UnityEngine_Vector3_o upVector;
    struct UnityEngine_Vector3_o downVector;
    struct UnityEngine_Vector3_o leftVector;
    struct UnityEngine_Vector3_o rightVector;
    struct UnityEngine_Vector3_o forwardVector;
    struct UnityEngine_Vector3_o backVector;
    struct UnityEngine_Vector3_o positiveInfinityVector;
    struct UnityEngine_Vector3_o negativeInfinityVector;
};

struct UnityEngine_Vector2_Fields {
    float x;
    float y;
};
struct UnityEngine_Vector2_VTable {
    VirtualInvokeData _0_Equals;
    VirtualInvokeData _1_Finalize;
    VirtualInvokeData _2_GetHashCode;
    VirtualInvokeData _3_ToString;
    VirtualInvokeData _4_Equals;
    VirtualInvokeData _5_ToString;
};
struct UnityEngine_Vector2_c {
    Il2CppClass_1 _1;
    struct UnityEngine_Vector2_StaticFields* static_fields;
    Il2CppRGCTXData* rgctx_data;
    Il2CppClass_2 _2;
    UnityEngine_Vector2_VTable vtable;
};
struct UnityEngine_Vector2_o {
    UnityEngine_Vector2_Fields fields;
};
struct UnityEngine_Vector2_StaticFields {
    struct UnityEngine_Vector2_o zeroVector;
    struct UnityEngine_Vector2_o oneVector;
    struct UnityEngine_Vector2_o upVector;
    struct UnityEngine_Vector2_o downVector;
    struct UnityEngine_Vector2_o leftVector;
    struct UnityEngine_Vector2_o rightVector;
    struct UnityEngine_Vector2_o positiveInfinityVector;
    struct UnityEngine_Vector2_o negativeInfinityVector;
};


struct UnityEngine_RaycastHit_Fields {
    struct UnityEngine_Vector3_o m_Point;
    struct UnityEngine_Vector3_o m_Normal;
    uint32_t m_FaceID;
    float m_Distance;
    struct UnityEngine_Vector2_o m_UV;
    int32_t m_Collider;
};
struct UnityEngine_RaycastHit_VTable {
    VirtualInvokeData _0_Equals;
    VirtualInvokeData _1_Finalize;
    VirtualInvokeData _2_GetHashCode;
    VirtualInvokeData _3_ToString;
};
struct UnityEngine_RaycastHit_c {
    Il2CppClass_1 _1;
    void* static_fields;
    Il2CppRGCTXData* rgctx_data;
    Il2CppClass_2 _2;
    UnityEngine_RaycastHit_VTable vtable;
};
struct UnityEngine_RaycastHit_o {
    UnityEngine_RaycastHit_Fields fields;
};

struct MultiplayerWeapon_Fields : UnityEngine_MonoBehaviour_Fields {
    int32_t Type;
    struct UnityEngine_Animator_o* animator;
    struct System_String_o* name;
    struct UnityEngine_Transform_o* leftHand;
    struct UnityEngine_Transform_o* rightHand;
    struct UnityEngine_Transform_o* tip;
    float spreadAngle;
    struct UnityEngine_ParticleSystem_o* particleSystem;
    struct UnityEngine_AudioClip_o* shoot;
    struct UnityEngine_AudioClip_o* reload;
    struct UnityEngine_AudioClip_o* reset;
    bool isLocal;
    bool dual;
    struct UnityEngine_Transform_o* lTip;
    struct UnityEngine_Transform_o* rTip;
    struct UnityEngine_ParticleSystem_o* lPart;
    struct UnityEngine_ParticleSystem_o* rPart;
    bool leftSide;
    bool useGravity;
    float reloadTime;
    float shootVertical;
    float shootHorizontal;
    float shootRotX;
    float shootRotZMultiplier;
    float shootRotYMultiplier;
    struct UnityEngine_Vector3_o startPos;
    struct UnityEngine_Vector3_o desiredBob;
    float xBob;
    float yBob;
    float zBob;
    float bobSpeed;
    struct UnityEngine_Vector3_o recoilOffset;
    struct UnityEngine_Vector3_o recoilRotation;
    struct UnityEngine_Vector3_o recoilOffsetVel;
    struct UnityEngine_Vector3_o recoilRotVel;
    float reloadRotation;
    float desiredReloadRotation;
    float reloadTimet;
    float rVel;
    float reloadPosOffset;
    float rPVel;
    float gunDrag;
    float desX;
    float desY;
    struct UnityEngine_Vector3_o speedBob;
    float reloadProgress;
    float rotationOffset;
    struct UnityEngine_Vector3_o prevRotation;
    int32_t spins;
    struct System_Collections_Generic_List_GameObject__o* skins;
};
struct MultiplayerWeapon_VTable {
    VirtualInvokeData _0_Equals;
    VirtualInvokeData _1_Finalize;
    VirtualInvokeData _2_GetHashCode;
    VirtualInvokeData _3_ToString;
};
struct MultiplayerWeapon_c {
    Il2CppClass_1 _1;
    void* static_fields;
    Il2CppRGCTXData* rgctx_data;
    Il2CppClass_2 _2;
    MultiplayerWeapon_VTable vtable;
};
struct MultiplayerWeapon_o {
    MultiplayerWeapon_c* klass;
    void* monitor;
    MultiplayerWeapon_Fields fields;
};

struct UnityEngine_Rigidbody_Fields : UnityEngine_Component_Fields {
};
struct UnityEngine_Rigidbody_VTable {
    VirtualInvokeData _0_Equals;
    VirtualInvokeData _1_Finalize;
    VirtualInvokeData _2_GetHashCode;
    VirtualInvokeData _3_ToString;
};
struct UnityEngine_Rigidbody_c {
    Il2CppClass_1 _1;
    void* static_fields;
    Il2CppRGCTXData* rgctx_data;
    Il2CppClass_2 _2;
    UnityEngine_Rigidbody_VTable vtable;
};
struct UnityEngine_Rigidbody_o {
    UnityEngine_Rigidbody_c* klass;
    void* monitor;
    UnityEngine_Rigidbody_Fields fields;
};
struct UnityEngine_Collider_Fields : UnityEngine_Component_Fields {
};
struct UnityEngine_Collider_VTable {
    VirtualInvokeData _0_Equals;
    VirtualInvokeData _1_Finalize;
    VirtualInvokeData _2_GetHashCode;
    VirtualInvokeData _3_ToString;
};
struct UnityEngine_Collider_c {
    Il2CppClass_1 _1;
    void* static_fields;
    Il2CppRGCTXData* rgctx_data;
    Il2CppClass_2 _2;
    UnityEngine_Collider_VTable vtable;
};
struct UnityEngine_Collider_o {
    UnityEngine_Collider_c* klass;
    void* monitor;
    UnityEngine_Collider_Fields fields;
};

struct Firearms_Fields : UnityEngine_MonoBehaviour_Fields {
    bool useArm;
    struct UnityEngine_Transform_o* arm;
    struct UnityEngine_Transform_o* weapon;
    int32_t weaponIndex;
    struct UnityEngine_Transform_o* leftHandIK;
    struct UnityEngine_Transform_o* rightHandIK;
    int32_t weaponType;
    float waitTimeToAttack;
    struct UnityEngine_Transform_o* muzzlePoint;
    struct UnityEngine_ParticleSystem_o* muzzleParticle;
    struct UnityEngine_AudioClip_o* shoot;
    struct UnityEngine_AudioClip_o* reload;
    struct UnityEngine_AudioClip_o* reset;
    bool useGravity;
    int32_t maxAmmo;
    struct Safe_SafeInt_o* currentAmmo;
    float fireRate;
    struct UnityEngine_Animator_o* animator;
    bool cantReload;
    float lastFireTime;
    bool allowHolding;
    float reloadMultiplier;
    struct Replay_ReplayPlayer_o* _replayPlayer;
    bool shooting;
    bool isAiming;
    float drag;
    int32_t bulletCount;
    bool createBullet;
    struct System_Collections_Generic_List_ClientPlayer__o* hitPlayer;
    struct UnityEngine_RaycastHit_array* hits;
    struct MultiplayerWeapon_o* _multiplayerWeapon;
    float recoilX;
    float recoilY;
    float recoilZ;
    float force;
    bool semiAuto;
    struct UnityEngine_Transform_o* camera;
    struct UnityEngine_RaycastHit_array* _hit;
    struct System_Collections_Generic_List_Enemy__o* enemies;
    struct System_Collections_Generic_List_ClientEnemy__o* clientEnemies;
    struct System_Collections_Generic_List_ClientPlayer__o* clients;
    struct System_Collections_Generic_List_ShootingTarget__o* shootingTarget;
    struct System_Collections_Generic_List_ShootingTarget2__o* shootingTarget2;
    struct UnityEngine_Collider_array* colliders;
    struct UnityEngine_Vector3_o aimPos;
    bool allowToAim;
    struct SmokeTrail_o* trail;
    int32_t spinAmount;
    bool isReload;
    struct Multiplayer_Client_ClientPlayer_o* _player;
    bool animateUi;
    int32_t damage;
    float spreadAngle;
    float normalSpread;
    float runSpread;
    float normalReloadTime;
    float reloadTime;
    float shootBack;
    float shootVertical;
    float shootHorizontal;
    float shootRotX;
    float shootRotZMultiplier;
    float shootRotYMultiplier;
    struct UnityEngine_Rigidbody_o* rb;
    struct UnityEngine_Camera_o* PlayerCam;
    struct UnityEngine_Vector3_o startPos;
    struct UnityEngine_Vector3_o desiredBob;
    float xBob;
    float yBob;
    float zBob;
    float bobSpeed;
    struct UnityEngine_Vector3_o recoilOffset;
    struct UnityEngine_Vector3_o recoilRotation;
    struct UnityEngine_Vector3_o recoilOffsetVel;
    struct UnityEngine_Vector3_o recoilRotVel;
    float reloadRotation;
    float desiredReloadRotation;
    float reloadTimet;
    float rVel;
    float reloadPosOffset;
    float rPVel;
    float gunDrag;
    float currentGunDragMultiplier;
    float desX;
    float desY;
    struct UnityEngine_Vector3_o speedBob;
    float reloadProgress;
    float rotationOffset;
    struct UnityEngine_Vector3_o prevRotation;
    int32_t spins;
};
struct Firearms_VTable {
    VirtualInvokeData _0_Equals;
    VirtualInvokeData _1_Finalize;
    VirtualInvokeData _2_GetHashCode;
    VirtualInvokeData _3_ToString;
    VirtualInvokeData _4_DoAttack;
    VirtualInvokeData _5_DoAim;
    VirtualInvokeData _6_DoNoAim;
    VirtualInvokeData _7_DoReload;
    VirtualInvokeData _8_Select;
    VirtualInvokeData _9_DeSelect;
    VirtualInvokeData _10_Start;
    VirtualInvokeData _11_Update;
};

struct Firearms_c {
    Il2CppClass_1 _1;
    struct Firearms_StaticFields* static_fields;
    Il2CppRGCTXData* rgctx_data;
    Il2CppClass_2 _2;
    Firearms_VTable vtable;
};
struct Firearms_o {
    Firearms_c* klass;
    void* monitor;
    Firearms_Fields fields;
};
struct Firearms_StaticFields {
    int32_t Attack;
};

struct Recoil_Fields : UnityEngine_MonoBehaviour_Fields {
    struct UnityEngine_Vector3_o currentRotation;
    struct UnityEngine_Vector3_o targetRotation;
    float snappiness;
    float returnSpeed;
    float recoilFactor;
};
struct Recoil_VTable {
    VirtualInvokeData _0_Equals;
    VirtualInvokeData _1_Finalize;
    VirtualInvokeData _2_GetHashCode;
    VirtualInvokeData _3_ToString;
};
struct Recoil_c {
    Il2CppClass_1 _1;
    struct Recoil_StaticFields* static_fields;
    Il2CppRGCTXData* rgctx_data;
    Il2CppClass_2 _2;
    Recoil_VTable vtable;
};
struct Recoil_o {
    Recoil_c* klass;
    void* monitor;
    Recoil_Fields fields;
};
struct Recoil_StaticFields {
    struct Recoil_o* Instance;
};

struct Steamworks_CSteamID_Fields {
    uint64_t m_SteamID;
};
struct Steamworks_CSteamID_VTable {
    VirtualInvokeData _0_Equals;
    VirtualInvokeData _1_Finalize;
    VirtualInvokeData _2_GetHashCode;
    VirtualInvokeData _3_ToString;
    VirtualInvokeData _4_Equals;
    VirtualInvokeData _5_CompareTo;
};
struct Steamworks_CSteamID_c {
    Il2CppClass_1 _1;
    struct Steamworks_CSteamID_StaticFields* static_fields;
    Il2CppRGCTXData* rgctx_data;
    Il2CppClass_2 _2;
    Steamworks_CSteamID_VTable vtable;
};
struct Steamworks_CSteamID_o {
    Steamworks_CSteamID_Fields fields;
};
struct Steamworks_CSteamID_StaticFields {
    struct Steamworks_CSteamID_o Nil;
    struct Steamworks_CSteamID_o OutofDateGS;
    struct Steamworks_CSteamID_o LanModeGS;
    struct Steamworks_CSteamID_o NotInitYetGS;
    struct Steamworks_CSteamID_o NonSteamGS;
};

struct Multiplayer_NetworkManager_Fields : UnityEngine_MonoBehaviour_Fields {
    struct UnityEngine_GameObject_o* serverPlayerPrefab;
    struct UnityEngine_GameObject_o* playerPrefab;
    struct UnityEngine_GameObject_o* localPlayerPrefab;
    uint16_t readyPlayerCount;
    struct Riptide_Server_o* _Server_k__BackingField;
    struct Riptide_Client_o* _Client_k__BackingField;
    struct System_Collections_Generic_List_Map__o* maps;
    struct System_String_array* weapons;
    bool isStarted;
    struct GameModes_o* game;
    struct System_Collections_Generic_List_UIManager_WeaponTexture__o* weaponTexture;
    struct Steamworks_CSteamID_o steamId;
    struct Steamworks_CSteamID_o currentGroup;
    struct System_Action_GameMode__o* GameModeChanged;
    bool displayTag;
    int32_t _SendByte_k__BackingField;
    int32_t _ByteUp_k__BackingField;
    int32_t _ReadByte_k__BackingField;
    int32_t _ByteDown_k__BackingField;
    struct Steamworks_Callback_AvatarImageLoaded_t__o* ImageLoaded;
    struct UnityEngine_Texture2D_o* myAvatar;
    int32_t WinCount;
    bool connecting;
    bool testMode;
    struct System_String_o* map;
    uint16_t _CurrentTick_k__BackingField;
    uint16_t _serverTick;
    uint16_t _InterpolationTick_k__BackingField;
    uint16_t _ticksBetweenPositionUpdates;
    uint16_t tickDivergenceTolerance;
    struct System_Collections_Generic_Queue_NetworkManager_BoxListItem__o* boxes;
    float leftTimeToStart;
    struct System_Collections_Generic_Dictionary_string__ushort__o* mapVote;
    struct System_Collections_Generic_Dictionary_string__ushort__o* gameModeVote;
    struct UnityEngine_Coroutine_o* startGame;
    bool gameStarted;
    struct UnityEngine_Localization_Locale_array* language;
    bool isStop;
};
struct Multiplayer_NetworkManager_VTable {
    VirtualInvokeData _0_Equals;
    VirtualInvokeData _1_Finalize;
    VirtualInvokeData _2_GetHashCode;
    VirtualInvokeData _3_ToString;
};
struct Multiplayer_NetworkManager_c {
    Il2CppClass_1 _1;
    struct Multiplayer_NetworkManager_StaticFields* static_fields;
    Il2CppRGCTXData* rgctx_data;
    Il2CppClass_2 _2;
    Multiplayer_NetworkManager_VTable vtable;
};
struct Multiplayer_NetworkManager_o {
    Multiplayer_NetworkManager_c* klass;
    void* monitor;
    Multiplayer_NetworkManager_Fields fields;
};
struct Multiplayer_NetworkManager_StaticFields {
    struct Multiplayer_NetworkManager_o* _instance;
    int32_t _VoteCount_k__BackingField;
    int32_t _ServerType_k__BackingField;
    int32_t _ClientServerType_k__BackingField;
    uint16_t _ServerGameMode_k__BackingField;
    uint16_t _ClientGameMode_k__BackingField;
    struct System_Collections_Generic_List_ulong__o* BannedPlayer;
    struct System_Collections_Generic_Dictionary_string__bool__o* AllowedWeapon;
    struct System_Collections_Generic_Dictionary_ushort__ClientData__o* ClientData;
    bool RandomMap;
    bool RandomGameMode;
    bool _ServerDisableSpecialWeapon_k__BackingField;
    bool _ClientDisableSpecialWeapon_k__BackingField;
};

struct Chat_Fields : UnityEngine_MonoBehaviour_Fields {
    struct UnityEngine_CanvasGroup_o* group;
    float desiredAlpha;
    float bgAlpha;
    uint64_t steamId;
    struct TMPro_TMP_InputField_o* input;
    struct UnityEngine_UI_Image_o* bg;
    struct System_Collections_Generic_List_string__o* swear;
    struct UnityEngine_Transform_o* c;
};
struct Chat_VTable {
    VirtualInvokeData _0_Equals;
    VirtualInvokeData _1_Finalize;
    VirtualInvokeData _2_GetHashCode;
    VirtualInvokeData _3_ToString;
};
struct Chat_c {
    Il2CppClass_1 _1;
    struct Chat_StaticFields* static_fields;
    Il2CppRGCTXData* rgctx_data;
    Il2CppClass_2 _2;
    Chat_VTable vtable;
};
struct Chat_o {
    Chat_c* klass;
    void* monitor;
    Chat_Fields fields;
};
struct Chat_StaticFields {
    struct Chat_o* Instance;
};

struct UnityEngine_LayerMask_Fields {
    int32_t m_Mask;
};
struct UnityEngine_LayerMask_VTable {
    VirtualInvokeData _0_Equals;
    VirtualInvokeData _1_Finalize;
    VirtualInvokeData _2_GetHashCode;
    VirtualInvokeData _3_ToString;
};
struct UnityEngine_LayerMask_c {
    Il2CppClass_1 _1;
    void* static_fields;
    Il2CppRGCTXData* rgctx_data;
    Il2CppClass_2 _2;
    UnityEngine_LayerMask_VTable vtable;
};
struct UnityEngine_LayerMask_o {
    UnityEngine_LayerMask_Fields fields;
};

struct Bullet_Fields : UnityEngine_MonoBehaviour_Fields {
    int32_t type;
    float speed;
    int32_t damage;
    struct UnityEngine_Transform_o* selfTrans;
    bool initialized;
    struct UnityEngine_Vector3_o startPos;
    struct UnityEngine_Rigidbody_o* rb;
    bool isLocal;
    struct UnityEngine_Vector3_o dir;
    struct UnityEngine_TrailRenderer_o* _renderer;
    struct Firearms_o* weapon;
    bool hited;
    struct UnityEngine_Transform_o* smoke;
    struct System_Collections_Generic_List_Enemy__o* enemies;
    struct System_Collections_Generic_List_ClientPlayer__o* clients;
    struct System_Collections_Generic_List_ClientEnemy__o* clientEnemies;
    struct System_Collections_Generic_List_ShootingTarget__o* shootingTarget;
    struct System_Collections_Generic_List_ShootingTarget2__o* shootingTarget2;
    struct UnityEngine_Collider_array* colliders;
    float penetrationAmount;
    struct UnityEngine_RaycastHit_array* hits;
};
struct Bullet_VTable {
    VirtualInvokeData _0_Equals;
    VirtualInvokeData _1_Finalize;
    VirtualInvokeData _2_GetHashCode;
    VirtualInvokeData _3_ToString;
    VirtualInvokeData _4_OnObjectSpawn;
    VirtualInvokeData _5_OnObjectInit;
};
struct Bullet_c {
    Il2CppClass_1 _1;
    void* static_fields;
    Il2CppRGCTXData* rgctx_data;
    Il2CppClass_2 _2;
    Bullet_VTable vtable;
};
struct Bullet_o {
    Bullet_c* klass;
    void* monitor;
    Bullet_Fields fields;
};

struct UnityEngine_CapsuleCollider_Fields : UnityEngine_Collider_Fields {
};
struct UnityEngine_CapsuleCollider_VTable {
    VirtualInvokeData _0_Equals;
    VirtualInvokeData _1_Finalize;
    VirtualInvokeData _2_GetHashCode;
    VirtualInvokeData _3_ToString;
};
struct UnityEngine_CapsuleCollider_c {
    Il2CppClass_1 _1;
    void* static_fields;
    Il2CppRGCTXData* rgctx_data;
    Il2CppClass_2 _2;
    UnityEngine_CapsuleCollider_VTable vtable;
};
struct UnityEngine_CapsuleCollider_o {
    UnityEngine_CapsuleCollider_c* klass;
    void* monitor;
    UnityEngine_CapsuleCollider_Fields fields;
};

struct UnityEngine_Quaternion_Fields {
    float x;
    float y;
    float z;
    float w;
};
struct UnityEngine_Quaternion_VTable {
    VirtualInvokeData _0_Equals;
    VirtualInvokeData _1_Finalize;
    VirtualInvokeData _2_GetHashCode;
    VirtualInvokeData _3_ToString;
    VirtualInvokeData _4_Equals;
    VirtualInvokeData _5_ToString;
};
struct UnityEngine_Quaternion_c {
    Il2CppClass_1 _1;
    struct UnityEngine_Quaternion_StaticFields* static_fields;
    Il2CppRGCTXData* rgctx_data;
    Il2CppClass_2 _2;
    UnityEngine_Quaternion_VTable vtable;
};
struct UnityEngine_Quaternion_o {
    UnityEngine_Quaternion_Fields fields;
};
struct UnityEngine_Quaternion_StaticFields {
    struct UnityEngine_Quaternion_o identityQuaternion;
};


struct Multiplayer_Client_ClientPlayer_Fields : UnityEngine_MonoBehaviour_Fields {
    struct PlayerMovement_o* playerMovement;
    struct Replay_ReplayPlayer_o* replayPlayer;
    uint64_t _SteamId_k__BackingField;
    uint16_t _Id_k__BackingField;
    struct System_String_o* _Username_k__BackingField;
    bool _IsLocal_k__BackingField;
    int32_t health;
    int32_t maxHealth;
    bool _Dead_k__BackingField;
    bool _IsGrappling_k__BackingField;
    struct UnityEngine_Vector3_o _GrapplePoint_k__BackingField;
    uint16_t _Kills_k__BackingField;
    uint16_t _Deaths_k__BackingField;
    int32_t _StayTime_k__BackingField;
    bool _DisplayTag_k__BackingField;
    struct Outline_o* outline;
    int32_t _outlineType;
    struct UnityEngine_Animator_o* animator;
    int32_t _Exp_k__BackingField;
    struct UnityEngine_Rigidbody_o* player;
    struct TMPro_TextMeshProUGUI_o* nameText;
    struct UnityEngine_Vector3_o desiredPos;
    struct UnityEngine_Quaternion_o desiredRot;
    struct System_Collections_Generic_List_MultiplayerWeapon__o* weapons;
    struct MultiplayerWeapon_o* currentWeapon;
    struct MultiplayerWeapon_array* weapon;
    struct MultiplayerWeapon_o* specialWeapon;
    struct LookedToObject_o* leftHandTarget;
    struct LookedToObject_o* rightHandTarget;
    struct System_Collections_Generic_List_GameObject__o* hatCosmetics;
    struct System_Collections_Generic_List_GameObject__o* faceCosmetics;
    struct System_Collections_Generic_List_GameObject__o* shoeLCosmetics;
    struct System_Collections_Generic_List_GameObject__o* shoeRCosmetics;
    struct System_Collections_Generic_List_GameObject__o* hairCosmetics;
    struct System_Collections_Generic_List_GameObject__o* clothesCosmetics;
    struct System_Collections_Generic_List_GameObject__o* pantCosmetics;
    struct UnityEngine_SkinnedMeshRenderer_o* daveHair;
    struct UnityEngine_SkinnedMeshRenderer_o* clothes;
    struct UnityEngine_SkinnedMeshRenderer_o* pant;
    struct System_Collections_Generic_List_Transform__o* eyes;
    bool isInfected;
    struct UnityEngine_SkinnedMeshRenderer_array* models;
    struct Manager_InventoryManager_CosmeticIndex_o* cosmeticIndex;
    int32_t team;
    struct System_Collections_Generic_List_Perk__o* perks;
    int32_t _WeaponLevel_k__BackingField;
    struct UnityEngine_MeshRenderer_array* eye;
    struct System_Collections_Generic_Queue_StringBuilder__o* recentChatMessage;
    uint64_t groupId;
    int32_t _WeaponIndex_k__BackingField;
    struct UnityEngine_Transform_o* _hatParticle;
    struct UnityEngine_Transform_o* _faceParticle;
    struct UnityEngine_Transform_o* _shoeLParticle;
    struct UnityEngine_Transform_o* _shoeRParticle;
    struct UnityEngine_Transform_o* _hairParticle;
    struct UnityEngine_Transform_o* _clotheParticle;
    struct UnityEngine_Transform_o* _pantParticle;
    struct UnityEngine_Transform_o* clawKnifeHandPos;
    struct UnityEngine_GameObject_o* clawKnife;
    struct UnityEngine_Animator_o* clawKnifeAnim;
    struct UnityEngine_Coroutine_o* _setTeamOutline;
    struct UnityEngine_Vector2_o input;
    struct UnityEngine_Transform_o* head;
    struct UnityEngine_Transform_o* aimTarget;
    bool _IsReady_k__BackingField;
    struct UnityEngine_GameObject_o* fire;
    bool bloodThirsty;
    struct UnityEngine_AudioSource_o* audioSource;
    struct UnityEngine_AudioSource_o* voice;
    struct UnityEngine_Light_o* Light;
    bool hitted;
    bool specting;
    struct System_Collections_Generic_List_FastIKFabric__o* iks;
    int32_t lastCoin;
    bool moved;
    uint16_t currentLifeKill;
    int32_t coins;
    struct Grappling_o* grappling;
    struct System_String_array* weaponNames;
    int32_t weaponIndex;
    struct System_UInt16_array* weaponIndexs;
    bool setNameCorrectly;
    struct UnityEngine_Animator_o* mouth;
    bool _Grounded_k__BackingField;
    bool _Crouch_k__BackingField;
    struct UnityEngine_CapsuleCollider_o* col;
    struct UnityEngine_Transform_o* nameTrans;
    float distance;
    struct System_Collections_Generic_List_Transform__o* bones;
    struct UnityEngine_CanvasGroup_o* group;
    float desiredAlpha;
    struct UnityEngine_GameObject_o* nameCanvas;
};
struct Multiplayer_Client_ClientPlayer_VTable {
    VirtualInvokeData _0_Equals;
    VirtualInvokeData _1_Finalize;
    VirtualInvokeData _2_GetHashCode;
    VirtualInvokeData _3_ToString;
};
struct Multiplayer_Client_ClientPlayer_c {
    Il2CppClass_1 _1;
    struct Multiplayer_Client_ClientPlayer_StaticFields* static_fields;
    Il2CppRGCTXData* rgctx_data;
    Il2CppClass_2 _2;
    Multiplayer_Client_ClientPlayer_VTable vtable;
};
struct Multiplayer_Client_ClientPlayer_o {
    Multiplayer_Client_ClientPlayer_c* klass;
    void* monitor;
    Multiplayer_Client_ClientPlayer_Fields fields;
};
struct Multiplayer_Client_ClientPlayer_StaticFields {
    struct System_Collections_Generic_Dictionary_ushort__ClientPlayer__o* list;
    int32_t X;
    int32_t Y;
    struct System_Collections_Generic_List_ulong__o* existGroup;
    struct GameUIManager_o* gameUi;
    struct WeaponManager_o* weaponManager;
    int32_t Jump;
    int32_t Crouch1;
    int32_t Speaking;
    int32_t Infecting;
    int32_t Attack;
};

struct PlayerMovement_Fields : UnityEngine_MonoBehaviour_Fields {
    struct UnityEngine_Transform_o* playerCam;
    struct UnityEngine_Transform_o* orientation;
    struct UnityEngine_GameObject_o* playerSmokeFx;
    struct UnityEngine_Rigidbody_o* rb;
    float xRotation;
    float sensitivity;
    float sensMultiplier;
    float moveSpeed;
    float maxSpeed;
    bool grounded;
    struct UnityEngine_LayerMask_o whatIsGround;
    float counterMovement;
    float threshold;
    float maxSlopeAngle;
    struct UnityEngine_Vector3_o crouchScale;
    struct UnityEngine_Vector3_o playerScale;
    float slideForce;
    float slideCounterMovement;
    bool readyToJump;
    float jumpCooldown;
    float jumpForce;
    float x;
    float y;
    bool jumping;
    bool crouching;
    bool inWater;
    struct UnityEngine_Vector3_o normalVector;
    struct UnityEngine_Vector3_o wallNormalVector;
    float fallSpeed;
    bool canCrouch;
    float dashForce;
    float dashDuration;
    struct Grappling_o* grappling;
    struct UnityEngine_Camera_o* cam;
    int32_t jumpLeft;
    bool canDash;
    bool speed_a;
    bool speed_B;
    float stayTimer;
    float minDisHead;
    struct UnityEngine_RaycastHit_o slopeHit;
    float distance;
    struct UnityEngine_Transform_o* _transform;
    bool moved;
    struct Replay_ReplayPlayer_o* _replayPlayer;
    bool needToStand;
    float maxDisHead;
    float moveSpeedFactor;
    float jumpFactor;
    float perkMoveSpeedFactor;
    float maxAirSpeed;
    float actualWallRotation;
    float wallRotationVel;
    float _desiredX_k__BackingField;
    bool aimAssist;
    struct UnityEngine_LayerMask_o whatIsAssist;
    float wallRunRotation;
    bool cancelling;
    struct UnityEngine_Vector3_o lastMoveSpeed;
    struct UnityEngine_Vector3_o lastVel;
    float playerHeight;
    struct UnityEngine_Vector3_o groundPoint;
    bool surfing;
    bool cancellingSurf;
    int32_t maxJumpCount;
    bool cancellingGrounded;
    bool cancellingWall;
    bool wallRunning;
    bool onWall;
    float wallRunGravity;
    bool readyToWallrun;
    struct Multiplayer_Client_ClientPlayer_o* _player;
};
struct PlayerMovement_VTable {
    VirtualInvokeData _0_Equals;
    VirtualInvokeData _1_Finalize;
    VirtualInvokeData _2_GetHashCode;
    VirtualInvokeData _3_ToString;
};
struct PlayerMovement_c {
    Il2CppClass_1 _1;
    struct PlayerMovement_StaticFields* static_fields;
    Il2CppRGCTXData* rgctx_data;
    Il2CppClass_2 _2;
    PlayerMovement_VTable vtable;
};
struct PlayerMovement_o {
    PlayerMovement_c* klass;
    void* monitor;
    PlayerMovement_Fields fields;
};
struct PlayerMovement_StaticFields {
    struct PlayerMovement_o* Instance;
};

struct KickVote_Fields : UnityEngine_MonoBehaviour_Fields {
    struct TMPro_TextMeshProUGUI_o* agreeCountText;
    struct TMPro_TextMeshProUGUI_o* disAgreeCountText;
    struct UnityEngine_Localization_Components_LocalizeStringEvent_o* kick;
    struct UnityEngine_Localization_Components_LocalizeStringEvent_o* vote;
    struct UnityEngine_Vector3_o desiredPos;
    struct UnityEngine_Vector3_o showPos;
    struct UnityEngine_Vector3_o defaultPos;
    struct UnityEngine_RectTransform_o* kickMessage;
    struct System_String_o* kickPlayerName;
    struct System_String_o* votePlayerName;
    struct UnityEngine_UI_Button_o* agreeBtn;
    struct UnityEngine_UI_Button_o* disAgreeBtn;
};
struct KickVote_VTable {
    VirtualInvokeData _0_Equals;
    VirtualInvokeData _1_Finalize;
    VirtualInvokeData _2_GetHashCode;
    VirtualInvokeData _3_ToString;
};
struct KickVote_c {
    Il2CppClass_1 _1;
    struct KickVote_StaticFields* static_fields;
    Il2CppRGCTXData* rgctx_data;
    Il2CppClass_2 _2;
    KickVote_VTable vtable;
};
struct KickVote_o {
    KickVote_c* klass;
    void* monitor;
    KickVote_Fields fields;
};
struct KickVote_StaticFields {
    struct KickVote_o* Instance;
    struct VoteKicking_o* VoteKicking;
};

struct __declspec(align(8)) VoteKicking_Fields {
    uint16_t PlayerId;
    uint16_t FromClient;
    uint16_t agreeCount;
    uint16_t disAgreeCount;
    struct System_Collections_Generic_Dictionary_ushort__bool__o* Players;
};
struct VoteKicking_VTable {
    VirtualInvokeData _0_Equals;
    VirtualInvokeData _1_Finalize;
    VirtualInvokeData _2_GetHashCode;
    VirtualInvokeData _3_ToString;
};
struct VoteKicking_c {
    Il2CppClass_1 _1;
    void* static_fields;
    Il2CppRGCTXData* rgctx_data;
    Il2CppClass_2 _2;
    VoteKicking_VTable vtable;
};
struct VoteKicking_o {
    VoteKicking_c* klass;
    void* monitor;
    VoteKicking_Fields fields;
};

namespace il2cpp {
    inline std::string to_string(System_String_o* str)
    {

        if (!str)
            return "NULL";
        else
        {
            auto wstr = std::wstring((wchar_t*)(&str->fields._firstChar));
            return std::string(wstr.begin(), wstr.end());
        }

    }
}

typedef void(__fastcall* tCreateExplosiveBullet)(Firearms_o* __this, UnityEngine_Vector3_o point, MethodInfo* method);
typedef void(__fastcall* tAddChat)(Chat_o* __this, System_String_o* content, uint64_t steamId, uint16_t fromClient, const MethodInfo* method);