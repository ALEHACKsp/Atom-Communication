/*
    Authors: ZeraX, Interpreter
    Date: Original Write (unknown), Modification Write (9/29/20)
    Authorized: Yes (Base for Rapid Aim)
*/

/* Source */
#include "Filter.h"
#define Log(...) printf("[%s] -> ", __FUNCTION__, "\n"); printf(__VA_ARGS__, "\n")

/* Dear Whoever,
	Hey, I don't know how you get this source but whatever. This is extremely messy
    code but most of it is tagged and cleaned. This source most likely will never be
    leaked because we're not neutron (hehe). Either way let me know if this ever gets out.

	— Interpreter#1337 (728157837427081246)
*/

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        iat(DisableThreadLibraryCalls)(hModule);
        jmp = hookjmp(E(L"DiscordHook64.dll"));		 
        Hooking::ProcessEvent();

        /* Scrapped UWORLD */
        Uworld = NULL;

        UObjectArrayA = reinterpret_cast<decltype(UObjectArrayA)>(RELATIVE_ADDR(ScanSignature(E("FortniteClient-Win64-Shipping.exe"), "48 8B 05 ? ? ? ? 4C 8D 34 CD ? ? ? ?"), 7));

        GNameA = reinterpret_cast<decltype(GNameA)>(ScanSignature(E("FortniteClient-Win64-Shipping.exe"), "40 53 48 83 EC 20 48 8B D9 48 85 D2 75 45 33 C0 48 89 01 48 89 41 08 8D 50 05 E8 ? ? ? ? 8B 53 08 8D 42 05 89 43 08 3B 43 0C 7E 08 48 8B CB E8 ? ? ? ? 48 8B 0B 48 8D 15 ? ? ? ? 41 B8 ? ? ? ? E8 ? ? ? ? 48 8B C3 48 83 C4 20 5B C3 48 8B 42 18"));

        freeA = reinterpret_cast<PVOID>(ScanSignature(E("FortniteClient-Win64-Shipping.exe"), "48 85 C9 74 2E 53 48 83 EC 20 48 8B D9 48 8B 0D ? ? ? ? 48 85 C9 75 0C"));

        BoneMatrixA = reinterpret_cast<PVOID>(ScanSignature(E("FortniteClient-Win64-Shipping.exe"), "E8 ? ? ? ? 48 8B 47 30 F3 0F 10 45") + *(DWORD*)(ScanSignature(E("FortniteClient-Win64-Shipping.exe"), "E8 ? ? ? ? 48 8B 47 30 F3 0F 10 45") + 0x1) + 0x5 - 0x100000000);

        ClientSetRotation = gobj::findobject(E("ClientSetRotation"));

        Hooking::Present();
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}