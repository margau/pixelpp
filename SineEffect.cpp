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
    for (uint16_t i = 0; i < _parent->getNumLeds(); i++)
    {
        rgb dat;
        uint16_t sin = (uint16_t)sinu8(t*(INT16_MAX/_peri)+(i % _width)*INT16_MAX);
        dat.red = (dat.red * sin) >> 8U;
        dat.green = (dat.green * sin) >> 8U;
        dat.blue = (dat.blue * sin) >> 8U;
        _parent->setPixel(i, dat);
    }
}
