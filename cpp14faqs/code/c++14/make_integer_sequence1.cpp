#include <utility>
#include <type_traits>

static_assert(std::is_same<
std::make_integer_sequence<int, 0>,
std::integer_sequence<int>
                >::value,
               "make empty int seq");

static_assert(std::is_same<
std::make_integer_sequence<int, 2>,
std::integer_sequence<int, 0, 1>
                >::value,
               "make non-empty int seq");

static_assert(std::is_same<
std::make_integer_sequence<unsigned, 0>,
std::integer_sequence<unsigned>
                >::value,
               "make empty unsigned seq");

static_assert(std::is_same<
std::make_integer_sequence<unsigned, 2>,
std::integer_sequence<unsigned, 0, 1>
                >::value,
               "make non-empty unsigned seq");

static_assert(std::is_same<
std::make_integer_sequence<unsigned long long, 0>, 
std::integer_sequence<unsigned long long>
                >::value, "");

static_assert(std::is_same<
std::make_integer_sequence<unsigned long long, 1>, 
std::integer_sequence<unsigned long long, 0>
                >::value, "");

static_assert(std::is_same<
std::make_integer_sequence<unsigned long long, 2>, 
std::integer_sequence<unsigned long long, 0, 1>
                >::value, "");

static_assert(std::is_same<
std::make_integer_sequence<unsigned long long, 3>, 
std::integer_sequence<unsigned long long, 0, 1, 2>
               >::value, "");
