#include <a_samp>

#include "../../bitmapper.inc"

main() {
    new Bitmap:handle;
    new ret = OpenBitmap("test1.bmp", handle);
    printf("OpenBitmap ret: %d, handle: %d", ret, _:handle);

    new r, g, b;

    ret = GetRGB(handle, 0, 0, r, g, b);
    printf("GetRGB X:0 Y:0: RED: %x GREEN: %x BLUE: %x, ret: %x", r, g, b, ret);

    ret = GetRGB(handle, 1, 0, r, g, b);
    printf("GetRGB X:1 Y:0: RED: %x GREEN: %x BLUE: %x, ret: %x", r, g, b, ret);

    ret = GetRGB(handle, 2, 0, r, g, b);
    printf("GetRGB X:2 Y:0: RED: %x GREEN: %x BLUE: %x, ret: %x", r, g, b, ret);

    ret = GetRGB(handle, 3, 0, r, g, b);
    printf("GetRGB X:3 Y:0: RED: %x GREEN: %x BLUE: %x, ret: %x", r, g, b, ret);

    ret = GetRGB(handle, 4, 0, r, g, b);
    printf("GetRGB X:4 Y:0: RED: %x GREEN: %x BLUE: %x, ret: %x", r, g, b, ret);

    ret = CloseBitmap(handle);
    printf("CloseBitmap ret: %d", ret);
}

Test:Bitmap1Pixel00() {
    new
        ret,
        Bitmap:handle;

    ret = OpenBitmap("test1.bmp", handle);
    ASSERT(ret == 0);

    new r, g, b;
    ret = GetRGB(handle, 0, 0, r, g, b);
    ASSERT(ret == 0);
    ASSERT(r == 0xFF);
    ASSERT(g == 0xFF);
    ASSERT(b == 0xFF);

    ret = CloseBitmap(handle);
    ASSERT(ret == 0);
}
