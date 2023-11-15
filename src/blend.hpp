#ifndef PIXART_BLEND_HPP_INCLUDED
#define PIXART_BLEND_HPP_INCLUDED

#include "pixel.hpp"

namespace pixart {

struct blend_func {
    RGBApixel blend(RGBApixel top, RGBApixel lower) {
        RGBApixel blended = blend_rgb(top, lower);
        auto lerp_u8 = [](uint16_t t, uint16_t u, uint16_t a) -> uint8_t {
            uint16_t res = (255u - a) * t + a * u;
            return res / 255u;
        };
        blended.r = lerp_u8(lower.r, blended.r, top.a);
        blended.g = lerp_u8(lower.g, blended.g, top.a);
        blended.b = lerp_u8(lower.b, blended.b, top.a);
        blended.a = lerp_u8(lower.a, 255, top.a);
    }
private:
    virtual RGBApixel blend_rgb(RGBApixel const& top, RGBApixel const& lower) = 0;
};

}

#endif
