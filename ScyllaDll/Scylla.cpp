#include "Scylla.h"

#include "NativeWinApi.h"
#include "SystemInformation.h"
#include "ProcessAccessHelp.h"

#include <psapi.h>
#pragma comment(lib, "psapi.lib")   //GetModuleFileNameExW

ConfigurationHolder Scylla::config(L"Scylla.ini");

ProcessLister Scylla::processLister;

const WCHAR Scylla::DEBUG_LOG_FILENAME[] = L"Scylla_debug.log";

FileLog Scylla::debugLog(DEBUG_LOG_FILENAME);
ListboxLog Scylla::windowLog;

void Scylla::initAsDll()
{
	ProcessAccessHelp::ownModuleList.clear();

	NativeWinApi::initialize();
	SystemInformation::getSystemInformation();
	ProcessAccessHelp::getProcessModules(GetCurrentProcess(), ProcessAccessHelp::ownModuleList);
}