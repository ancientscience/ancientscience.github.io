#include <utility>

template<int N, typename T, T... I>
constexpr std::integer_sequence<T, N*I...>
multiply(std::integer_sequence<T, I...>) noexcept
{ 
    return {}; 
}

using orig_seq =
    std::integer_sequence<std::size_t, 1, 2, 3, 4, 5>;

using expected_seq =
    std::integer_sequence<std::size_t, 5, 10, 15, 20, 25>;

auto mult5_seq = multiply<5>(orig_seq());

static_assert(std::is_same<decltype(mult5_seq), expected_seq>::value, "");
