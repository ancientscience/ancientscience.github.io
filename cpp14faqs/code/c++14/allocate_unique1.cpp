#include <type_traits>
#include <utility> 
#include <memory>
#include <iostream>


template <class T>
inline T* to_raw_pointer(T* p) noexcept
{
    return p;
}


template <class Pointer>
inline typename std::pointer_traits<Pointer>::element_type*
to_raw_pointer(Pointer p) noexcept
{
    return to_raw_pointer(p.operator->());
}


template <class Allocator>
struct alloc_deleter : Allocator
{
public:
    typedef Allocator allocator_type;
    typedef std::allocator_traits<allocator_type> traits;
    typedef typename traits::pointer pointer;

    explicit alloc_deleter(const allocator_type& a)
        : allocator_type(a) {}

    void operator()(pointer p)
    {
        traits::destroy(*this, to_raw_pointer(p));
        traits::deallocate(*this, p, 1);
    }
};


template <class T, class Allocator, class ...Args>
std::unique_ptr<T, alloc_deleter<Allocator>>
allocate_unique(const Allocator& a, Args&& ...args)
{
    typedef alloc_deleter<Allocator> A;
    static_assert(sizeof(T) == sizeof(typename A::value_type),
                  "Allocatorator has incorrect value_type");
    A alloc(a);
    auto p = std::allocator_traits<A>::allocate(alloc, 1);
    try
    {
        std::allocator_traits<A>::construct(
            alloc, to_raw_pointer(p), std::forward<Args>(args)...
                                           );
    }
    catch (...)
    {
        std::allocator_traits<A>::deallocate(alloc, p, 1);
        throw;
    }
    return std::unique_ptr<T, A>(p, alloc);
}


struct A
{
    A() {std::cout << "A() called \n";}
    ~A() {std::cout << "~A() called \n";}

    void f() {std::cout << "A::f() called\n";}
}; 


int main()
{
  auto up = allocate_unique<A>(std::allocator<A>());
  up->f(); 
  
  std::allocator<int> a;
  auto p = allocate_unique<int>(a, 0);
  return *p;
}
