#include <utility>

template<typename T, T I0, T... I>
constexpr std::integer_sequence<T, I0>
split1(std::integer_sequence<T, I0, I...>) noexcept
{ 
    return {}; 
}


template<typename T, T I0, T... I>
constexpr std::integer_sequence<T, I...>
split2(std::integer_sequence<T, I0, I...>) noexcept
{ 
    return {}; 
}


using orig_seq =
    std::integer_sequence<std::size_t, 1, 2, 3, 4, 5>;

using expected_seq1 =
    std::integer_sequence<std::size_t, 1>;

using expected_seq2 =
    std::integer_sequence<std::size_t, 2, 3, 4, 5>;

auto seq1 = split1(orig_seq());
auto seq2 = split2(orig_seq());

static_assert(std::is_same<decltype(seq1), expected_seq1>::value, "");
static_assert(std::is_same<decltype(seq2), expected_seq2>::value, "");
