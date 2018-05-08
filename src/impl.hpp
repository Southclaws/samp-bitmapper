#ifndef BITMAPPER_IMPL_H
#define BITMAPPER_IMPL_H

#include <iterator>
#include <map>
#include <random>
#include <set>
#include <string>
#include <utility>
#include <vector>

#include "BasicBitmap.h"
#include "common.hpp"

namespace Impl {
struct Bitmap {
    BasicBitmap* bmp;
    bool isCached;
    std::vector<IUINT32> colours;
    std::map<IUINT32, std::vector<std::pair<int, int>>> colourPositions;
};
int OpenBitmap(std::string path);
int OpenBitmapCached(std::string path, std::set<IUINT32> colours);
int CloseBitmap(int handle);
int GetRGB(int handle, int x, int y, int& r, int& g, int& b);
int GetRandomCachedRGB(int handle, IUINT32 colour, int& x, int& y);

extern int BitmapPoolCounter;
extern std::map<int, Bitmap> BitmapPool;
extern std::random_device randomDevice;
extern std::mt19937 randomGenerator;
};

#endif
