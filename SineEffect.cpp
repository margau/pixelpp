#include "SineEffect.hpp"
#include "sin.h"

SineEffect::SineEffect(PixelPP* parent, uint8_t width, uint16_t period) : Effect(parent), _width(width), _peri(period)
{

}

SineEffect::~SineEffect()
{
}

void SineEffect::render(unsigned long t)
{
    uint16_t numPixels = _parent->getNumLeds();
    for (uint16_t i = 0; i < numPixels; i++)
    {
        rgb& pix = _parent->_leds_rgb[i];
        uint16_t sin_val = sinu8(t*(INT16_MAX/_peri)+i*(INT16_MAX/_width));
        pix.red = (pix.red * sin_val) >> 8U;
        pix.green = (pix.green * sin_val) >> 8U;
        pix.blue = (pix.blue * sin_val) >> 8U;
    }
}
