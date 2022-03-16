#include <iostream>

template<typename T1, typename T2>
void f(T1 * a, T2 * b)
{}

struct A
{
    A() { std::cout << "A()" << std::endl; }
    ~A() { std::cout << "~A()" << std::endl; }
};

struct B
{
    B() { std::cout << "B()" << std::endl; }
    ~B() { std::cout << "~B()" << std::endl; }
};

int main()
{
    f(new A, new B);
}
