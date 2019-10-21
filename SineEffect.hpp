#ifndef SINEEFFECT_HPP
#define SINEEFFECT_HPP
#include <stdint.h>

class SineEffect
{
private:
    uint8_t _width;
    uint8_t _step;
public:
    SineEffect(uint8_t freq);
    ~SineEffect();
    void render(rgb* leds, uint8_t num_leds);
    void reset();
};

#endif