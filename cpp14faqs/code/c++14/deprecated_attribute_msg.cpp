class [[deprecated("Usage of class A is deprecated. Please class X instead.")]] A1 {};

[[deprecated("Usage of func1 is deprecated. Please use func2 instead.")]]
void func1() {}

int main()
{
    A1 a;
    func1();
}
