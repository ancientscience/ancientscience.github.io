#include "saddleback_count_correct.hpp"
#include <iostream>

int main()
{
    TwoDimArray<4, 4> a = {
                              2, 2, 3, 5,
                              3, 4, 6, 6,
                              3, 5, 6, 6,
                              3, 6, 6, 9
                          };

    size_t count 
        = saddleback_count<4, 4>(a, 6);

    std::cout << "Count of 6 is: " 
              << count << std::endl; 
}
