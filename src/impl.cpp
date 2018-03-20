// implementation

#include <cstring>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sys/stat.h>
#include <sys/types.h>

#include <amx/amx.h>

#include "BasicBitmap.h"
#include "impl.hpp"

// CurrentID is a continually incrementing unique identifier it increments
// for each bitmap opened and provides a simple way to uniquely identify
// bitmaps in Pawn space.
int CurrentID;

// BitmapPool maps Pawn space ID numbers to actual BasicBitmap objects.
map<int, BasicBitmap*> BitmapPool;

cell Bitmap::OpenBitmap(string path)
{
    BasicBitmap* bmp = BasicBitmap::LoadBmp(path.c_str());
    if (bmp == nullptr) {
        return -1;
    }

    BitmapPool[CurrentID] = bmp;

    return CurrentID++;
}

cell Bitmap::CloseBitmap(int id)
{
    auto search = BitmapPool.find(id);
    if (search == BitmapPool.end()) {
        return 1;
    }
    delete search->second;

    return 0;
}

cell Bitmap::GetRGB(int handle, int x, int y, int& r, int& g, int& b)
{
    auto search = BitmapPool.find(handle);
    if (search == BitmapPool.end()) {
        return 1;
    }

    BasicBitmap* bmp = search->second;

    if (bmp == nullptr) {
        return 2;
    }

    IUINT32 pixel = bmp->GetColor(x, y);
    r = (pixel >> 16) & 0xFF;
    g = (pixel >> 8) & 0xFF;
    b = pixel & 0xFF;

    return 0;
}
