#include <stddef.h>
#include <stdint.h>
#include "sin.h"
#include "SineEffect.hpp"

typedef struct rgb
{
    uint8_t red;
    uint8_t green;
    uint8_t blue;
} rgb;

#define NUM_LEDS 72

rgb leds[NUM_LEDS];


void fill(rgb color)
{
    for (uint8_t i = 0; i < NUM_LEDS; i++)
    {
        leds[i] = color;
    }
}

SineEffect::SineEffect(uint8_t width)
{
    _width = width;
    _step = 0;
}

SineEffect::~SineEffect()
{
}

void SineEffect::render(rgb* leds, uint8_t num_leds)
{
    for (uint8_t i = 0; i < num_leds; i++)
    {
        sinu8(INT16_MAX / _width * ((i + _step) % _width));
    }
    ++_step %= num_leds;
}
