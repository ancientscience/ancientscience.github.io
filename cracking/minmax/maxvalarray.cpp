#include <vector>
#include <algorithm>
#include <cassert>

template <typename T>
size_t maxValArray(std::vector<T> & v)
{
    size_t i = 1, k = 0;
    size_t n = v.size();

    while(i <= n)
    {
        if(v[i] >= v[k]) k = i;
        ++i;
    }

    assert(v[k] == *std::max_element(v.begin(), 
                                     v.end()));
    return k;
}

int main()
{
    std::vector<int> v {10, 12, 2, 8, 5, 20, 7};
    maxValArray(v); 
}
