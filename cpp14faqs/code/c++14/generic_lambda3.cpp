template<typename T>
auto f = [](auto a, T b){ /**/ };

int main()
{
    f<int>(1, 2);
}
