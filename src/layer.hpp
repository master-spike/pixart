#ifndef PIXART_LAYER_HPP_INCLUDED
#define PIXART_LAYER_HPP_INCLUDED

#include <cstdint>
#include <vector>
#include <span>
#include <cassert>
#include <optional>

#include "pixel.hpp"

namespace pixart {

class layer {
public:
    layer() = delete;
    layer(uint32_t _width, uint32_t _height, RGBApixel _default_pixel) :
        m_width(_width), m_height(_height),
        m_pixels(_width * _height, _default_pixel) {};

    uint32_t getWidth() const noexcept { return m_width; } 
    uint32_t getHeight() const noexcept { return m_height; }

    std::span<const RGBApixel> getPixels() const noexcept {
        return std::span(m_pixels.cbegin(), m_pixels.cend());
    }

    std::optional<RGBApixel> readPixel(uint32_t x, uint32_t y) {
        if (y * m_width + x >= m_width * m_height) return std::nullopt;
        return m_pixels[y * m_width + x];
    }

    void writePixel(uint32_t x, uint32_t y, RGBApixel color) {
        if(y * m_width + x >= m_width * m_height) return;
        m_pixels[y * m_width + x] = color;
    }

private:
    uint32_t m_width;
    uint32_t m_height;
    std::vector<RGBApixel> m_pixels;
};

}

#endif
