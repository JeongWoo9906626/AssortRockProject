#include <iostream>
#include <vector>
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

template<typename DataType>
class MyVector
{
public:
	void resize(int _Size)
	{
		SizeValue = _Size;
		Array.Resize(_Size);
	}

	void reserve(int _Size)
	{
		Array.Resize(_Size);
	}

	DataType& operator[](size_t _Index)
	{
		if (size() <= _Index)
		{
			MsgBoxAssert("인덱스를 넘겨서 접근하려고 했습니다.");
		}
		return Array[_Index];
	}

	void push_back(const DataType& _Data)
	{
		if (capacity() <= SizeValue + 1)
		{
			Array.Resize(Array.Num() * 2);
		}
		Array[SizeValue] = _Data;
		++SizeValue;
	}

	size_t capacity()
	{
		return Array.Num();
	}
	size_t size()
	{
		return SizeValue;
	}

	void clear()
	{
		SizeValue = 0;
	}
protected:

private:
	int SizeValue = 0;
	CArray<int> Array;
};

int main()
{
    std::vector<int> ArrVector = std::vector<int>();

	ArrVector.reserve(5);
	int capacity = ArrVector.capacity();
	ArrVector.push_back(1);

    //ArrVector.resize(10);
	
	for (int i = 0; i < static_cast<int>(ArrVector.size()); i++)
	{
		ArrVector[i] = i;
	}

	for (int i = 0; i < static_cast<int>(ArrVector.size()); i++)
	{
		std::cout << ArrVector[i] << std::endl;
	}
}