#include "PixEffect.hpp"

PixEffect::PixEffect(PixelPP* parent, rgb color, uint16_t length, uint8_t num) : _length(length), _num(num), _color(color), Effect(parent)
{
        randomSeed(analogRead(0));
}

PixEffect::~PixEffect()
{
}

void PixEffect::render(unsigned long t)
{
	static uint16_t lastadd = 0;

	if (t - lastadd >= _length / _num)
	{
		pixfadeVector.push_back({
			random(_parent->getNumLeds()),
			t + _length
		});
		lastadd = t;
	}

	// Iterate and display
	std::list<pixfade>::iterator it = pixfadeVector.begin();
	while (it != pixfadeVector.end()) {
		// Remove element if end is over
		if (it->end <= t)
		{
			it = pixfadeVector.erase(it);
		}
		else
		{
			// Display pixel and move on
			uint8_t factor = (INT8_MAX*(it->end - t)) / _length;
			rgb& pix = _parent->_leds_rgb[it->n];
			pix = {
				(_color.red * factor) >> 8U,
				(_color.green * factor) >> 8U,
				(_color.blue * factor) >> 8U
			};
			++it;
		}
	}
}
