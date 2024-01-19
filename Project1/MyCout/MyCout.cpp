#include <iostream>

namespace std
{
    class MyStream
    {
    public:
        void operator <<(const char* _Text)
        {
            printf_s(_Text);
        }
    };

    extern MyStream mycout;
}

std::MyStream mycout;

int main()
{
    std::mycout << "Hello World!\n";
    std::mycout.operator<<("Hello World!\n");
    std::cout.operator<<("Hi");
}