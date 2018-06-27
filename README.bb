[COLOR="#FF4700"][SIZE="7"][B]samp-bitmapper[/B][/SIZE][/COLOR]

For generating in-game coordinates from a bitmap.

See [URL="http://forum.sa-mp.com/showthread.php?t=516560"]this thread[/URL] for the primary reason that this plugin exists. It’s best used with MapAndreas or ColAndreas and a texture map so you can automatically place items in the game world in areas.

Create a bitmap image of the map then paint specific colours over it. Then, load the bitmap and specify which colours you want to cache with [FONT="courier new"]OpenBitmapCache[/FONT]. You can then get random points in the image of specific cached colours with [FONT="courier new"]GetRandomCachedRGB[/FONT].

If you want to map larger or smaller bitmaps to areas of the map, [URL="https://github.com/Southclaws/samp-virtual-canvas"]use this library[/URL] to create a virtual canvas to perform the scaling.

For example, this:

[IMG]https://i.imgur.com/KJrnAArm.jpg[/IMG]

Generates this:

[IMG]https://i.imgur.com/GW34TtIl.jpg[/IMG]

See the thread linked above for more examples.

[COLOR="RoyalBlue"][SIZE="6"][B]Installation[/B][/SIZE][/COLOR]

Simply install to your project:

[CODE]
sampctl package install Southclaws/samp-bitmapper
[/CODE]

Or, if you prefer GitHub:

[LIST]
[*][URL="https://github.com/Southclaws/samp-bitmapper/releases"]Binaries[/URL]
[*][URL="https://github.com/Southclaws/samp-bitmapper"]Source & Include[/URL]
[/LIST]

Include in your code and begin using the library:

[CODE]
[COLOR="Blue"]#include <bitmapper>[/COLOR]
[/CODE]

[COLOR="RoyalBlue"][SIZE="6"][B]Usage[/B][/SIZE][/COLOR]

[COLOR="DeepSkyBlue"][SIZE="5"][B]Functions[/B][/SIZE][/COLOR]

[COLOR="SlateGray"][SIZE="5"][FONT="courier new"]OpenBitmap(const filename[], &Bitmap:handle);[/FONT][/SIZE][/COLOR]

Opens the given file as a bitmap image and stores thefile handle in [FONT="courier new"]handle[/FONT]. Returns 0 on success or an error code.

[COLOR="SlateGray"][SIZE="5"][FONT="courier new"]OpenBitmapCache(const filename[], &Bitmap:handle, const colours[], len = sizeof colours);[/FONT][/SIZE][/COLOR]

Opens the given file and caches all pixels that match the colours listed in [FONT="courier new"]colours[/FONT]. Returns 0 on success or an error code.

[COLOR="SlateGray"][SIZE="5"][FONT="courier new"]CloseBitmap(Bitmap:handle);[/FONT][/SIZE][/COLOR]

Closes the specified file handle. Returns 0 on success, 1 if the handle is invalid.

[COLOR="SlateGray"][SIZE="5"][FONT="courier new"]GetRGB(Bitmap:handle, x, y, &r, &g, &b);[/FONT][/SIZE][/COLOR]

Looks up the red, green and blue values stored in the specified X and Y coordinates and stores them in the result parameters [FONT="courier new"]r[/FONT], [FONT="courier new"]b[/FONT] and [FONT="courier new"]g[/FONT].

[COLOR="SlateGray"][SIZE="5"][FONT="courier new"]GetRandomCachedRGB(Bitmap:handle, colour, &x, &y);[/FONT][/SIZE][/COLOR]

Provides coordinates and RGB information from a random pixel in the bitmap that contains the specified colour.

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

