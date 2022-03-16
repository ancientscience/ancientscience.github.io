#include <iostream>
#include <iomanip>

template<typename T>
constexpr T pi = T(3.1415926535897932385);

int main()
{
    std::cout << std::setprecision(40);
    std::cout << "pi<int> : " << pi<int> << std::endl;
    std::cout << "pi<float> : " << pi<float> << std::endl;
    std::cout << "pi<double> : " << pi<double> << std::endl;
}
