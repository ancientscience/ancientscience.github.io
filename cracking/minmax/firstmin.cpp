template <typename ForwardIterator>
ForwardIterator first_min_element(
    ForwardIter first, ForwardIter last)
{
    if (first == last) return last;
    ForwardIter min_result = first;
    while (++first != last)
    {
        if (*first < *min_result) 
            min_result = first;
    }
    return min_result;
}
