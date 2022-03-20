#include <algorithm>
#include <array>

using Point = std::pair<int, int>;

template <int m, int n>
using TwoDimArray 
    = std::array<std::array<int, n>, m>;

template <int m, int n>
Point saddleback_search_first(TwoDimArray<m, n>
                              & a, int x)
{
    Point p(-1, -1);

    int i = 0, j = n - 1;

    while(x != a[i][j])
    {
        if(a[i][j] < x) ++i;
        else --j;
    }

    while(x == a[i][j]) --j; 
    
    ++j;

    p.first = i;
    p.second = j;

    return p;    
}
