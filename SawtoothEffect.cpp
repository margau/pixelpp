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
		uint8_t fade_val = (((t*255)/_peri) + ((i*255)/_width)) % 255;
		rgb& pix = _parent->_leds_rgb[i];
		pix.red = (pix.red * fade_val) >> 8U;
        	pix.green = (pix.green * fade_val) >> 8U;
	        pix.blue = (pix.blue * fade_val) >> 8U;
	}
}
