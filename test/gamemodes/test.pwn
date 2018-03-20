#include <a_samp>

#include "../../bitmapper.inc"

main() {
    new Bitmap:handle;
    new ret = OpenBitmap("test1.bmp", handle);
    printf("OpenBitmap ret: %d, handle: %d", ret, _:handle);

    new r, g, b;

    ret = GetRGB(handle, 0, 0, r, g, b);
    printf("GetRGB X:0 Y:0: RED: %03d GREEN: %03d BLUE: %03d, ret: %d", r, g, b, ret);

    ret = GetRGB(handle, 1, 0, r, g, b);
    printf("GetRGB X:1 Y:0: RED: %03d GREEN: %03d BLUE: %03d, ret: %d", r, g, b, ret);

    ret = GetRGB(handle, 2, 0, r, g, b);
    printf("GetRGB X:2 Y:0: RED: %03d GREEN: %03d BLUE: %03d, ret: %d", r, g, b, ret);

    ret = GetRGB(handle, 3, 0, r, g, b);
    printf("GetRGB X:3 Y:0: RED: %03d GREEN: %03d BLUE: %03d, ret: %d", r, g, b, ret);

    ret = GetRGB(handle, 4, 0, r, g, b);
    printf("GetRGB X:4 Y:0: RED: %03d GREEN: %03d BLUE: %03d, ret: %d", r, g, b, ret);

    ret = CloseBitmap(handle);
    printf("CloseBitmap ret: %d", ret);
}
