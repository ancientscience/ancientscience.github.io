template<class T1, class T2 = T1>
inline T1 exchange(T1 & obj, T2 && new_value)
{
    T1 old_value = std::move(obj);

    obj = std::forward<T2>(new_value);

    return old_value;
}
