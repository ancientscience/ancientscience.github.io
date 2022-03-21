template <typename ForwardIterator>
ForwardIterator last_max_element(
    ForwardIter first, ForwardIter last)
{
    if (first == last) return last;
    ForwardIter max_result = first;
    while (++first != last)
    {
        if (*first < *max_result) 
        max_result = first;
    }
    return max_result;
}
