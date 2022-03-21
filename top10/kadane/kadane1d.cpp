#include <iostream>
#include <array>
#include <vector>
#include <forward_list>
#include "kadane1d.hpp"

int main()
{
    std::array<int, 8> a 
    {-2, -3, 4, -1, -2, 1, 5, -3};

    std::cout << kadane1d(a.cbegin(), a.cend()) 
              << std::endl;

    std::vector<int> v 
    {-1, 4, -2, 5, -5, 2, -20, 6};

    std::cout << kadane1d(v.cbegin(), v.cend()) 
              << std::endl;

    std::forward_list<int> l 
    {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    std::cout << kadane1d(l.cbegin(), l.cend()) 
              << std::endl;
}
