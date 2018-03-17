#ifndef bitmapper_IMPL_H
#define bitmapper_IMPL_H

#include <string>
#include <vector>
#include <map>
using std::string;
using std::vector;
using std::map;

#include "BasicBitmap.h"


namespace Bitmap {
	cell OpenBitmap(string path);
	cell CloseBitmap(int handle);
	cell GetRGB(int handle, int x, int y, int &r, int &g, int &b);
};

#endif
