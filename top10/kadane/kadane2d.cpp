#include <vector>
#include <algorithm>
#include <iostream>

template <typename ForwardIterator>
typename std::iterator_traits<ForwardIterator>::value_type
kadane1d(ForwardIterator start, ForwardIterator end)
{
    typedef typename std::iterator_traits<
            ForwardIterator
        >::value_type value_type;

    value_type max_so_far = 0, max_ending_here = 0;

    while(start != end)
    {
        max_ending_here = std::max(max_ending_here + *start++, 0);
        max_so_far = std::max(max_so_far, max_ending_here);
    }
    return max_so_far;
}

void kadane2d(std::vector<std::vector<int>> & a)
{
    
}

int main()
{
    std::vector<int> row1 {2, -4, 5, -5, -9, 3, -4};
    std::vector<int> row2 {-5, -6, -9, 2, -5, 4, 1};
    std::vector<int> row3 {-3, 7, -7, 5, 6, -6, 0};
    std::vector<int> row4 {-3, 5, -8, 8, -2, 2, -7};
    std::vector<int> row5 {-4, 1, -1, 0, -1, -4, 1};

    std::vector<int> row12 {-3, -10, -4, -3, -14, 7, -3};
    std::vector<int> row13 {-1, 3, -2, 0, -3, -3, -4};
    std::vector<int> row14 {-1, 1, -3, 3, -11, 5, -11};
    std::vector<int> row15 {-2, -3, 4, -5, -10, -1, -3};

    int k1 = kadane1d(row1.begin(), row1.end());
    int k2 = kadane1d(row2.begin(), row2.end());
    int k3 = kadane1d(row3.begin(), row3.end());
    int k4 = kadane1d(row4.begin(), row4.end());
    int k5 = kadane1d(row5.begin(), row5.end());

    int k12 = kadane1d(row12.begin(), row12.end());
    int k13 = kadane1d(row13.begin(), row13.end());
    int k14 = kadane1d(row14.begin(), row14.end());
    int k15 = kadane1d(row15.begin(), row15.end());

    std::cout << k1 << ":" << k2 << ":" << k3 << ":" << k4 << ":" << k5 << std::endl;
    std::cout << k12 << ":" << k13 << ":" << k14 << ":" << k15 << std::endl;
}
