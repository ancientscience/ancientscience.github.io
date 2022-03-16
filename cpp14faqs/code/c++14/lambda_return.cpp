struct A 
{ 
    int f(); 
    const int& g(); 
};

template <class T> 
void h () 
{
    [](T t, bool b)
    {
        if (b)
            return t.f();
        else
            return t.g();
    };
}

template void h<A>();
