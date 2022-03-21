template <typename ForwardIterator>
std::pair<ForwardIterator,ForwardIterator>
first_min_last_max_element(
    ForwardIterator first, 
    ForwardIterator last)
{
    if (first == last) 
        return std::make_pair(last,last);

    ForwardIterator min_result, 
                    max_result = first;

    ForwardIterator second = ++first;

    if (second == last) 
    return std::make_pair(min_result, 
                          max_result);

    if (*second < *min_result) 
        min_result = second;
    else max_result = second;

    first = ++second; 

    if (first != last) ++second;

    while (second != last) 
    {
        if (!(*second < *first)) 
        {
            if (*first < *min_result) 
                min_result = first;
            if (!(*second < *max_result)) 
                max_result = second;
        } 
        else 
        {
            if (*second < *min_result) 
                min_result = second;
            if (!(*first < *max_result)) 
                max_result = first;
        }

        first = ++second; 

        if (first != last) ++second;
    }

    if (first != last) 
    {
        if (*first < *min_result) 
            min_result = first;
        else if (!(*first < *max_result)) 
            max_result = first;
    }
    return std::make_pair(min_result, max_result);
}
