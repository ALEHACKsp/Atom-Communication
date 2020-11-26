#include "imports.h"
#include "_spoofer_stub.h"
#include "detours.h"

//real winapi function
HANDLE(WINAPI* Real_CreateFileW) (
    LPCWSTR lpFileName,
    DWORD dwDesiredAccess,
    DWORD dwShareMode,
    LPSECURITY_ATTRIBUTES lpSecurityAttributes,
    DWORD dwCreationDisposition,
    DWORD dwFlagsAndAttributes,
    HANDLE hTemplateFile) = CreateFileW;

//real winapi function
BOOL(WINAPI* Real_CreateDirectoryW) (
    LPCWSTR lpPathName,
    LPSECURITY_ATTRIBUTES lpSecurityAttributes) = CreateDirectoryW;


//our own hooked function
HANDLE WINAPI _CreateFileW(LPCWSTR lpFileName,
    DWORD dwDesiredAccess,
    DWORD dwShareMode,
    LPSECURITY_ATTRIBUTES lpSecurityAttributes,
    DWORD dwCreationDisposition,
    DWORD dwFlagsAndAttributes,
    HANDLE hTemplateFile)
{
    //if file name contains shared, create spoofed file.
    if (wcsstr(lpFileName, E(L"Shared")))
        return Real_CreateFileW(E(L"C:\\Windows\\a"), dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile);

    //ignore pak, sig files and anything to fortnite and pipes
    if (wcsstr(lpFileName, E(L".pak")) || wcsstr(lpFileName, E(L".sig")) || wcsstr(lpFileName, E(L".ini")) || wcsstr(lpFileName, E(L"\\.\\")) || wcsstr(lpFileName, E(L"Binaries")))
        return Real_CreateFileW(lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile);
    else
        return Real_CreateFileW(E(L"C:\\Windows\\a"), dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile);
}

//our own hooked function
BOOL WINAPI _CreateDirectoryW(LPCWSTR lpPathName,
    LPSECURITY_ATTRIBUTES lpSecurityAttributes)
{
    //ignore fortnite folder creation
    if (wcsstr(lpPathName, E(L"Fortnite")))
        return Real_CreateDirectoryW(lpPathName, lpSecurityAttributes);
    else
        return Real_CreateDirectoryW(E(L"C:\\Windows\\a"), lpSecurityAttributes);
}