#if defined _bitmapper_included
	#endinput
#endif
#define _bitmapper_included


// OpenBitmap opens the given file as a bitmap image and stores thefile handle
// in `handle`. Returns 0 on success or an error code.
native OpenBitmap(const filename[], &Bitmap:handle);

// OpenBitmapCache opens the given file and caches all pixels that match the
// colours listed in `colours`. Returns 0 on success or an error code.
native OpenBitmapCache(const filename[], &Bitmap:handle, const colours[], len = sizeof colours);

// CloseBitmap closes the specified file handle. Returns 0 on success, 1 if the
// handle is invalid.
native CloseBitmap(Bitmap:handle);

// GetRGB looks up the red, green and blue values stored in the specified X and
// Y coordinates and stores them in the result parameters `r`, `b` and `g`.
native GetRGB(Bitmap:handle, x, y, &r, &g, &b);
