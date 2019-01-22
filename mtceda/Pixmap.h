#ifndef PIXMAP_H
#define PIXMAP_H

#include "Matrix.h"
#include "Std.h"

struct PixmapPixel {
    unsigned char R;
    unsigned char G;
    unsigned char B;

    PixmapPixel()
    {
        this->R = 0;
        this->G = 0;
        this->B = 0;
    }

    PixmapPixel(unsigned char r, unsigned char g, unsigned char b)
    {
        this->R = r;
        this->G = g;
        this->B = b;
    }
};

class Pixmap
{
public:
    Pixmap() {}

    void Load(const char* path);
    void Save(const char* path);

    inline void SetDimensions(const unsigned int width, const unsigned int height);
    inline void SetColorDepth(const unsigned int depth);

    inline void SetPixel(
        const unsigned int x, 
        const unsigned int y, 
        const PixmapPixel& pixel);

    inline PixmapPixel GetPixel(
        const unsigned int x,
        const unsigned int y
    );

    int Width() {
        return this->m_width;
    }

    int Height() {
        return this->m_height;
    }


private:
    unsigned int m_width;
    unsigned int m_height;
    unsigned int m_colorDepth;

    Matrix<PixmapPixel> m_matrix;
};

#endif