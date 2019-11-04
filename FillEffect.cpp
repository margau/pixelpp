#include "FillEffect.hpp"

FillEffect::FillEffect(PixelPP* parent, rgb color) : _color(color), Effect(parent)
{
}

FillEffect::~FillEffect()
{
}

void FillEffect::render(unsigned long t)
{
	for (uint16_t i = 0; i < _parent->getNumLeds(); i++)
	{
    _parent->_leds_rgb[i] = _color;
	}

}
