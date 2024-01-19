// RefEx.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class Test
{
public:
    int& Ref;
};

int main()
{
    int Value0 = 0;
    int& Ref = Value0;

    int Value1 = 2;
    Ref = Value1;

    Ref = 50;
    // 레퍼런스는 무조건 초기화 하는 순간 값을 넣어줘야 함
}
