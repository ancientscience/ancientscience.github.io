template <typename ForwardIterator>
std::pair<ForwardIterator, ForwardIterator>
first_min_first_max_element(
    ForwardIterator first, 
    ForwardIterator last)
{
    if (first == last) 
        return std::make_pair(last,last);

    ForwardIterator min_result, 
                    max_result = first;

    // if only one element
    ForwardIterator second = first; ++second;

    if (second == last) 
    return std::make_pair(min_result, 
                          max_result);

    // treat first pair separately 
    //(only one comparison for 
    //first two elements)
    ForwardIterator 
      potential_min_result = last;

    if (*first < *second) max_result = second;
    else 
    {
        min_result = second;
        potential_min_result = first;
    }

    // then each element by pairs, 
    // with at most 3 comparisons per pair
    first = ++second; 

    if (first != last) ++second;
    
    while (second != last) 
    {
        if (*first < *second) 
        {
            if (*first < *min_result) 
            {
                min_result = first;
                potential_min_result = last;
            }

            if (*max_result < *second) 
                max_result = second;
        } 
        else 
        {
            if (*second < *min_result) 
            {
                min_result = second;
                potential_min_result = first;
            }

            if (*max_result < *first) 
                max_result = first;
        }

        first = ++second;

        if (first != last) ++second;
    }

    // if odd number of elements, 
    //treat last element
    if (first != last) 
    { // odd number of elements
        if (*first < *min_result) 
        {
            min_result = first;
            potential_min_result = last;
        }
        else if (*max_result < *first) 
            max_result = first;
    }

    // resolve min_result being incorrect 
    // with one extra comparison
    // (in which case potential_min_result 
    // is necessarily the 
    // correct result)
    if (potential_min_result != last && 
        !(*min_result < *potential_min_result))
    min_result = potential_min_result;

    return 
      std::make_pair(min_result,max_result);
}
