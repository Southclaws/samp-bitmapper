#ifndef bitmapper_IMPL_H
#define bitmapper_IMPL_H

#include <map>
#include <string>
#include <vector>
using std::map;
using std::string;
using std::vector;

#include "BasicBitmap.h"

namespace Bitmap {
cell OpenBitmap(string path);
cell CloseBitmap(int handle);
cell GetRGB(int handle, int x, int y, int& r, int& g, int& b);
}; // namespace Bitmap

#endif
