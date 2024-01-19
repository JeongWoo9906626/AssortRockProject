#include <iostream>

void Test(int& _Data)
{
    if (100 <= _Data)
    {
        return;
    }
    std::cout << _Data << std::endl;
    ++_Data;
    Test(_Data);
}

int main()
{
    int Value;

    Test(Value);
}