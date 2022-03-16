#include <iostream>

template<typename T>
constexpr T binary_lit_impl()
{
  return 0;
}

template<typename T, char C, char... Digits>
constexpr T binary_lit_impl()
{
  static_assert(C == '0' || C == '1', "not a valid binary number");
  return binary_lit_impl<T, Digits...>() + ((C=='1') ? 1 : 0) * (1ULL << sizeof...(Digits));
}


template<char... Digits>
constexpr unsigned long long operator "" _binary()
{
  return binary_lit_impl<unsigned long long, Digits...>();
}

int main()
{
  signed short a = 110_binary;
  std::cout << a << std::endl;
 
  return 0;
}
