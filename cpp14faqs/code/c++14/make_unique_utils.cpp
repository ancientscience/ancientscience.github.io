#include <memory>
#include <type_traits>
#include <iostream>

template<class T, class... Args> 
typename std::unique_ptr<T[]>
make_unique_deduce_length(Args&&... args) 
{
        return std::unique_ptr<T>(new typename std::remove_extent<T>::type[sizeof...(Args)]{ std::forward<Args>(args)... });
}


int main()
{
    auto up = make_unique_deduce_length<int[]>(1, 2, 3, 4, 5);

    for (int i = 0; i < 5; ++i) 
    {
        std::cout << up[i] << " ";
    }
    std::cout << std::endl;
}
