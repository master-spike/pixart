#ifndef PIXART_PIXEL_HPP_INCLUDED
#define PIXART_PIXEL_HPP_INCLUDED

#include <cstdint>

namespace pixart {

struct RGBApixel {
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
    RGBApixel() noexcept : r(0), g(0), b(0), a(0) {}
    RGBApixel(uint8_t _r, uint8_t _g, uint8_t _b, uint8_t _a) noexcept
    : r(_r), g(_g), b(_b), a(_a) {}
};

}


#endif
