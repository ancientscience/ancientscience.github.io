struct Closure 
{
    template<class T> auto operator()(T t) const { ... }
    template<class T> static auto lambda_call_operator_invoker(T a) 
    {
        // forwards execution to operator()(a) and therefore has
        // the same return type deduced                                  
        ...
    }

    template<class T> using fptr_t =
       decltype(lambda_call_operator_invoker(declval<T>())) (*)(T);

    template<class T> operator fptr_t<T>() const
    { 
        return &lambda_call_operator_invoker;
    }
};
