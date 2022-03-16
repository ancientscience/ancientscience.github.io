#include <functional>
#include <vector>
#include <algorithm>
#include <cassert>

int main()
{
    std::vector<int> v {5, 1, 6, 3, 4, 2};
    std::sort(v.begin(), v.end(), std::greater<>());
    assert( v == std::vector<int> ({6, 5, 4, 3, 2, 1}));
}
