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
    hsv h;
    for (uint8_t i = 0; i < _parent->getNumLeds(); i++)
    {
        rgb2hsv(_parent->getLeds()[i], h);
        h.val = (h.val * (uint16_t)sinu8(INT16_MAX / _width * ((i + _step) % _width))) >> 8;
        hsv2rgb(h, _parent->getLeds()[i]);
    }
    ++_step %= _width;
}
