#include <iostream>
#include <cassert>
#include <type_traits>

template< 
    class T,
    class = typename 
            std::enable_if< 
                      std::is_arithmetic<T>::value
                   || std::is_pointer<T>::value
            >::type
>
struct zero_init
{
    zero_init( )
    : val( static_cast<T>(0) ) 
    { }

    zero_init( T val ) : val( val )
    { }

    operator T & ( )
    { return val; }

    operator T( ) const
    { return val; }

private:
    T val;
};

int main()
{
    zero_init<int*> p; 
    assert( p == 0 );

    p = new int(7);
    assert( *p == 7 );

    delete p; 

    zero_init<int> i; assert( i == 0 );
    i = 7;
    assert( i == 7 );

    switch( i ) 
    { 
        case 7 :
        std::cout << "7" << std::endl;
        default:
        exit(0);
    } 
}
