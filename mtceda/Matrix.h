#ifndef MATRIX_H
#define MATRIX_H

template<class T>
class Matrix
{
public:
    Matrix(const unsigned short cols, const unsigned short rows)
    {
        this->m_rows = rows;
        this->m_cols = cols;

        //Initialize the matrix with zero values.
        //  So we don't take a stroll down undefined behaviour land.
        this->m_values = new T*[this->m_rows];

        for (int i = 0; i < this->m_rows; i++)
        {
            this->m_values[i] = new T[cols];
        }
    }

    ~Matrix()
    {
        //Clean each row.
        for (int i = 0; i < this->m_rows; i++)
        {
            delete[] this->m_values[i];
        }

        //Delete the entire (by now empty) matrix.
        delete[] this->m_values;
    }

    int Width() { return m_cols; }
    int Height() { return m_rows; }

private:
    unsigned short m_rows, m_cols;
    T** m_values;
};

#endif