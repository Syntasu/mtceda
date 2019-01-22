#include "Pixmap.h"

bool ParseHeader(Pixmap* map, std::vector<unsigned char> data)
{
    //The header consists of 3 parts.
    //  Each new line we advance the position by one.
    //  This will indicate were we are in the header
    //  and know what to write to.
    int headerPosition = 0;
    std::string current = "";

    //The header is 16 bits long
    for (int i = 0; i < 16; i++)
    {
        if (data[i] == '\n')
        {
            //The magic byte.
            if (headerPosition == 0)
            {
                if (current != "P6")
                {
                    std::cout << "The magic byte indicates that this is not a pixmap" << std::endl;
                    return false;
                }
            }
            //Width and height.
            else if (headerPosition == 1)
            {
                std::vector<std::string> dim = split(current, ' ');
                map->SetDimensions(std::stoi(dim[0]), std::stoi(dim[1]));
            }
            else if (headerPosition == 2)
            {
                map->SetColorDepth(std::stoi(current));
            }

            headerPosition++;
            current = "";
        }
        else
        {
            current += data[i];
        }
    }

    return true;
}

bool ParseBody(Pixmap* map, const std::vector<unsigned char> data)
{
    //Size of the data, minus the header size.
    //  Check if this divided by 3 results into no remainder.
    //  Important because we don't want any left out pixels.
    if ((data.size() - 16) % 3 != 0)
    {
        std::cout << "Pixmap cannot be split into 3 byte RGB sets equally, is the file corrupted?" << std::endl;
        return false;
    }

    int x = 0;
    int y = 0;

    for (size_t i = 16; i < data.size(); i += 3)
    {
        if (x == map->Width())
        {
            x = 0;
            y++;
        }

        PixmapPixel pixel = PixmapPixel(
            data[i], data[i+1], data[i+2]
        );

        map->SetPixel(x, y, pixel);
    }

    return true;
}

void Pixmap::Load(const char* filePath)
{
    std::ifstream inStream(filePath, 
        std::ios_base::in | std::ios_base::binary
    );

    if (inStream.is_open())
    {
        std::vector<unsigned char> data;
        unsigned char current = inStream.get();

        while (inStream.good())
        {
            data.push_back(current);
            current = inStream.get();
        }

        inStream.close();

        if (!ParseHeader(this, data))
        {
            std::cout << "Failed to parse the header!" << std::endl;
            return;
        }

        if (!ParseBody(this, data))
        {
            std::cout << "Failed to parse the body!" << std::endl;
            return;
        }

    }
    else
    {
        std::cout << "Could not open " << filePath << "!" << std::endl;
    }
}

void Pixmap::Save(const char* path)
{
}

inline void Pixmap::SetDimensions(
    const unsigned int width, 
    const unsigned int height)
{
    this->m_width = width;
    this->m_height = height;
    this->m_matrix = Matrix<PixmapPixel>(width, height);
}

inline void Pixmap::SetColorDepth(const unsigned int depth)
{
    this->m_colorDepth = depth;
}

inline void Pixmap::SetPixel(
    const unsigned int x, const unsigned int y, 
    const PixmapPixel& pixel)
{
    this->m_matrix.Set(x, y, pixel);
}

inline PixmapPixel Pixmap::GetPixel(
    const unsigned int x, const unsigned int y)
{
    return this->m_matrix.Get(x, y);
}