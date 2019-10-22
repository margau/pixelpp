#ifndef COLOR_CONV_HPP
#define COLOR_CONV_HPP

#include "common.h"
#include "rgb.h"

void rgb2hsv(const rgb & rgb, hsv & hsv);
void hsv2rgb(const hsv & hsv, rgb & rgb);

#endif