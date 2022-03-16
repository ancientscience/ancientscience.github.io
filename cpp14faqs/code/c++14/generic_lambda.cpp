#include <iostream>

int main()
{
// 'Identity' is a lambda that accepts an argument of any type and
 // returns the value of its parameter. 
    auto Identity = [](auto a) { return a; };

    int three_int = Identity(3);

    char const* three_str = Identity("three");

    std::cout << "three as integer : " << three_int << std::endl;
    std::cout << "three as const char* : " << three_str << std::endl;
} 
