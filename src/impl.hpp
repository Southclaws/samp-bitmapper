#ifndef bitmapper_IMPL_H
#define bitmapper_IMPL_H

#include <string>
#include <vector>
using std::string;
using std::vector;

#include "BasicBitmap.h"

namespace Impl {

// Bitmap represents a single bitmap image loaded into memory
class Bitmap {
public:
    Bitmap(string path, int width, int height);
    ~Bitmap();

	int GetRGB(int x, int y, int &r, int &g, int &b);

private:
    BasicBitmap* _data = nullptr;
};
};

#endif
