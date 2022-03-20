#include <algorithm>
#include <array>

template <int m, int n>
using TwoDimArray 
    = std::array<std::array<int, n>, m>;

template <int m, int n>
size_t saddleback_count(
    TwoDimArray<m, n> & a, int x)
{
    size_t i = 0, j = n - 1, count = 0;

    while(j <= n - 1)
    {
        if(a[i][j] < x) i += 1;
        else if(a[i][j] > x) j -= 1;
        else // a[i][j] == x
        {
            count += 1;
            i += 1;
            j -= 1;
        }
    }

    return count;    
}
