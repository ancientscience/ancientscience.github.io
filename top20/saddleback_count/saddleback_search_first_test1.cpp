#include "saddleback_search_first.hpp"
#include <iostream>

int main()
{
    TwoDimArray<4, 4> a = {
                              2, 2, 3, 5,
                              3, 4, 6, 6,
                              3, 5, 6, 6,
                              3, 6, 6, 9
                          };

    Point p 
        = saddleback_search_first<4, 4>(a, 6);

    std::cout << "6 is found at : a[" 
              << p.first << "][" 
              << p.second << "]"
              << std::endl; 

}
