#include <utility>
#include <type_traits>

// generates empty integer sequence
static_assert(std::integer_sequence<int>::size() == 0, "size of std::integer_sequence<int> should be zero");

// generates int : 0, 1, 2, 3, 4, 5
static_assert(std::integer_sequence<int, 0, 1, 2, 3, 4, 5>::size() == 6, "");

static_assert(std::is_same<std::integer_sequence<int>::value_type, int>::value, "");

// generates unsigned short : 3, 8
using ushort2 = 
    std::integer_sequence<unsigned short, 3, 8>;

static_assert(std::is_same<ushort2::value_type, unsigned short>::value, "");
static_assert(ushort2::size() == 2, "");

static_assert(std::is_same<std::integer_sequence<bool>::value_type, bool>::value, "");


