#include "SineEffect.hpp"
#include "sin.h"

SineEffect::SineEffect(PixelPP* parent, uint8_t width) : Effect(parent), _width(width)
{
    _step = 0;
}

SineEffect::~SineEffect()
{
}

void SineEffect::render()
{
    for (uint8_t i = 0; i < _parent->getNumLeds(); i++)
    {
        rgb* dat = &_parent->getLeds()[i];
        uint16_t sin = (uint16_t)sinu8(INT16_MAX / _width * ((i + _step) % _width));
        dat->red = (dat->red * sin) >> 8U;
        dat->green = (dat->green * sin) >> 8U;
        dat->blue = (dat->blue * sin) >> 8U;
    }
    ++_step %= _width;
}
