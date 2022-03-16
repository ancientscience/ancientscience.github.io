#include <iostream>
#include <iomanip>

template<typename T>
constexpr T pi = T(3.1415926535897932385);


constexpr long double operator "" _pi(long double x)
{
    return pi<long double> * x;
}

constexpr long double operator "" _pi(unsigned long long int x) 
{
    return pi<long double> * x;
}

int main()
{
    std::cout << std::setprecision(10);

    auto a = 2_pi;
    auto b = -3.5_pi;

    std::cout << a << std::endl;
    std::cout << b << std::endl;
}

