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
    int current_col_index = j;

    while(j <= n - 1)
    {
        if(a[i][j] < x) i += 1;
        else if(a[i][j] > x) j -= 1;
        else // a[i][j] == x
        {
            current_col_index = j;
            while(current_col_index >=0 && 
              a[i][current_col_index] == x)
            {
                ++count;
                current_col_index--;
            }
            ++i; 
        }
    }

    return count;    
}
