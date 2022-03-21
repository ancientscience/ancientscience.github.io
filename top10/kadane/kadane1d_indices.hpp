#include <algorithm>
#include <tuple>

template <typename ForwardIterator>
std::tuple<typename std::iterator_traits<
                 ForwardIterator
             >::value_type, 
           ForwardIterator, ForwardIterator>
kadane1d(ForwardIterator start, 
         ForwardIterator end)
{
    typedef typename std::iterator_traits<
                    ForwardIterator
                >::value_type value_type;

    int max_so_far = 0, max_ending_here = 0;

    ForwardIterator starti, 
                sum_start, sum_end = start;

    while(start != end)
    {
        max_ending_here += *start;

        if(max_ending_here < 0)
        {
            max_ending_here = 0;
            starti = start;
            ++starti;
        }

        if(max_so_far < max_ending_here)
        {
            max_so_far = max_ending_here;
            sum_start = starti;
            sum_end = start;
        }
        ++start;
    }

    return std::make_tuple(max_so_far, 
                           sum_start, 
                           sum_end);
}
