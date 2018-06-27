# samp-bitmapper

For generating in-game coordinates from a bitmap.

See [this thread](http://forum.sa-mp.com/showthread.php?t=516560) for the
primary reason that this plugin exists. It's best used with MapAndreas or
ColAndreas and a texture map so you can automatically place items in the game
world in areas.

Create a bitmap image of the map then paint specific colours over it. Then, load
the bitmap and specify which colours you want to cache with `OpenBitmapCache`.
You can then get random points in the image of specific cached colours with
`GetRandomCachedRGB`.

If you want to map larger or smaller bitmaps to areas of the map,
[use this library](https://github.com/Southclaws/samp-virtual-canvas) to create
a virtual canvas to perform the scaling.

For example, this:

![https://i.imgur.com/KJrnAArm.jpg](https://i.imgur.com/KJrnAArm.jpg)

Generates this:

![https://i.imgur.com/GW34TtIl.jpg](https://i.imgur.com/GW34TtIl.jpg)

See the thread linked above for more examples.

## Installation

Simply install to your project:

```bash
sampctl package install Southclaws/samp-bitmapper
```

Or, if you prefer GitHub:

- [Binaries](https://github.com/Southclaws/samp-bitmapper/releases)
- [Source & Include](https://github.com/Southclaws/samp-bitmapper)

Include in your code and begin using the library:

```pawn
#include <bitmapper>
```

## Usage

### Functions

#### `OpenBitmap(const filename[], &Bitmap:handle);`

Opens the given file as a bitmap image and stores thefile handle in `handle`.
Returns 0 on success or an error code.

#### `OpenBitmapCache(const filename[], &Bitmap:handle, const colours[], len = sizeof colours);`

Opens the given file and caches all pixels that match the colours listed in
`colours`. Returns 0 on success or an error code.

#### `CloseBitmap(Bitmap:handle);`

Closes the specified file handle. Returns 0 on success, 1 if the handle is
invalid.

#### `GetRGB(Bitmap:handle, x, y, &r, &g, &b);`

Looks up the red, green and blue values stored in the specified X and Y
coordinates and stores them in the result parameters `r`, `b` and `g`.

#### `GetRandomCachedRGB(Bitmap:handle, colour, &x, &y);`

Provides coordinates and RGB information from a random pixel in the bitmap that
contains the specified colour.

## Testing

You can compile the plugin and test it in a Docker container all with one
command:

```bash
make build-e2e
```

This will:

- build the plugin inside a Debian docker image
- build the Pawn package in `test/` with [sampctl](http://sampctl.com)
- run the server in `test/` as a container, also with sampctl

Or you can just do the build process with:

```bash
make build-debian
```

(thanks to maddinat0r for the Docker images!)
