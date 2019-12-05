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
        // Add additional pixels if some timed out
        for (int i = 0; i < _num - pixfadeVector.size(); i++)
        {
                pixfadeVector.push_back({
                    random(_parent->getNumLeds()),
                    t + _length
                });
        }

        // Iterate and display
        auto it = pixfadeVector.begin();
        while(it != pixfadeVector.end()) {
                // Remove element if end is over
                if(it->end <= t) {
                        it = pixfadeVector.erase(it);
                } else {
                        // Display pixel and move on
                        uint8_t factor = (INT8_MAX*(it->end - t)) / _length;
                        rgb& pix = _parent->_leds_rgb[it->n];
                        pix = _color;

                        // Calculate Fade factor
                        pix.red = (_color.red * factor) >> 8U;
                        pix.green = (_color.green * factor) >> 8U;
                        pix.blue = (_color.blue * factor) >> 8U;
                        ++it;
                }
        }
}
