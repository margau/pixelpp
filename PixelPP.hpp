#ifndef PIXELPP_H
#define PIXELPP_H

#include "common.h"
#include "rgb.h"
#include "Effect.hpp"
#include <list>

#define COLOR_MONO 0

typedef uint8_t  colorType;

class PixelPP {
  private:
  uint8_t* _leds;
  uint16_t _num_leds;
  std::list<Effect*> _effects;
  LEDColor _type;
  LEDChannels _channels;
 public:
  // Constructor: number of LEDs, ColorType
  PixelPP(void);
  PixelPP(uint16_t n, uint8_t * pix = NULL, LEDColor t = LEDColor::RGB, LEDChannels channels = LEDChannels::RGB);
  ~PixelPP();
  PixelPP* addEffect(Effect* effect);
  void clearEffects();
  void render(void);
  rgb* _leds_rgb;
  uint16_t getNumLeds();
  void setPixel(uint16_t n, rgb const & rgb);
};

#endif
