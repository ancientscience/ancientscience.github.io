#include <memory>
#include <iostream>

template<typename Allocator>
struct alloc_deleter
{
  alloc_deleter(const Allocator& a) : a(a) { }

  typedef typename std::allocator_traits<Allocator>::pointer pointer;

  void operator()(pointer p) const
  {
    Allocator aa(a);
    std::allocator_traits<Allocator>::destroy(aa, std::addressof(*p));
    std::allocator_traits<Allocator>::deallocate(aa, p, 1);
  }

private:
  Allocator a;
};

template<typename T, typename Allocator, typename... Args>
auto
allocate_unique(const Allocator& alloc, Args&&... args)
{
  using AT = std::allocator_traits<Allocator>;
  static_assert(std::is_same<typename AT::value_type, std::remove_cv_t<T>>{}(),
                "Allocatorator has incorrect value_type");

  Allocator a(alloc);
  auto p = AT::allocate(a, 1);
  try {
    AT::construct(a, std::addressof(*p), std::forward<Args>(args)...);
    using D = alloc_deleter<Allocator>;
    return std::unique_ptr<T, D>(p, D(a));
  }
  catch (...)
  {
    AT::deallocate(a, p, 1);
    throw;
  }
}


struct A
{
    A() {std::cout << "A() called\n";}
    ~A() {std::cout << "~A() called\n";}

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
