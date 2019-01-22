#include "Matrix.h"

template<class T>
Matrix<T>::Matrix(const unsigned short rows, const unsigned short cols)
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

template<class T>
Matrix<T>::~Matrix()
{
    //Clean each row.
    for (int i = 0; i < this->m_rows; i++)
    {
        delete[] this->m_values[i];
    }
    
    //Delete the entire (by now empty) matrix.
    delete[] this->m_values;
}
