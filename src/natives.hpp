#ifndef BITMAPPER_NATIVES_H
#define BITMAPPER_NATIVES_H

#include <string>

#include <amx/amx2.h>

#include "common.hpp"
#include "impl.hpp"

namespace Natives {
cell OpenBitmap(AMX* amx, cell* params);
cell OpenBitmapCache(AMX* amx, cell* params);
cell CloseBitmap(AMX* amx, cell* params);
cell GetRGB(AMX* amx, cell* params);
}

#endif
