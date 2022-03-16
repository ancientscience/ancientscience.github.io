#include <iostream>

template<typename T>
T magicVal = 42;

int main()
{
    std::cout << magicVal<int> << std::endl;;

    magicVal<int> = 0;

    std::cout << magicVal<int> << std::endl;;
}
