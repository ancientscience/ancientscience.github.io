#include <utility>
#include <type_traits>

// generates size_t : 1, 1, 2, 3, 5
using indices = 
    std::index_sequence<1, 1, 2, 3, 5>; 

using indices1 = 
    std::integer_sequence<std::size_t, 1, 1, 2, 3, 5>;

static_assert(std::is_same<
    indices::value_type, 
    std::size_t
>::value, "");

static_assert(indices::size() == 5, "");

static_assert(std::is_same<
    indices, 
    indices1
>::value, "");
