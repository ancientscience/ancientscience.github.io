#include <algorithm>
#include <array>
#include <vector>

template <int m, int n>
using TwoDimArray 
    = std::array<std::array<int, n>, m>;

typedef std::pair<int, int> PairIndices;

typedef std::vector<PairIndices> ListIndices;

template <int m, int n>
ListIndices saddleback_findall(
                TwoDimArray<m, n> & a, int x)
{
    size_t i = 0, j = n - 1;
    ListIndices list_indices;
    int currrent_col_index = j;

    while(j <= n - 1)
    {
        if(a[i][j] < x) i += 1;
        else if(a[i][j] > x) j -= 1;
        else // a[i][j] == x
        {
            currrent_col_index = j;
            while(currrent_col_index >=0 && 
                  a[i][currrent_col_index] == x)
            list_indices.push_back(
          PairIndices(i, currrent_col_index--));

            ++i; 
        }
    }

    return list_indices;    
}
