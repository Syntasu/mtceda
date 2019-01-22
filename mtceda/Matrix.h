#ifndef MATRIX_H
#define MATRIX_H

#include "Std.h"

template<class T>
class Matrix
{
    typedef std::vector<std::vector<T>> value_array;

public:
    Matrix()
    {
        this->m_rows = 0;
        this->m_cols = 0;
    }

    Matrix(const unsigned int cols, const unsigned int rows)
        : m_rows(rows), m_cols(cols)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                m_values[i][j] = {};
            }
        }
    }

    T Get(const int x, const int y)
    {
        return m_values[x][y];
    }

    void Set(const int x, const int y, T value)
    {
        m_values[x][y] = value;
    }

    const int Width() {
        return m_cols; 
    }

    const int Height() { 
        return m_rows; 
    }

private:
    unsigned short m_rows, m_cols;
    value_array m_values;
};

#endif