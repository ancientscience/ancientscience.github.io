template <typename ForwardIterator>
ForwardIterator last_min_element(
    ForwardIter first, ForwardIter last)
{
    if (first == last) return last;
    ForwardIter min_result = first;
    while (++first != last)
    {
        if (*min_result < *first) 
            min_result = first;
    }
    return min_result;
}
