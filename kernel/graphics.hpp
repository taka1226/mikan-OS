#pragma once

#include "frame_buffer_config.hpp"

// #@@range_begin(pixel_color_def)
struct PixelColor{
    uint8_t r, g, b;
};
// #@@range_end(pixel_color_def)

class PixelWriter {
public:
    PixelWriter(const FrameBufferConfig& config) : config_{config}{}
    virtual ~PixelWriter() = default;
    virtual void Write(int x, int y, const PixelColor& c) = 0;

protected:
    uint8_t* PixelAt(int x, int y){
        return config_.frame_buffer + 4 * (config_.pixels_per_scan_line * y + x);
    }

private:
    const FrameBufferConfig& config_;
};

// #@@range_begin(pixel_writer_def)
class RGBResv8BitPerColorPixelWriter : public PixelWriter {
public:
    using PixelWriter::PixelWriter;
    virtual void Write(int x, int y, const PixelColor& c) override;
};

class BGRResv8BitPerColorPixelWriter : public PixelWriter {
public:
    using PixelWriter::PixelWriter;
    virtual void Write(int x, int y, const PixelColor& c) override;
};
// #@@range_end(pixel_writer_def)

// #@@range_begin(vector2D)
template <typename T>
struct Vector2D {
    T x, y;

    template <typename U>
    Vector2D<T>& operator += (const Vector2D<U>& rhs){
        x += rhs.x;
        y += rhs.y;
        return *this;
    }
};
// #@@range_end(vector2D)

// #@@range_begin(FillRectangle)
void FillRectangle(PixelWriter& writer, const Vector2D<int>& pos, const Vector2D<int>& size, const PixelColor& c);
// #@@range_end(FillRectangle)

// #@@range_begin(drawRectangle)
void DrawRectangle(PixelWriter& writer, const Vector2D<int>& pos, const Vector2D<int>& size, const PixelColor& c);
// #@@range_end(drawRectangle)
