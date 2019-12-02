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
        for(int i=0; i<_num; i++) {
                // Add new random pixel
                pixfade p;
                p.n = random(_parent->getNumLeds());
                p.end = t+_length;
                pixfadeVector.push_back(p);
        }

        // Iterate and display
        auto it = pixfadeVector.begin();
        while(it != pixfadeVector.end()) {
                // Remove element if end is over
                if(it->end <= t) {
                        it = pixfadeVector.erase(it);
                } else {
                        // Display pixel and move on
                        uint8_t factor = (INT8_MAX*(it->end-t))/_length;
                        rgb& pix = _parent->_leds_rgb[it->n];
                        pix=_color;

                        // Calculate Fade factor
                        pix.red = (pix.red * factor) >> 8U;
                        pix.green = (pix.green * factor) >> 8U;
                        pix.blue = (pix.blue * factor) >> 8U;
                        ++it;
                }
        }
}
