// bitmapper, based on the old FileManager plugin by JaTochNietDan

#include <amx/amx.h>
#include <plugincommon.h>

#include "natives.hpp"
int BasicBitmap_SSE2_AVX_Enable();

typedef void (*logprintf_t)(const char* format, ...);

logprintf_t logprintf;

extern void* pAMXFunctions;

PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports()
{
    return SUPPORTS_VERSION | SUPPORTS_AMX_NATIVES;
}

PLUGIN_EXPORT bool PLUGIN_CALL Load(void** ppData)
{
    int sse = BasicBitmap_SSE2_AVX_Enable();

    pAMXFunctions = ppData[PLUGIN_DATA_AMX_EXPORTS];
    logprintf = (logprintf_t)ppData[PLUGIN_DATA_LOGPRINTF];

    logprintf("Bitmapper plugin by Southclaws loaded");
    logprintf("- Bitmapper SSE Status: %d", sse);

    return true;
}

PLUGIN_EXPORT void PLUGIN_CALL Unload() {}

AMX_NATIVE_INFO NATIVES[] = {
    { "OpenBitmap", Native::OpenBitmap },
    { "CloseBitmap", Native::CloseBitmap },
    { "GetRGB", Native::GetRGB },
    { 0, 0 }
};

PLUGIN_EXPORT int PLUGIN_CALL AmxLoad(AMX* amx)
{
    return amx_Register(amx, NATIVES, -1);
}

PLUGIN_EXPORT int PLUGIN_CALL AmxUnload(AMX* amx) { return AMX_ERR_NONE; }
