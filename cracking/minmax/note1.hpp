std::min_element(v.begin(), v.end(),
                 std::less<int>()) 
== 
std::max_element(v.begin(), v.end(),
                 std::greater<int>())
