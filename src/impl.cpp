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

Impl::Bitmap::Bitmap(string path, int width, int height, vector<int> colours)
{
    this->_data = &BasicBitmap(width, height, BasicBitmap::A8B8G8R8);
}

Impl::Bitmap::~Bitmap()
{
    delete this->_data;
}
