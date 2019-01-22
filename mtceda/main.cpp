#include <iostream>
#include "Matrix.h"

int main()
{
    Matrix<int> mat = Matrix<int>(20, 20);
    std::cout << mat.Width() << ", " << mat.Height() << std::endl;
    std::cin.get();

    return 0;

}