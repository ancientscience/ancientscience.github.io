#include <type_traits>
#include <iomanip>
#include <iostream>

template< class T >
    using void_t = void;
    //using void_t = std::conditional_t<true, void, T>;


template< class, class = void >
struct has_type_member : std::false_type 
{ };

template< class T >
struct has_type_member<T, void_t<typename T::type>> : std::true_type
{ };

struct A 
{
    typedef int type;
};

struct B
{
};

int main()
{
    static_assert(has_type_member<A>::value, "");
    static_assert(!has_type_member<B>::value, "");

    std::cout << std::boolalpha;
    std::cout << has_type_member<A>() << std::endl;
    std::cout << has_type_member<B>() << std::endl;
    std::cout << has_type_member< std::common_type<int, double> >{}() << std::endl;    
    std::cout << has_type_member< std::common_type<int, std::string> >{}() << std::endl;    

}
