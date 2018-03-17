#ifndef bitmapper_NATIVES_H
#define bitmapper_NATIVES_H

#include <amx/amx.h>

namespace Native {
cell OpenBitmap(AMX* amx, cell* params);
cell CloseBitmap(AMX* amx, cell* params);
cell GetRGB(AMX* amx, cell* params);
};

#endif
 