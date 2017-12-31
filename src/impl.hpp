#ifndef bitmapper_IMPL_H
#define bitmapper_IMPL_H

#include <string>

using std::string;

namespace Impl {
int OpenBitmap(string path);
int CloseBitmap(int id);
};

#endif
