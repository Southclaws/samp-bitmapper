#include "impl.hpp"

// BitmapPoolCounter is a continually incrementing unique identifier it
// increments for each bitmap opened and provides a simple way to uniquely
// identify bitmaps in Pawn space.
int Impl::BitmapPoolCounter;

// BitmapPool maps Pawn space ID numbers to actual BasicBitmap objects.
std::map<int, Impl::Bitmap> Impl::BitmapPool;

std::random_device Impl::randomDevice;
std::mt19937 Impl::randomGenerator(randomDevice());

int Impl::OpenBitmap(std::string path)
{
    BasicBitmap* bmp = BasicBitmap::LoadBmp(path.c_str());
    if (bmp == nullptr) {
        return -1;
    }

    BitmapPool[BitmapPoolCounter] = Bitmap{ bmp, false };

    return BitmapPoolCounter++;
}

int Impl::OpenBitmapCached(std::string path, std::set<IUINT32> colours)
{
    BasicBitmap* bmp = BasicBitmap::LoadBmp(path.c_str());
    if (bmp == nullptr) {
        return -1;
    }

    Bitmap bitmap;
    bitmap.bmp = bmp;
    bitmap.isCached = true;

    for (int x = 0; x < bmp->Width(); ++x) {
        for (int y = 0; y < bmp->Height(); ++y) {
            IUINT32 pixel = bmp->GetPixel(x, y);
            if (colours.find(pixel) != colours.end()) {
                bitmap.colourPositions[pixel].push_back(std::make_pair(x, y));
            }
        }
    }

    BitmapPool[BitmapPoolCounter] = bitmap;

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

int Impl::GetRandomCachedRGB(int handle, IUINT32 colour, int& x, int& y)
{
	auto search = BitmapPool.find(handle);
	if (search == BitmapPool.end()) {
		return 1;
	}

	auto coloursTable = search->second.colourPositions.find(colour);
	if (coloursTable == search->second.colourPositions.end()) {
		return 2;
	}

	std::uniform_int_distribution<> distance(0, std::distance(coloursTable->second.begin(), coloursTable->second.end()) - 1);
	auto pos = coloursTable->second[distance(randomGenerator)];
	x = pos.first;
	y = pos.second;

	return 0;
}
