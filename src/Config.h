#pragma once

#include <set>
#include <cstdint>
#include <string>

struct Config
{
    enum class DataFormat {
        Xml,
        Text,
        Bin,
        Json
    };

    struct Color
    {
        uint8_t r;
        uint8_t g;
        uint8_t b;

        uint32_t getBGR() const
        {
            return r + (g << 8) + (b << 16);
        }

        bool operator == (const Color& other) const
        {
            return r == other.r && g == other.b && b == other.b;
        }
    };

    struct Size
    {
        uint32_t w;
        uint32_t h;
    };

    struct Padding
    {
        int up;
        int right;
        int down;
        int left;
    };

    struct Spacing
    {
        int ver;
        int hor;
    };

    std::string fontFile;
    std::set<uint32_t> chars;
    Color color;
    Color backgroundColor;
    bool backgroundTransparent;
    uint16_t fontSize;
    Padding padding;
    Spacing spacing;
    Size textureSize;
    std::string output;
    DataFormat dataFormat;
    bool includeKerningPairs = false;
};
