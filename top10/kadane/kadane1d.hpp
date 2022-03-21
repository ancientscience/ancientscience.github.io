#include <algorithm>

template <typename ForwardIterator>
typename std::iterator_traits<
    ForwardIterator>::value_type
kadane1d(ForwardIterator start, 
         ForwardIterator end)
{
    typedef typename std::iterator_traits<
            ForwardIterator
        >::value_type value_type;

    value_type max_so_far = 0, 
               max_ending_here = 0;

    while(start != end)
    {
        max_ending_here = 
          std::max(max_ending_here + *start++, 
                  0);
        max_so_far = 
        std::max(max_so_far, max_ending_here);
    }
    return max_so_far;
}
