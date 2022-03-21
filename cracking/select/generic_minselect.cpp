#include <algorithm>
#include <utility>
#include <vector>
#include <cassert>

int generic_kth_minselect(std::vector<int> & a, 
                          size_t k)
{
    size_t minIndex = 0;
    size_t minVal = a[0];

    size_t numElements = a.size();

    for(size_t i = 0; i < k; ++i)
    {
        minIndex = i;
        minVal = a[i];
        
        for(size_t j = i + 1; 
            j < numElements; ++j)
        {
            minIndex = j;
            minVal = a[j];
        }
        std::swap(a[i], a[minIndex]);
    }
    return a[k - 1];
}


int main()
{
    std::vector<int> v {1, 23, 12, 9, 30, 2, 50};

    int fourth_min = generic_kth_minselect(v, 4);

    assert(fourth_min == 12);
}
