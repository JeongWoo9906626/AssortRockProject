#include <iostream>

void MoveClick()
{
    printf_s("Move\n");
}

void AttackClick()
{
    printf_s("Attack\n");
}

class Button
{
public:
    virtual void Click()
    {
        Function();
    }

    void SetFucntion(void (*_Function)())
    {
        Function = _Function;
    }

private:
    void (*Function)() = nullptr;
};

int main()
{
    Button AttackButton;
    Button MoveButton;

    AttackButton.SetFucntion(AttackClick);
    MoveButton.SetFucntion(MoveClick);

    AttackButton.Click();
    MoveButton.Click();
}