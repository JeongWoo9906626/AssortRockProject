#include <iostream>
#include <list>
#include <string>
using namespace std;

class Test
{
public:
    int Value = 0;
    void Function()
    {
        this->Value = 20;
    }
};

int main(void) 
{
    Test* NewTest = nullptr;
    NewTest->Function();

    int a = 0;
}