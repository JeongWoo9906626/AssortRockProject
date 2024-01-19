#include <iostream>
#include <ConsoleEngine/EngineDebug.h>


template<typename DataType>
class CArray
{
public:
	// DataType = <int>
	CArray()
	{
	}

	// DataType = CArray<int>
	CArray(int _Size)
	{
		ReSize(_Size);
	}

	CArray(const CArray& _Other)
	{
		Copy(_Other);
	}

	~CArray()
	{
		Release();
	}

	void operator=(const CArray& _Other)
	{
		Copy(_Other);
	}

	DataType& operator[](int _Count)
	{
		return ArrPtr[_Count];
	}

	DataType& Test(int _Count)
	{
		return ArrPtr[_Count];
	}

	int Num()
	{
		return NumValue;
	}

	void Copy(const CArray& _Other)
	{
		NumValue = _Other.NumValue;
		ReSize(NumValue);
		for (int i = 0; i < NumValue; i++)
		{
			ArrPtr[i] = _Other.ArrPtr[i];
		}
	}

	void ReSize(int _Size)
	{
		if (0 >= _Size)
		{
			MsgBoxAssert("배열의 크기가 0일수 없습니다");
		}

		// Prev ArrPtr Address
		DataType* CopyArrPtr = ArrPtr;
		ArrPtr = new DataType[_Size];


		int CopyCount = _Size;
		if (NumValue < _Size)
		{
			CopyCount = NumValue;
		}

		for (int i = 0; i < CopyCount; i++)
		{
			ArrPtr[i] = CopyArrPtr[i];
		}
		NumValue = _Size;

		if (nullptr != CopyArrPtr)
		{
			delete[] CopyArrPtr;
			CopyArrPtr = nullptr;
		}
	}

	void Release()
	{
		if (nullptr != ArrPtr)
		{
			delete[] ArrPtr;
			ArrPtr = nullptr;
		}
	}

private:
	int NumValue = 0;
	DataType* ArrPtr = nullptr;
};

class Monster
{
public:
	void StatusRender()
	{
		std::cout << "StatusRender" << std::endl;
	}

private:
	int Att = 0;
	int Hp = 0;
};

int main()
{
	LeakCheck;
	{
		CArray<int> TestArray = CArray<int>(10);

		for (int i = 0; i < TestArray.Num(); i++)
		{
			TestArray[i] = i;
		}

		for (int i = 0; i < TestArray.Num(); i++)
		{
			std::cout << TestArray[i] << std::endl;
		}
	}

	{
		CArray<const char*> TestCharArray = CArray<const char*>(10);
		TestCharArray[0] = "AAAA";
		TestCharArray[1] = "BBBB";
		TestCharArray[2] = "CCCC";
		TestCharArray[3] = "DDDD";
		TestCharArray[4] = "EEEE";
		TestCharArray[5] = "FFFF";
		TestCharArray[6] = "GGGG";
		TestCharArray[7] = "HHHH";
		TestCharArray[8] = "IIII";
		TestCharArray[9] = "JJJJ";

		for (int i = 0; i < TestCharArray.Num(); i++)
		{
			std::cout << TestCharArray[i] << std::endl;
		}
	}

	{
		CArray<Monster> TestMonsterArray = CArray<Monster>(10);
		for (int i = 0; i < TestMonsterArray.Num(); i++)
		{
			TestMonsterArray[i].StatusRender();
		}
	}

	{
		CArray<CArray<int>> TestArray = CArray<CArray<int>>(10);

		for (int i = 0; i < TestArray.Num(); i++)
		{
			TestArray[i].ReSize(10);
		}

		for (int y = 0; y < 10; y++)
		{
			for (int x = 0; x < 10; x++)
			{
				TestArray[y][x] = x;
			}
		}

		for (int y = 0; y < 10; y++)
		{
			for (int x = 0; x < 10; x++)
			{
				std::cout << TestArray[y][x];
			}

			std::cout << std::endl;
		}
	}
}