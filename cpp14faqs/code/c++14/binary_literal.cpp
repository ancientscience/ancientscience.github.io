#include <iostream>
#include <type_traits>
#include <limits>

template <unsigned long long val, typename... Integers>
struct SelectIntType;

template <unsigned long long val, typename TypeInt, typename... Integers>
struct SelectIntType<val,TypeInt,Integers...>
    :
std::integral_constant<
   typename std::conditional<
                            (val <= static_cast<unsigned long long>
                                    (std::numeric_limits<TypeInt>::max())
                            ),
                            TypeInt,
                            typename SelectIntType<
                                        val, Integers...>::value_type 
                            >::type, 
                      val> 
{};

template <unsigned long long val>
struct SelectIntType<val>:std::integral_constant<unsigned long long,val>
{};

template <char... Digits>
struct bitsImpl
{
    static_assert(! sizeof...(Digits),
        "binary literal digits must be 0 or 1");
    static constexpr unsigned long long value=0;
};

template <char... Digits>
struct bitsImpl<'0',Digits...>
{
    static constexpr unsigned long long value=bitsImpl<Digits...>::value;
};

template <char... Digits>
struct bitsImpl<'1',Digits...>
{
    static constexpr unsigned long long value=
    bitsImpl<Digits...>::value|(1ULL<<sizeof...(Digits));
};


template <char... Digits>
constexpr typename SelectIntType<bitsImpl<Digits...>::value,
        int, unsigned, long, unsigned long, long long>::value_type
operator "" _binary()
{
    return SelectIntType<bitsImpl<Digits...>::value,
        int, unsigned, long, unsigned long, long long>::value;
}


template <char... Digits>
constexpr typename SelectIntType<bitsImpl<Digits...>::value,
        long, unsigned long, long long>::value_type
operator "" _binaryl()
{
    return SelectIntType<bitsImpl<Digits...>::value,
        long, unsigned long, long long>::value;
}


template <char... Digits>
constexpr auto operator "" _binaryL() 
    -> decltype(operator "" _binaryl<Digits...>())
{
    return operator "" _binaryl<Digits...>();
}


template <char... Digits>
constexpr typename SelectIntType<bitsImpl<Digits...>::value,
         long long>::value_type
operator "" _binaryll()
{
    return SelectIntType<bitsImpl<Digits...>::value,
                           long long>::value;
}


template <char... Digits>
constexpr auto operator "" _binaryLL() 
    -> decltype(operator "" _binaryll<Digits...>())
{
    return operator "" _binaryll<Digits...>();
}



template <char... Digits>
constexpr typename SelectIntType<bitsImpl<Digits...>::value,
        unsigned, unsigned long>::value_type
operator "" _binaryu()
{
    return SelectIntType<bitsImpl<Digits...>::value,
                           unsigned, unsigned long>::value;
}



template <char... Digits>
constexpr auto operator "" _binaryU() 
    -> decltype(operator "" _binaryu<Digits...>())
{
    return operator "" _binaryu<Digits...>();

}



template <char... Digits>
constexpr typename SelectIntType<bitsImpl<Digits...>::value,
                                   unsigned long>::value_type
operator "" _binaryul()
{
    return SelectIntType<bitsImpl<Digits...>::value,
                          unsigned long>::value;
}



template <char... Digits>
constexpr auto operator "" _binaryUL() 
    -> decltype(operator "" _binaryul<Digits...>())
{
    return operator "" _binaryul<Digits...>();
}



template <char... Digits>
constexpr auto operator "" _binaryuL() 
    -> decltype(operator "" _binaryul<Digits...>())
{
    return operator "" _binaryul<Digits...>();
}



template <char... Digits>
constexpr auto operator "" _binaryUl() 
    -> decltype(operator "" _binaryul<Digits...>())
{
    return operator "" _binaryul<Digits...>();
}



template <char... Digits>
constexpr unsigned long long operator "" _binaryull()
{
    return bitsImpl<Digits...>::value;
}



template <char... Digits>
constexpr unsigned long long operator "" _binaryULL()
{
    return bitsImpl<Digits...>::value;
}



template <char... Digits>
constexpr unsigned long long operator "" _binaryuLL()
{
    return bitsImpl<Digits...>::value;
}



template <char... Digits>
constexpr unsigned long long operator "" _binaryUll()
{
    return bitsImpl<Digits...>::value;
}




int main()
{
    auto a1 = 110_binary;
    auto a2 = 110_binaryl;
    auto a3 = 110_binaryL;
    auto a4 = 110_binaryll;
    auto a5 = 110_binaryu;
    auto a6 = 110_binaryul;
    auto a7 = 110_binaryUL;
    auto a8 = 110_binaryUl;
    auto a9 = 110_binaryuL;
    auto a10 = 110_binaryull;
    auto a11 = 110_binaryULL;
    auto a12 = 110_binaryuLL;
    auto a13 = 110_binaryUll;
}
