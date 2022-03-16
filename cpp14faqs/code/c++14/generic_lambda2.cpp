#include <iostream>

void f1(int (*)(int))   
{ 
    std::cout << "f1" << std::endl;
}

void h(int (*)(int))    
{ 
    std::cout << "h(int (*)(int))" << std::endl;
} 

void h(char (*)(int))   
{ 
    std::cout << "h(char (*)(int))" << std::endl;
}   
 

// generic lambda
auto glambda = [](auto a) { return a; };


int main()
{
  f1(glambda);   
  h(glambda);   
}
