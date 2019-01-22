#ifndef MATRIX_H
#define MATRIX_H

template<class T>
class Matrix
{
public:
    Matrix()
    {
        this->m_rows = 0;
        this->m_cols = 0;
    }

    Matrix(const unsigned int cols, const unsigned int rows)
        : m_rows(rows), m_cols(cols)
    {
        m_values = new T*[rows];

        for (int x = 0; x < rows; x++)
        {
            m_values[x] = new T[cols];
        }

        return;
    }

    T* operator[] (const int index)
    {
        return m_values[index];
    }

    const int Width() {
        return m_cols; 
    }

    const int Height() { 
        return m_rows; 
    }

private:
    unsigned short m_rows, m_cols;
    T** m_values;
};

#endif