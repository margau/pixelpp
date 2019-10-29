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
        rgb dat;
        uint16_t sin = sinu8((INT16_MAX * (t/_peri)));
        dat.red = ((uint16_t)dat.red * sin) >> 8U;
        dat.green = ((uint16_t)dat.green * sin) >> 8U;
        dat.blue = ((uint16_t)dat.blue * sin) >> 8U;
        Serial.printf("%d, %d, %d\n", dat.red, dat.green, dat.blue);
        _parent->setPixel(i, dat);
    }
}
