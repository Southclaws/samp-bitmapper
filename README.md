# samp-bitmapper

For generating in-game coordinates from a bitmap.

## Installation

Note: Still in development.

<!-- Simply install to your project:

```bash
sampctl package install Southclaws/samp-bitmapper
```

Include in your code and begin using the library:

```pawn
#include <bitmapper>
``` -->

## Testing

You can compile the plugin and test it in a Docker container all with one command:

```bash
make build-e2e
```

This will:

* build the plugin inside a Debian docker image
* build the Pawn package in `test/` with [sampctl](http://sampctl.com)
* run the server in `test/` as a container, also with sampctl

Or you can just do the build process with:

```bash
make build-debian
```

(thanks to maddinat0r for the Docker images!)
