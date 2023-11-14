#ifndef PIXART_LAYER_HPP_INCLUDED
#define PIXART_LAYER_HPP_INCLUDED

#include <cstdint>
#include <vector>
#include <span>

#include "pixel.hpp"

namespace pixart {

class layer {
public:
    layer() = delete;
    layer(uint32_t _width, uint32_t _height, RGBApixel _default_pixel) :
        m_bck_color(_default_pixel), m_width(_width), m_height(_height),
        m_pixels(_width * _height, _default_pixel) {};

    uint32_t getWidth() const noexcept { return m_width; } 
    uint32_t getHeight() const noexcept { return m_height; }

    std::span<const RGBApixel> readPixels() const noexcept {
        return std::span(m_pixels.cbegin(), m_pixels.cend());
    }

    
    
private:

    RGBApixel m_bck_color;
    uint32_t m_width;
    uint32_t m_height;
    std::vector<RGBApixel> m_pixels;

};

}

#endif
