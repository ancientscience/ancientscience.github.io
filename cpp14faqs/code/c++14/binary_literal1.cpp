#include <iostream>
#include <type_traits>
#include <limits>

template <char... Digits>
struct binary_lit_impl
{
    static_assert(! sizeof...(Digits),
        "binary literal digits must be 0 or 1");
    static constexpr unsigned long long value=0;
};

// If the next digit is zero, then compute the rest
template <char... Digits>
struct binary_lit_impl<'0',Digits...>
{
    static constexpr unsigned long long value=binary_lit_impl<Digits...>::value;
};

// If the next digit is one, then shift 1 and compute the rest
template <char... Digits>
struct binary_lit_impl<'1',Digits...>
{
    static constexpr unsigned long long value=
    binary_lit_impl<Digits...>::value|(1ULL<<sizeof...(Digits));
};


template <char... Digits>
constexpr unsigned long long operator "" _binary()
{
    return binary_lit_impl<Digits...>::value;
}


int main()
{
    const unsigned long long b = 110_binary;
    std::cout << "b : " << std::hex << b << std::endl;
}
