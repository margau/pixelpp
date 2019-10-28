#include "FillEffect.hpp"

FillEffect::FillEffect(PixelPP* parent, rgb color) : _color(color), Effect(parent)
{
}

FillEffect::~FillEffect()
{
}

void FillEffect::render()
{
	for (uint16_t i = 0; i < _parent->getNumLeds(); i++)
	{
		_parent->getLeds()[i] = _color;
	}

}
