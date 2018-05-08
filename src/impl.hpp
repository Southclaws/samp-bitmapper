#ifndef BITMAPPER_IMPL_H
#define BITMAPPER_IMPL_H

#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
using std::map;
using std::pair;
using std::set;
using std::string;
using std::vector;

#include "BasicBitmap.h"

namespace Impl {
struct Bitmap {
    BasicBitmap* bmp;
    vector<int32_t> colours;
    map<int32_t, vector<pair<int, int>>> colourPositions;
};
int OpenBitmap(string path);
int OpenBitmapCached(string path, set<int> colours);
int CloseBitmap(int handle);
int GetRGB(int handle, int x, int y, int& r, int& g, int& b);

extern int BitmapPoolCounter;
extern map<int, Bitmap> BitmapPool;
};

#endif
