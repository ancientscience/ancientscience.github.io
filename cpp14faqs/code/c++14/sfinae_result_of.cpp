//#include <type_traits>
//#include <utility>
//#include <string>

#include <iostream>

//struct eat { template<typename T> eat(T const &) {} };
//struct not_incrementable {};

struct increment_me 
{
    template<typename T>
    auto operator()(T t) const 
        -> decltype(++t)
    { 
        return ++t; 
    }
};


template <typename T>
typename std::result_of<increment_me(T)>::type 
//decltype(std::declval<increment_me>()(std::declval<T>())) 
call_increment_me(T t)
{
    return increment_me()(t);
}


struct A {};
struct B { template<typename T> B(T const &) {} };

A call_increment_me(B)
{
    std::cout << "A call_increment_me() called" << std::endl;
    return A();
}

int main()
{
    std::cout << increment_me()(5) << std::endl;
    std::cout << call_increment_me(5) << std::endl;
    call_increment_me(std::string("5"));
}

/*
template<typename A>
//#ifdef BUGBUG
  typename std::result_of<inc(A)>::type            // HARD ERROR HERE
//#else
//  decltype(std::declval<inc>()(std::declval<A>())) // SFINAE HERE
//#endif
try_inc(A a) {
    return inc()(a);
}

not_incrementable try_inc(eat) {
    return not_incrementable();
}

int main() {
    int x = try_inc(1); // OK
    not_incrementable y = try_inc(std::string("foo")); // OK, not_incrementable
}
*/
