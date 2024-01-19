#pragma once
#include "NameUnit.h"

class StatusUnit : public NameUnit
{
public:
	void StatusRender();

	inline void HpReset()
	{
		Hp = MaxHp;
	}

	inline void AddGold(int _Gold)
	{
		Gold += _Gold;
	}

	inline int GetGold() 
	{
		return Gold;
	}

	inline int GetExp()
	{
		return Exp;
	}


	void RandomGold(int _Min, int _Max);
	void RandomExp(int _Min, int _Max);
	int RandomValue(int _Min, int _Max);
	void StatusInit(int _Hp, int _MinAtt, int _MaxAtt);
	void SetHp(int _Value);
	void SetMaxHp(int _Value);
	void SetMinAtt(int _Value);
	void SetMaxAtt(int _Value);

	virtual void StatusRenderStart();
	virtual void StatusRenderBase();
	virtual void StatusRenderEnd();

protected:
	int Hp = 100;
	int MaxHp = 100;
	int MinAtt = 10;
	int MaxAtt = 20;
	int Speed = 20; // 0~20
	int Gold = 0;
	int Exp = 0;
};

