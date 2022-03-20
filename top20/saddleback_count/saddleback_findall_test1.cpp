#include "saddleback_findall.hpp"
#include <iostream>

int main()
{
    TwoDimArray<4, 4> a = {
                              2, 2, 3, 5,
                              3, 4, 5, 6,
                              3, 5, 6, 8,
                              3, 6, 7, 9
                          };

    ListIndices indexList 
        = saddleback_findall<4, 4>(a, 6);

    std::cout << "6 is found at : \n";
    for(PairIndices & p : indexList)
    std::cout << "a[" << p.first << "]"
              << "[" << p.second << "]" 
              << std::endl;
}
