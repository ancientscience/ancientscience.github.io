#include <memory>
#include <type_traits>
#include <iostream>

template<class T>
struct unique_type
{
    typedef std::unique_ptr<T> single_object;
};

template<class T, std::size_t N>
struct unique_type<T[N]>
{
    typedef std::unique_ptr<T[]> fixed_array;

    template <typename... Args>
    static inline fixed_array make(Args&&... args) 
    {
        static_assert(N >= sizeof...(Args),
        "make_unique<T[N]> : no of arguments can't be more than N");
        return fixed_array(new T[N]{std::forward<Args>(args)...});
  }
};

template<typename T, class... Args> 
typename unique_type<T>::fixed_array
make_unique_fixed_array(Args&&... args) 
{
    return unique_type<T>::make(std::forward<Args>(args)...);
}


int main()
{
    auto up = make_unique_fixed_array<int[5]>(1, 2, 3, 4, 5, 6);
}
