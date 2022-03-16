#include <tuple>
#include <utility>
#include <iostream>


template<typename F, typename Tuple, std::size_t... I>
auto apply_(F&& f, Tuple&& args, std::index_sequence<I...>)
noexcept(noexcept(std::forward<F>(f)(std::get<I>(std::forward<Tuple>(args))...)))
    -> decltype(std::forward<F>(f)(std::get<I>(std::forward<Tuple>(args))...))
{
    return std::forward<F>(f)(std::get<I>(std::forward<Tuple>(args))...);
}


template<typename F, typename Tuple, typename Indices
    = std::make_index_sequence<std::tuple_size<typename std::decay<Tuple>::type>::value>>
auto apply(F&& f, Tuple&& args)
noexcept(noexcept(apply_(std::forward<F>(f), std::forward<Tuple>(args), Indices())))
    -> decltype(apply_(std::forward<F>(f), std::forward<Tuple>(args), Indices()))
{
    return apply_(std::forward<F>(f), std::forward<Tuple>(args), Indices());
}


void f(int x)
{
    std::cout << x << std::endl;
}

void f(std::tuple<int, int, int> & t)
{
    
}


int main()
{
    auto t = std::make_tuple(1, 2, 3, 4, 5);

    apply(f, t);
}
