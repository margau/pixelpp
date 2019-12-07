#include "DimEffect.hpp"

DimEffect::DimEffect(PixelPP* parent, uint8_t percentage) : _percentage(percentage), Effect(parent)
{
}

DimEffect::~DimEffect()
{
}

void DimEffect::render(unsigned long t)
{
	uint16_t numPixels = _parent->getNumLeds();
	for (uint16_t i = 0; i < numPixels; i++)
	{
		rgb& pix = _parent->_leds_rgb[i];
        	pix.red = (pix.red * _percentage) >> 8U;
	        pix.green = (pix.green * _percentage) >> 8U;
	        pix.blue = (pix.blue * _percentage) >> 8U;
	}
}
