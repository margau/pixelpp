#include "SawtoothEffect.hpp"

SawtoothEffect::SawtoothEffect(PixelPP* parent, uint8_t width, uint16_t period) : Effect(parent), _width(width), _peri(period)
{
}

SawtoothEffect::~SawtoothEffect()
{
}

void SawtoothEffect::render(unsigned long t)
{
	if (_peri == 0 || _width == 0)
	{
		return;
	}
	uint16_t numPixels = _parent->getNumLeds();
	for (uint16_t i = 0; i < numPixels; i++)
	{
		rgb& pix = _parent->_leds_rgb[i];
		pix.blue = pix.blue * ((i + t / _peri) % _width) / _width;
		pix.green = pix.green * ((i + t / _peri) % _width) / _width;
		pix.red = pix.red * ((i + t / _peri) % _width) / _width;
	}
}
