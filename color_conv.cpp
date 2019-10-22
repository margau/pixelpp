#include "color_conv.hpp"

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

void hsv2rgb(const hsv & hsv, rgb & rgb)
{
    // Convert hue, saturation and brightness ( HSV/HSB ) to RGB
    // "Dimming" is used on saturation and brightness to make
    // the output more visually linear.

    // Apply dimming curves
    uint8_t value = hsv.val;
    uint8_t saturation = hsv.sat;

    // The brightness floor is minimum number that all of
    // R, G, and B will be set to.
    uint8_t invsat = 255 - saturation;
    uint8_t brightness_floor = value * invsat / 256;

    // The color amplitude is the maximum amount of R, G, and B
    // that will be added on top of the brightness_floor to
    // create the specific hue desired.
    uint8_t color_amplitude = value - brightness_floor;

    // Figure out which section of the hue wheel we're in,
    // and how far offset we are withing that section
    uint8_t section = hsv.hue / HSV_SECTION_3; // 0..2
    uint8_t offset = hsv.hue % HSV_SECTION_3;  // 0..63

    uint8_t rampup = offset; // 0..63
    uint8_t rampdown = (HSV_SECTION_3 - 1) - offset; // 63..0

    // compute color-amplitude-scaled-down versions of rampup and rampdown
    uint8_t rampup_amp_adj   = (rampup   * color_amplitude) / HSV_SECTION_3;
    uint8_t rampdown_amp_adj = (rampdown * color_amplitude) / HSV_SECTION_3;

    // add brightness_floor offset to everything
    uint8_t rampup_adj_with_floor   = rampup_amp_adj   + brightness_floor;
    uint8_t rampdown_adj_with_floor = rampdown_amp_adj + brightness_floor;


    if( section ) {
        if( section == 1) {
            // section 1: 0x40..0x7F
            rgb.red = brightness_floor;
            rgb.green = rampdown_adj_with_floor;
            rgb.blue = rampup_adj_with_floor;
        } else {
            // section 2; 0x80..0xBF
            rgb.red = rampup_adj_with_floor;
            rgb.green = brightness_floor;
            rgb.blue = rampdown_adj_with_floor;
        }
    } else {
        // section 0: 0x00..0x3F
        rgb.red = rampdown_adj_with_floor;
        rgb.green = rampup_adj_with_floor;
        rgb.blue = brightness_floor;
    }
}