#include <iostream>

void f1(int (*)(int))   
{ 
    std::cout << "f1" << std::endl;
}

void f2(char (*)(int))  
{ 
    std::cout << "f2" << std::endl;
}

void g(int (*)(int))    
{ 
    std::cout << "g(int (*)(int))" << std::endl;
}  

void g(char (*)(char))  
{ 
    std::cout << "g(char (*)(char))" << std::endl;
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
  f2(glambda);   
  g(glambda);   
  h(glambda);   
}
