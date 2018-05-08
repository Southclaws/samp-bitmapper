#include "impl.hpp"

// BitmapPoolCounter is a continually incrementing unique identifier it
// increments for each bitmap opened and provides a simple way to uniquely
// identify bitmaps in Pawn space.
int Impl::BitmapPoolCounter;

// BitmapPool maps Pawn space ID numbers to actual BasicBitmap objects.
map<int, Impl::Bitmap> Impl::BitmapPool;

int Impl::OpenBitmap(string path)
{
    BasicBitmap* bmp = BasicBitmap::LoadBmp(path.c_str());
    if (bmp == nullptr) {
        return -1;
    }

    BitmapPool[BitmapPoolCounter] = Bitmap{ bmp };

    return BitmapPoolCounter++;
}

int Impl::OpenBitmapCached(string path, set<int> colours)
{
    BasicBitmap* bmp = BasicBitmap::LoadBmp(path.c_str());
    if (bmp == nullptr) {
        return -1;
    }

    Bitmap bitmapper;
    bitmapper.bmp = bmp;

    for (int x = 0; x < bmp->Width(); ++x) {
        for (int y = 0; y < bmp->Height(); ++y) {
            IUINT32 pixel = bmp->GetPixel(x, y);
            if (colours.find(pixel) != colours.end()) {
                bitmapper.colourPositions[pixel].push_back(pair<int, int>(x, y));
            }
        }
    }

    BitmapPool[BitmapPoolCounter] = bitmapper;

    return BitmapPoolCounter++;
}

int Impl::CloseBitmap(int id)
{
    auto search = BitmapPool.find(id);
    if (search == BitmapPool.end()) {
        return 1;
    }
    delete search->second.bmp;
	BitmapPool.erase(id);

    return 0;
}

int Impl::GetRGB(int handle, int x, int y, int& r, int& g, int& b)
{
    auto search = BitmapPool.find(handle);
    if (search == BitmapPool.end()) {
        return 1;
    }

    BasicBitmap* bmp = search->second.bmp;

    if (bmp == nullptr) {
        return 2;
    }

    IUINT32 pixel = bmp->GetColor(x, y);
    r = (pixel >> 16) & 0xFF;
    g = (pixel >> 8) & 0xFF;
    b = pixel & 0xFF;

    return 0;
}
