#include <a_samp>

#include "../../bitmapper.inc"

main() {
    new Bitmap:handle;
    new ret = OpenBitmap("test1.bmp", handle);
    printf("OpenBitmap ret: %d, handle: %d", ret, _:handle);

    new r, g, b;

    ret = GetRGB(handle, 0, 0, r, g, b);
    printf("GetRGB 0, 0: %d %d %d, ret: %d", r, g, b, ret);

    ret = GetRGB(handle, 1, 0, r, g, b);
    printf("GetRGB 1, 0: %d %d %d, ret: %d", r, g, b, ret);

    ret = GetRGB(handle, 2, 0, r, g, b);
    printf("GetRGB 2, 0: %d %d %d, ret: %d", r, g, b, ret);

    ret = GetRGB(handle, 3, 0, r, g, b);
    printf("GetRGB 3, 0: %d %d %d, ret: %d", r, g, b, ret);

    ret = GetRGB(handle, 4, 0, r, g, b);
    printf("GetRGB 4, 0: %d %d %d, ret: %d", r, g, b, ret);

    ret = CloseBitmap(handle);
    printf("CloseBitmap ret: %d", ret);
}
