#include <functional>
#include <vector>
#include <algorithm>
#include <cassert>

int main()
{
    std::vector<const char *> v {"a", "abc", "ab"};
    std::sort(v.begin(), v.end(), std::greater<std::string>());
    assert( v == std::vector<const char *> ({"abc", "ab", "a"}));
}
