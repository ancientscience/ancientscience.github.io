#include <iostream>
#include <memory>
#include <cstdlib>

struct A
{
    A() { std::cout << " i : " << i << std::endl; }

    int i;
};

int main()
{
    auto a1 = new A;

    auto a2 = new A();

    std::cout << "Unique Pointer Start" << std::endl;
    std::make_unique<A>();
    std::cout << "Unique Pointer End" << '\n' << '\n';

    std::cout << "Shared Pointer Start" << std::endl;
    std::make_shared<A>();
    std::cout << "Shared Pointer End" << std::endl;
}
