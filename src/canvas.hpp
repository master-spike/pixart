#ifndef PIXART_CANVAS_HPP_INCLUDED
#define PIXART_CANVAS_HPP_INCLUDED

#include <cstdint>
#include <string>
#include <string_view>
#include <vector>

#include "pixel.hpp"
#include "layer.hpp"

namespace pixart {

class canvas_layer {
public:
    layer& getLayer() {
        return m_layer;
    }
    const layer& getLayer() const {
        return m_layer;
    }
    canvas_layer() = delete;
    canvas_layer(std::string_view _name, layer&& _layer)
    : m_name(_name), m_layer(std::move(_layer)) {}
    
    void setHidden(bool val){
        m_hidden = val;
    }

private:
    std::string m_name;
    layer m_layer;
    bool m_hidden;
};

class canvas {
public:
    canvas() = delete;
    canvas(uint32_t _width, uint32_t _height) : m_width(_width), m_height(_height) {}
    
    std::vector<canvas_layer>::iterator add_layer(RGBApixel default_pixel) {
        m_canvas_layers.emplace_back(m_width, m_height, default_pixel);
        return m_canvas_layers.end()-1;
    };
private:
    uint32_t m_width;
    uint32_t m_height;
    std::vector<canvas_layer> m_canvas_layers;
};

}

#endif
