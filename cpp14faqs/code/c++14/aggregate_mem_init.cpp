#include <iostream>

struct A
{
    struct X { int a, b; };
    
    X x = { 1, 2 };

    int n;
};

int main()
{
    A a = {{10}, 5};
    std::cout << a.x.b << std::endl;
}
