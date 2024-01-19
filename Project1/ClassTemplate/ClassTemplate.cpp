#include <iostream>

template<typename MemberType>
class TemplateClass
{
private:
    MemberType Value;
};

int main()
{
    TemplateClass<int> NewType;
    TemplateClass<int> NewType2;

    NewType = NewType2;
}