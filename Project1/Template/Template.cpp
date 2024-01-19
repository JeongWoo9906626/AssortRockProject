#include <iostream>

template<typename Type>
void Test(Type _Value)
{
    std::cout << *_Value << std::endl;
}

int main()
{
    int Value = 0;
    int* Ptr = &Value;

    bool bValue = false;
    bool* bPtr = &bValue;

    Test(Ptr);

    Test<int*>(Ptr);
    Test<bool*>(bPtr);
    Test<const char*>("AAA");
}