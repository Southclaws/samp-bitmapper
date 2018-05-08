#include <amx/amx.h>
#include <plugincommon.h>

#include "common.hpp"
#include "natives.hpp"

logprintf_t logprintf;
int BasicBitmap_SSE2_AVX_Enable();

extern "C" AMX_NATIVE_INFO nativeList[] = {
    { "OpenBitmap", Natives::OpenBitmap },
    { "OpenBitmapCache", Natives::OpenBitmapCache },
    { "CloseBitmap", Natives::CloseBitmap },
    { "GetRGB", Natives::GetRGB },
    { 0, 0 }
};

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

PLUGIN_EXPORT int PLUGIN_CALL AmxLoad(AMX* amx)
{
    return amx_Register(amx, nativeList, -1);
}

PLUGIN_EXPORT int PLUGIN_CALL Unload()
{
    return 1;
}

PLUGIN_EXPORT int PLUGIN_CALL AmxUnload()
{
    return 1;
}
