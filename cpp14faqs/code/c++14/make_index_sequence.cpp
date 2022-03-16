#include <utility>
#include <type_traits>

static_assert(std::is_same<
std::make_index_sequence<0>,
std::integer_sequence<std::size_t>
                >::value, "");

static_assert(std::is_same<
std::make_index_sequence<2>,
std::integer_sequence<std::size_t, 0, 1>
                >::value, "");


static_assert(std::is_same<
std::make_index_sequence<3>, 
std::integer_sequence<std::size_t, 0, 1, 2>
               >::value, "");
