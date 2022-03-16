#include <vector>
#include <algorithm>
#include <iostream>

int main()
{
    std::vector<int> v{1, 2, 3, 4, 5};

    auto prod = 
        std::accumulate(v.begin(), v.end(), 
                        1,
                        std::multiplies<int>());
    std::cout << "product : " << prod << std::endl;
}
