#define RUN_TESTS

#include "bitmapper.inc"

#include <a_samp>
#include <YSI\y_testing>


Test:ReadPixels() {
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

Test:GetRandom() {
    new
        ret,
        Bitmap:handle;

    ret = OpenBitmapCache("test2.bmp", handle, {0xff0000, 0x0000ff}, 2);
    ASSERT(ret == 0);

    new x, y;

    for(new i; i < 100; i++) {
        ret = GetRandomCachedRGB(handle, 0xff0000, x, y);
        ASSERT(ret == 0);
        ASSERT(x < 3);
        ASSERT(y < 3);
        printf("%d %d", x, y);
    }

    for(new i; i < 100; i++) {
        ret = GetRandomCachedRGB(handle, 0x0000ff, x, y);
        ASSERT(ret == 0);
        ASSERT(x > 4);
        ASSERT(y > 4);
        printf("%d %d", x, y);
    }

    ret = GetRandomCachedRGB(handle, 0xf3f3f3, x, y);
    printf("%d", ret);
    ASSERT(ret == 2);
}

main() {
    //
}
