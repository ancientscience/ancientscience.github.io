#include <iostream>

#define M(x, ...) __VA_ARGS__

int main()
{
    /*auto million = 1'000'000;
    auto pi = 3.14159'26535'89793;

    std::cout << "million is : " << million << std::endl;
    std::cout << "pi is : " << pi << std::endl;*/

    int x[2] = { M(1'2,3'4) };

    for(auto e : x)
    std::cout << e << std::endl;
}
