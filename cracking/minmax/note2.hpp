std::reverse_iterator(
    first_min_element(v.begin(), v.end(),
                      std::less<int>())) 
== 
last_max_element(v.rbegin(), v.rend(),
                 std::greater<int>())
