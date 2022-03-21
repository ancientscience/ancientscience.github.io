#include <boost/iterator_adaptors.hpp>

template <typename ForwardIterator, 
          typename Predicate>
ForwardIterator 
first_max_element_if(ForwardIter first, 
                     ForwardIter last, 
                     Predicate pred)
{
    return first_max_element(
        boost::make_filter_iterator(first, last, 
                                    pred),
        boost::make_filter_iterator(last, last, 
                                    pred)
    );
}
