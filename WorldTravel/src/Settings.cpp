#include "Settings.h"
#include <stdio.h>

bool Settings::EnableLogging = true;
bool Settings::FastTravel = true;
int Settings::TeleportKey = VK_F11;
bool Settings::EnableCayoPerico = true;
bool Settings::EnableNorthYankton = true;
bool Settings::EnableLibertyCityLODLights = true;
bool Settings::IHaveAPersistenceMod = false;
bool Settings::RememberMap = false;
int Settings::LastLocation = 0;

void Settings::Load()
{
    char iniFilePath[MAX_PATH];
    GetFullPathName("WorldTravel.ini", MAX_PATH, iniFilePath, nullptr);

    EnableLogging = LoadBoolSetting("WorldTravel", "EnableLogging", true, iniFilePath);
    FastTravel = LoadBoolSetting("WorldTravel", "FastTravel", true, iniFilePath);
    TeleportKey = LoadIntSetting("WorldTravel", "TeleportKey", VK_F11, iniFilePath);
    EnableCayoPerico = LoadBoolSetting("WorldTravel", "EnableCayoPerico", true, iniFilePath);
    EnableNorthYankton = LoadBoolSetting("WorldTravel", "EnableNorthYankton", true, iniFilePath);
	EnableLibertyCityLODLights = LoadBoolSetting("WorldTravel", "EnableLibertyCityLODLights", true, iniFilePath);
    IHaveAPersistenceMod = LoadBoolSetting("WorldTravel", "IHaveAPersistenceMod", false, iniFilePath);//useful for skipping things like location and weather setting on load
    RememberMap = LoadBoolSetting("WorldTravel", "RememberMap", false, iniFilePath);
    LastLocation = LoadIntSetting("WorldTravel", "LastLocation", 0, iniFilePath);
}

// Settings helper functions
bool Settings::LoadBoolSetting(const char* section, const char* key, bool defaultValue, const char* iniFilePath)
{
    UINT value = GetPrivateProfileInt(section, key, defaultValue ? 1 : 0, iniFilePath);
    return value != 0;
}

int Settings::LoadIntSetting(const char* section, const char* key, int defaultValue, const char* iniFilePath)
{
    return GetPrivateProfileInt(section, key, defaultValue, iniFilePath);
}

void Settings::SaveSetting(const char* section, const char* key, const char* value, const char* iniFilePath)
{
    WritePrivateProfileString(section, key, value, iniFilePath);
}