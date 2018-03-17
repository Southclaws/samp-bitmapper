#include <string>
using std::string;

#include <amx/amx2.h>

#include "impl.hpp"
#include "natives.hpp"


cell AMX_NATIVE_CALL Native::OpenBitmap(AMX *amx, cell *params) {
	const char *path = nullptr;
	amx_StrParam(amx, params[1], path);

	int id = Bitmap::OpenBitmap(path);

	cell* output;
	amx_GetAddr(amx, params[2], &output);
	*output = id;

	return 0;
}

cell AMX_NATIVE_CALL Native::CloseBitmap(AMX *amx, cell *params) {
	int id = params[1];
	return Bitmap::CloseBitmap(id);
}

cell AMX_NATIVE_CALL Native::GetRGB(AMX *amx, cell *params) {
	int id = params[1];
	int x = params[2];
	int y = params[3];

	logprintf("%d", id);

	int r, g, b = 0;

	cell ret = Bitmap::GetRGB(id, x, y, r, g, b);
/*
	cell* rr;
	amx_GetAddr(amx, params[4], &rr);
	*rr = r;
	cell* gg;
	amx_GetAddr(amx, params[5], &gg);
	*rr = r;
	cell* bb;
	amx_GetAddr(amx, params[6], &bb);
	*bb = b;*/

	return ret;
}
