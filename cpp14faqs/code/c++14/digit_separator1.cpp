#include <cassert>

int main()
{
    auto x1 = 12; // decimal
    auto x2 = 014; // octal
    auto x3 = 0XC; // hexadecimal
    auto x4 = 0b1100; // binary 
    auto x5 = 0B1100; // binary 

    assert(x1 == x2);
    assert(x2 == x3);
    assert(x3 == x4);
    assert(x4 == x5);
}
