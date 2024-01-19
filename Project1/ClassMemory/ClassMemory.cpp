// ClassMemory.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class Test1
{
public:
	int b;
	bool a;
	bool c;
	__int64 d;
};

class Test2
{
public:
	short a;
};

class A
{
public:
	Test1 t1;
	Test2 t2;
};
class J
{
public:
	bool Test0;
	int Test1;
	__int64 Test2;
};
int main()
{
	printf_s("%lld", sizeof(Test1));
}
