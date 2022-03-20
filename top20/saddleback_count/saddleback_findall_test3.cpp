#include "saddleback_findall.hpp"
#include <iostream>

int main()
{
    TwoDimArray<4, 4> a = {
                              6, 6, 6, 6,
                              6, 6, 6, 6,
                              6, 6, 6, 6,
                              6, 6, 6, 6
                          };

    ListIndices indexList 
        = saddleback_findall<4, 4>(a, 6);

    std::cout << "6 is found at : \n";
    for(PairIndices & p : indexList)
    std::cout << "a[" << p.first << "]"
              << "[" << p.second << "]" 
              << std::endl;
}
