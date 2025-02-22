#pragma once
#include <Windows.h>

class Settings
{
public:
    static bool EnableLogging;
    static bool FastTravel;
    static int TeleportKey;
    static bool EnableCayoPerico;
    static bool EnableNorthYankton;
	static bool EnableLibertyCityLODLights;
	static bool IHaveAPersistenceMod;
    static bool RememberMap;
    static int LastLocation;

    static void Load();
    static void SaveSetting(const char* section, const char* key, const char* value, const char* iniFilePath);

private:
    static bool LoadBoolSetting(const char* section, const char* key, bool defaultValue, const char* iniFilePath);
    static int LoadIntSetting(const char* section, const char* key, int defaultValue, const char* iniFilePath);
};