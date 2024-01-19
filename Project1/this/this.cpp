// this.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class Player
{
public:
	int Att = 10;
	int Hp = 100;

	void Damage(int _Damage)
	{
		Hp -= _Damage;
	}
};

// 문법적으로는 차이점이 있음
// 결과적으로는 차이점이 없음
// void Damage(Player* const this, int Damage);
// 자기 자신의 포인터가 첫번째 인자로 들어옴 (생략)
void Damage(Player* _this, int Damage)
{
	// 클래스를 포인터로 사용할 때는 -> 로 사용
	if (nullptr == _this)
	{
		return;
	}

	_this->Hp -= Damage;
}

int main()
{
	Player NewPlayer0 = Player();
	Player NewPlayer1 = Player();

	NewPlayer0.Damage(10);
	NewPlayer1.Damage(20);

	Damage(&NewPlayer0, 10);
	Damage(&NewPlayer1, 20);
}
