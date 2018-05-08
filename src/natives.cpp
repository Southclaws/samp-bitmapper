#include "natives.hpp"

cell Natives::OpenBitmap(AMX* amx, cell* params)
{
    const char* path = nullptr;
    amx_StrParam(amx, params[1], path);

    int id = Impl::OpenBitmap(path);

    cell* output;
    amx_GetAddr(amx, params[2], &output);
    *output = id;

    return 0;
}

cell Natives::OpenBitmapCache(AMX* amx, cell* params)
{
    std::string path = amx_GetCppString(amx, params[1]);

    std::set<IUINT32> colours;
    cell* addr;
    amx_GetAddr(amx, params[3], &addr);
    for (int i = 0; i < params[4]; i++) {
        colours.insert(addr[i]);
    }

    int id = Impl::OpenBitmapCached(path, colours);

    cell* output;
    amx_GetAddr(amx, params[2], &output);
    *output = id;

    return 0;
}

cell Natives::CloseBitmap(AMX* amx, cell* params)
{
    int id = params[1];
    return Impl::CloseBitmap(id);
}

cell Natives::GetRGB(AMX* amx, cell* params)
{
    int id = params[1];
    int x = params[2];
    int y = params[3];

    int *r, *g, *b = 0;
    amx_GetAddr(amx, params[4], &r);
    amx_GetAddr(amx, params[5], &g);
    amx_GetAddr(amx, params[6], &b);

    cell ret = Impl::GetRGB(id, x, y, *r, *g, *b);

    return ret;
}

cell Natives::GetRandomCachedRGB(AMX* amx, cell* params)
{
    int id = params[1];
    int colour = params[2];
    int* x = nullptr;
    int* y = nullptr;
    amx_GetAddr(amx, params[3], &x);
    amx_GetAddr(amx, params[4], &y);

    return Impl::GetRandomCachedRGB(id, colour, *x, *y);
}
