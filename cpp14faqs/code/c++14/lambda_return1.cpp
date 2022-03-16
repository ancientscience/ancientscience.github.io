auto x1 = [](int i){ return i; }; 
auto x2 = []{ return { 1, 2 }; }; 
                                  
int j;
auto x3 = []()->auto&& { return j; };
