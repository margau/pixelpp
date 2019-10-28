#ifndef RGB_H
#define RGB_H

#include "common.h"

typedef struct rgb {
  uint8_t red;
  uint8_t green;
  uint8_t blue;
} rgb;

class RGB {
public:
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    RGB();
    RGB(uint8_t r, uint8_t g, uint8_t b);
};

typedef struct hsv {
    uint8_t hue;
    uint8_t sat;
    uint8_t val;
} hsv;

#endif
