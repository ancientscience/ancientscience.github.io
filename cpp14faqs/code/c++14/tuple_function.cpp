#include <tuple>
#include <utility>
#include <iostream>

void f(int x)
{
    std::cout << x << std::endl;
}

template<typename F, typename Tuple>
void apply(F && f, Tuple && t)
{
}


int main()
{
    auto t = std::make_tuple(1, 2, 3, 4, 5);

    apply(f, t);
}
