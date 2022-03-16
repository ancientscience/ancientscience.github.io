#include <utility>
#include <type_traits>

// generates std::size_t : 0, 1, 2, 3
using indices = 
    std::index_sequence_for<char, int, std::size_t, unsigned long>;

static_assert(std::is_same<
              indices,
              std::make_index_sequence<4>
             >::value, "");


struct A{};
struct B{};

static_assert(std::is_same<
    std::index_sequence_for<A, B>,
    std::index_sequence<0, 1>
>::value, "");
