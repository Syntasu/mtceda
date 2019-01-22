#include <iostream>
#include "Pixmap.h"

int main()
{
    //Matrix<int> mat = Matrix<int>(20, 20);
    //std::cout << mat.Width() << ", " << mat.Height() << std::endl;

    Pixmap map = Pixmap();
    map.Load("../samples/nhlstenden.ppm");

    
    std::cin.get();
    return 0;

}