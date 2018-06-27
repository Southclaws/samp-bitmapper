# samp-bitmapper

For generating in-game coordinates from a bitmap.

## Installation

Simply install to your project:

```bash
sampctl package install Southclaws/samp-bitmapper
```

Or, if you prefer [GitHub](https://github.com/Southclaws/samp-bitmapper).

Include in your code and begin using the library:

```pawn
#include <bitmapper>
```

## Usage

### `OpenBitmap(const filename[], &Bitmap:handle);`

`OpenBitmap` opens the given file as a bitmap image and stores thefile handle in
`handle`. Returns 0 on success or an error code.

### `OpenBitmapCache(const filename[], &Bitmap:handle, const colours[], len = sizeof colours);`

`OpenBitmapCache` opens the given file and caches all pixels that match the
colours listed in `colours`. Returns 0 on success or an error code.

### `CloseBitmap(Bitmap:handle);`

`CloseBitmap` closes the specified file handle. Returns 0 on success, 1 if the
handle is invalid.

### `GetRGB(Bitmap:handle, x, y, &r, &g, &b);`

`GetRGB` looks up the red, green and blue values stored in the specified X and Y
coordinates and stores them in the result parameters `r`, `b` and `g`.

### `GetRandomCachedRGB(Bitmap:handle, colour, &x, &y);`

`GetRandomCachedRGB` provides coordinates and RGB information from a random
pixel in the bitmap that contains the specified colour.

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
