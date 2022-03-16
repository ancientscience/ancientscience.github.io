#include <iostream>
#include <memory>
#include <cstdlib>

void* operator new(std::size_t s) 
{
    std::cout << "global operator new called" << std::endl;
    return std::malloc(s);
}

void operator delete(void* ptr) noexcept
{
    std::cout << "global operator delete called" << std::endl;
    std::free(ptr);
}

struct A
{
    A() { std::cout << "A's constructor called" << std::endl; }
    ~A() { std::cout << "A's destructor called" << std::endl; }

    static void* operator new(std::size_t s)
    {
        std::cout << "custom operator new called" << '\n';
        return ::operator new(s);
    }

    static void operator delete(void * ptr)
    {
        std::cout << "custom operator delete called" << '\n';
        ::operator delete(ptr);
    }

};

int main()
{
    std::cout << "Unique Pointer Start" << std::endl;
    std::make_unique<A>();
    std::cout << "Unique Pointer End" << '\n' << '\n';

    std::cout << "Shared Pointer Start" << std::endl;
    std::make_shared<A>();
    std::cout << "Shared Pointer End" << std::endl;
}
