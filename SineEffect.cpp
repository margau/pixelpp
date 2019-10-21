#include "SineEffect.hpp"
#include "sin.h"

SineEffect::SineEffect(PixelPP* parent, uint8_t width) : _parent(parent), _width(width)
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
        sinu8(INT16_MAX / _width * ((i + _step) % _width));
    }
    ++_step %= _parent->getNumLeds();
}
