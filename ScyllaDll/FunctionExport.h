#pragma once

#include <windows.h>

#if defined(DLL_SDK_EXPORT)
#define DLL_PLUGIN_API __declspec(dllexport)
#else
#define DLL_PLUGIN_API __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C" {
#endif

const int SCY_ERROR_SUCCESS = 0;
const int SCY_ERROR_PROCOPEN = -1;
const int SCY_ERROR_IATWRITE = -2;
const int SCY_ERROR_IATSEARCH = -3;
const int SCY_ERROR_IATNOTFOUND = -4;
const int SCY_ERROR_PIDNOTFOUND = -5;


//int InitializeGui(HINSTANCE hInstance, LPARAM param);


//function to export in DLL

BOOL DumpProcessW(const WCHAR * fileToDump, DWORD_PTR imagebase, DWORD_PTR entrypoint, const WCHAR * fileResult);

DLL_PLUGIN_API BOOL WINAPI ScyllaDumpCurrentProcessW(const WCHAR * fileToDump, DWORD_PTR imagebase, DWORD_PTR entrypoint, const WCHAR * fileResult);
DLL_PLUGIN_API BOOL WINAPI ScyllaDumpCurrentProcessA(const char * fileToDump, DWORD_PTR imagebase, DWORD_PTR entrypoint, const char * fileResult);

DLL_PLUGIN_API BOOL WINAPI ScyllaDumpProcessW(DWORD_PTR pid, const WCHAR * fileToDump, DWORD_PTR imagebase, DWORD_PTR entrypoint, const WCHAR * fileResult);
DLL_PLUGIN_API BOOL WINAPI ScyllaDumpProcessA(DWORD_PTR pid, const char * fileToDump, DWORD_PTR imagebase, DWORD_PTR entrypoint, const char * fileResult);

DLL_PLUGIN_API BOOL WINAPI ScyllaRebuildFileW(const WCHAR * fileToRebuild, BOOL removeDosStub, BOOL updatePeHeaderChecksum, BOOL createBackup);
DLL_PLUGIN_API BOOL WINAPI ScyllaRebuildFileA(const char * fileToRebuild, BOOL removeDosStub, BOOL updatePeHeaderChecksum, BOOL createBackup);

DLL_PLUGIN_API const WCHAR * WINAPI ScyllaVersionInformationW();
DLL_PLUGIN_API const char * WINAPI ScyllaVersionInformationA();
DLL_PLUGIN_API DWORD WINAPI ScyllaVersionInformationDword();

//int WINAPI ScyllaStartGui(DWORD dwProcessId, HINSTANCE mod);

DLL_PLUGIN_API int WINAPI ScyllaIatSearch(DWORD dwProcessId, DWORD_PTR * iatStart, DWORD * iatSize, DWORD_PTR searchStart, BOOL advancedSearch);

DLL_PLUGIN_API int WINAPI ScyllaIatFixAutoW(DWORD_PTR iatAddr, DWORD iatSize, DWORD dwProcessId, const WCHAR * dumpFile, const WCHAR * iatFixFile);


#ifdef __cplusplus
}
#endif

/*
C/C++ Prototyps

typedef const WCHAR * (WINAPI * def_ScyllaVersionInformationW)();
typedef const char * (WINAPI * def_ScyllaVersionInformationA)();
typedef DWORD (WINAPI * def_ScyllaVersionInformationDword)();
typedef int (WINAPI * def_ScyllaIatSearch)(DWORD dwProcessId, DWORD_PTR * iatStart, DWORD * iatSize, DWORD_PTR searchStart, BOOL advancedSearch);
typedef int (WINAPI * def_ScyllaStartGui)(DWORD dwProcessId, HINSTANCE mod);

*/
