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
    uint16_t sin2 = (uint16_t)sinu8(t*(INT16_MAX/_peri));
    Serial.println(sin2);
    for (uint8_t i = 0; i < _parent->getNumLeds(); i++)
    {
        rgb* dat = &_parent->getLeds()[i];
        uint16_t sin = (uint16_t)sinu8(t*(INT16_MAX/_peri));
        dat->red = (dat->red * sin) >> 8U;
        dat->green = (dat->green * sin) >> 8U;
        dat->blue = (dat->blue * sin) >> 8U;
    }
}
