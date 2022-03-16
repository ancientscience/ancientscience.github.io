#include <memory>
#include <iostream>

int main()
{
    auto up = std::make_unique<int[]>(5);
    
    for(int i = 0; i < 5; ++i)
    {
        std::cout << up[i] << " ";
    }
    std::cout << std::endl;
}
