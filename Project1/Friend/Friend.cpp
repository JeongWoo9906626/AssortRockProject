#include <iostream>

class A
{
    friend void C::Test(A& _Other);
private:
    int Value;
};

class B
{
private:
    int Value;
};

class C
{
public:
    void Test(A& _Other)
    {
        _Other.Value;
    }

    void Test(B& _Other)
    {
        _Other.Value;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}