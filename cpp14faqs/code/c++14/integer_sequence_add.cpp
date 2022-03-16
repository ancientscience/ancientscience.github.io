#include <utility>

template<int N, typename T, T... I>
constexpr std::integer_sequence<T, N+I...>
add(std::integer_sequence<T, I...>) noexcept
{ 
    return {}; 
}

using orig_seq =
    std::integer_sequence<std::size_t, 1, 2, 3, 4, 5>;

using expected_seq =
    std::integer_sequence<std::size_t, 6, 7, 8, 9, 10>;

auto add5_seq = add<5>(orig_seq());

static_assert(std::is_same<decltype(add5_seq), expected_seq>::value, "");
