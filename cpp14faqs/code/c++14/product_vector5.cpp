#include <vector>
#include <algorithm>
#include <iostream>

auto mult = [](auto x, auto y) { return x * y; };

int main()
{
    std::vector<int> v{1, 2, 3, 4, 5};

    auto prod = 
        std::accumulate(v.begin(), v.end(), 
                        1,
                        mult
                       );
    std::cout << "product : " << prod << std::endl;
}
