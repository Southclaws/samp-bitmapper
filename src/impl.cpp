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

Impl::Bitmap::Bitmap(string path, int width, int height) {
    this->_data = &BasicBitmap(width, height, BasicBitmap::A8B8G8R8);
}

Impl::Bitmap::~Bitmap() {
    delete _data;
}

int Impl::Bitmap::GetRGB(int x, int y, int &r, int &g, int &b) {
	IUINT32 pixel = _data->GetColor(x, y);

	r = (pixel >> 16) & 0xFF;
	g = (pixel >> 8) & 0xFF;
	b = pixel & 0xFF;

	return 0;
}
