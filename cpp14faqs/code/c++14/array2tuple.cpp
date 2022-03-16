#include <utility>
#include <tuple>
#include <array>
#include <cassert>

template<typename Array, size_t... I>
auto array_to_tuple_(const Array& a, std::index_sequence<I...>)
    -> decltype(std::make_tuple(a[I]...))
{
    return std::make_tuple(a[I]...);
}


template<typename T, std::size_t N, typename Indices = std::make_index_sequence<N>>
auto array_to_tuple(const std::array<T, N>& a)
    -> decltype(array_to_tuple_(a, Indices()))
{
    return array_to_tuple_(a, Indices());
}


int main()
{
    std::array<int, 5> a = {1, 2, 3, 4, 5};

    auto t = array_to_tuple(a);

    auto t1 = std::make_tuple(1, 2, 3, 4, 5);

    assert(t == t1);
}
