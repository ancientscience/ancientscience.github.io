#include <iostream>
#include <memory>

template<typename T1, typename T2>
void f(std::unique_ptr<T1> a, std::unique_ptr<T2> b)
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
    f(std::make_unique<A>(), std::make_unique<B>());
}
