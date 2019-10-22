#ifndef PIXELPP_H
#define PIXELPP_H

#include "common.h"
#include "rgb.h"

#define COLOR_MONO 0
#define COLOR_RGB 1
#define COLOR_RGBW 2

typedef uint8_t  colorType;

class PixelPP {
  private:
  rgb* _leds;
  uint16_t _num_leds;

 public:

  // Constructor: number of LEDs, ColorType
  PixelPP(void);
  PixelPP(uint16_t n, colorType t=COLOR_RGB, uint8_t * pix=NULL);
  ~PixelPP();

  void render(void);

  uint16_t getNumLeds();
  rgb* getLeds();
};

#endif
