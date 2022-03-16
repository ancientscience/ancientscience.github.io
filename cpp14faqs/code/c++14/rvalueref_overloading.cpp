#include <memory>
#include <iostream>

template<typename T>
struct C 
{
    void push_back(const T& x) // #1
    {
        std::cout << "push_back(const value_type& x)" << std::endl;
    }

    void push_back(T&& x) // #2
    {
        std::cout << "push_back(value_type&& x)" << std::endl;
    }
};

void f(C<std::unique_ptr<int>> & c, std::unique_ptr<int> x) 
{
    c.push_back(x); // error: selects #1, which fails to instantiate
}

int main()
{
    C<std::unique_ptr<int>> c;

    f(c, std::unique_ptr<int>(new int(10)));
}
