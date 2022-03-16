#include <functional>
#include <vector>
#include <algorithm>
#include <cassert>
#include <iostream>

int main()
{
    std::vector<const char *> v {"a", "aaa", "aa"};
    std::sort(v.begin(), v.end(), std::greater<>());
    for(auto e : v)
    std::cout << e << std::endl;
    //assert( v == std::vector<const char *> ({"abc", "ab", "a"}));
}
