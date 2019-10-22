#include "common.h"
#include "rgb.h"

#define HSV_SECTION_3 (0x40)

void rgb2hsv(const rgb & rgb, hsv & hsv)
{
    uint8_t minval = (rgb.red < rgb.green) ? (rgb.red < rgb.blue ? rgb.red : rgb.blue) : (rgb.green < rgb.blue ? rgb.green : rgb.blue);
    uint8_t maxval = (rgb.red > rgb.green) ? (rgb.red > rgb.blue ? rgb.red : rgb.blue) : (rgb.green > rgb.blue ? rgb.green : rgb.blue);
    uint8_t delta = maxval - minval;
    printf("%d, %d, %d\n", maxval, minval, delta);

    if (delta == 0)
    {
        hsv.hue = 0;
    }
    else if (maxval == rgb.red)
    {
        hsv.hue = ((32 * (192 * (rgb.green - rgb.blue) / delta)) / 192) % (3 * HSV_SECTION_3);
    }
    else if (maxval == rgb.green)
    {
        hsv.hue = ((32 * (192 * (rgb.blue - rgb.red) / delta)) / 192) + HSV_SECTION_3;
    }
    else if (maxval == rgb.blue)
    {
        hsv.hue = ((32 * (192 * (rgb.red - rgb.green) / delta)) / 192) + (2 * HSV_SECTION_3);
    }

    hsv.sat = (maxval == 0) ? 0 : (delta * 255 / maxval);

    hsv.val = maxval;
}
