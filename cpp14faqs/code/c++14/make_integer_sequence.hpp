namespace integer_sequence_internals 
{

template <typename T, size_t... Extra>
struct repeat;

template <typename T, T... Is, size_t... Extra>
struct repeat<integer_sequence<T, Is...>, Extra...>
{
    using type =  integer_sequence<T, Is...,
        1 * sizeof...(Is) + Is...,
        2 * sizeof...(Is) + Is...,
        3 * sizeof...(Is) + Is...,
        4 * sizeof...(Is) + Is...,
        5 * sizeof...(Is) + Is...,
        6 * sizeof...(Is) + Is...,
        7 * sizeof...(Is) + Is...,
        Extra...>;
};

template <size_t N>
struct parity;

template <size_t N>
struct make
  : parity<N % 8>::template pmake<N> {};

template <> struct make<0> { using type = integer_sequence<size_t>; };
template <> struct make<1> { using type = integer_sequence<size_t, 0>; };
template <> struct make<2> { using type = integer_sequence<size_t, 0, 1>; };
template <> struct make<3> { using type = integer_sequence<size_t, 0, 1, 2>; };
template <> struct make<4> { using type = integer_sequence<size_t, 0, 1, 2, 3>; };
template <> struct make<5> { using type = integer_sequence<size_t, 0, 1, 2, 3, 4>; };
template <> struct make<6> { using type = integer_sequence<size_t, 0, 1, 2, 3, 4, 5>; };
template <> struct make<7> { using type = integer_sequence<size_t, 0, 1, 2, 3, 4, 5, 6>; };

template <> struct parity<0> { template <size_t N> struct pmake : repeat<typename make<N / 8>::type> {}; };
template <> struct parity<1> { template <size_t N> struct pmake : repeat<typename make<N / 8>::type, N - 1> {}; };
template <> struct parity<2> { template <size_t N> struct pmake : repeat<typename make<N / 8>::type, N - 2, N - 1> {}; };
template <> struct parity<3> { template <size_t N> struct pmake : repeat<typename make<N / 8>::type, N - 3, N - 2, N - 1> {}; };
template <> struct parity<4> { template <size_t N> struct pmake : repeat<typename make<N / 8>::type, N - 4, N - 3, N - 2, N - 1> {}; };
template <> struct parity<5> { template <size_t N> struct pmake : repeat<typename make<N / 8>::type, N - 5, N - 4, N - 3, N - 2, N - 1> {}; };
template <> struct parity<6> { template <size_t N> struct pmake : repeat<typename make<N / 8>::type, N - 6, N - 5, N - 4, N - 3, N - 2, N - 1> {}; };
template <> struct parity<7> { template <size_t N> struct pmake : repeat<typename make<N / 8>::type, N - 7, N - 6, N - 5, N - 4, N - 3, N - 2, N - 1> {}; };

template <typename T, typename U>
struct convert
{
    template <typename>
    struct result;

    template <T ...Is>
    struct result<integer_sequence<T, Is...>>
    {
        using type = integer_sequence<U, Is...>;
    };
};

template <typename T>
struct convert<T, T>
{
    template <typename U>
    struct result
    {
        using type = U;
    };
};

template <typename T, T N>
using make_integer_sequence_unchecked =
    typename convert<size_t, T>::template result<typename make<N>::type>::type;
 
template <typename T, T N>
struct make_integer_sequence
{
    static_assert(std::is_integral<T>::value,
        "std::make_integer_sequence can only be instantiated with an integral type");
    static_assert(0 <= N, "std::make_integer_sequence input shall not be negative");
 
    using type = make_integer_sequence_unchecked<T, N>;
};

} // namespace integer_sequence_internals

template <typename T, T N>
using make_integer_sequence = typename integer_sequence_internals::make_integer_sequence<T, N>::type;
