#include <iostream>

struct X { int i, j, k = 42; };

X a[] = { 1, 2, 3, 4, 5, 6 };

int main()
{
    size_t len = sizeof(a)/sizeof(a[0]);

    std::cout << "size of a is : " << len << std::endl;

    std::cout << "a[0].k : " << a[0].k << std::endl;
    std::cout << "a[1].k : " << a[1].k << std::endl;
}
