#include <iostream>

struct A 
{
    constexpr A() : n(3) {}
    constexpr int getN() const { return n; }
  
    int n;
};


struct B 
{
    constexpr B() : a() {}
    constexpr const A &getA() const
    { 
        return a; 
    }
    A &getA() 
    { 
        return a; 
    }            
  
    A a;
};


int main()
{
    
    constexpr int n = B().getA().getN(); 
}
