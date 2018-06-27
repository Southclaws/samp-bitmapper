[COLOR="#FF4700"][SIZE="7"][B]samp-bitmapper[/B][/SIZE][/COLOR]

For generating in-game coordinates from a bitmap.

[COLOR="RoyalBlue"][SIZE="6"][B]Installation[/B][/SIZE][/COLOR]

Simply install to your project:

[CODE]
sampctl package install Southclaws/samp-bitmapper
[/CODE]

Or, if you prefer [URL="https://github.com/Southclaws/samp-bitmapper"]GitHub[/URL].

Include in your code and begin using the library:

[CODE]
[COLOR="Blue"]#include <bitmapper>[/COLOR]
[/CODE]

[COLOR="RoyalBlue"][SIZE="6"][B]Usage[/B][/SIZE][/COLOR]

[COLOR="DeepSkyBlue"][SIZE="5"][B][FONT="courier new"]OpenBitmap(const filename[], &Bitmap:handle);[/FONT][/B][/SIZE][/COLOR]

[FONT="courier new"]OpenBitmap[/FONT] opens the given file as a bitmap image and stores thefile handle in [FONT="courier new"]handle[/FONT]. Returns 0 on success or an error code.

[COLOR="DeepSkyBlue"][SIZE="5"][B][FONT="courier new"]OpenBitmapCache(const filename[], &Bitmap:handle, const colours[], len = sizeof colours);[/FONT][/B][/SIZE][/COLOR]

[FONT="courier new"]OpenBitmapCache[/FONT] opens the given file and caches all pixels that match the colours listed in [FONT="courier new"]colours[/FONT]. Returns 0 on success or an error code.

[COLOR="DeepSkyBlue"][SIZE="5"][B][FONT="courier new"]CloseBitmap(Bitmap:handle);[/FONT][/B][/SIZE][/COLOR]

[FONT="courier new"]CloseBitmap[/FONT] closes the specified file handle. Returns 0 on success, 1 if the handle is invalid.

[COLOR="DeepSkyBlue"][SIZE="5"][B][FONT="courier new"]GetRGB(Bitmap:handle, x, y, &r, &g, &b);[/FONT][/B][/SIZE][/COLOR]

[FONT="courier new"]GetRGB[/FONT] looks up the red, green and blue values stored in the specified X and Y coordinates and stores them in the result parameters [FONT="courier new"]r[/FONT], [FONT="courier new"]b[/FONT] and [FONT="courier new"]g[/FONT].

[COLOR="DeepSkyBlue"][SIZE="5"][B][FONT="courier new"]GetRandomCachedRGB(Bitmap:handle, colour, &x, &y);[/FONT][/B][/SIZE][/COLOR]

[FONT="courier new"]GetRandomCachedRGB[/FONT] provides coordinates and RGB information from a random pixel in the bitmap that contains the specified colour.

[COLOR="RoyalBlue"][SIZE="6"][B]Testing[/B][/SIZE][/COLOR]

You can compile the plugin and test it in a Docker container all with one command:

[CODE]
make build-e2e
[/CODE]

This will:

[LIST]
[*]build the plugin inside a Debian docker image
[*]build the Pawn package in [FONT="courier new"]test/[/FONT] with [URL="http://sampctl.com"]sampctl[/URL]
[*]run the server in [FONT="courier new"]test/[/FONT] as a container, also with sampctl
[/LIST]

Or you can just do the build process with:

[CODE]
make build-debian
[/CODE]

(thanks to maddinat0r for the Docker images!)

