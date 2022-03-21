template <typename ForwardIterator>
ForwardIterator first_max_element(
    ForwardIter first, ForwardIter last)
{
    if (first == last) return last;
    ForwardIter max_result = first;
    while (++first != last)
    {
        if (*max_result < *first) 
            max_result = first;
    }
    return max_result;
}
