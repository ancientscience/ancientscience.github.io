#include <iostream>

int main()
{
    int x = 4;
 
    auto y = [&r = x, x = x+1]()
             {
                 r += 2;
                 std::cout << "r is : " << r << std::endl;
                 return x+2;
             }();

    std::cout << "y is : " << y << std::endl;
}
