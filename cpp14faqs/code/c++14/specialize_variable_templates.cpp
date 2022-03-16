#include <iostream>
#include <iomanip>

template<typename T=double>
constexpr T pi = T(3.1415926535897932385);

template<>
constexpr float pi<int> = pi<float>;

int main()
{
    std::cout << std::setprecision(30);
    std::cout << "pi<> : " << pi<> << std::endl;
    std::cout << "pi<int> : " << pi<int> << std::endl;
    std::cout << "pi<float> : " << pi<float> << std::endl;
}
