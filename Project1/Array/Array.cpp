#include <iostream>
#include <ConsoleEngine/EngineDebug.h>

class IntArray
{
public:
    IntArray(int _Size)
    {
        ReSize(_Size);
    }

    IntArray(const IntArray& _Other)
    {
        Copy(_Other);
    }

    ~IntArray()
    {
        Release();
    }

    void operator=(const IntArray& _Other)
    {
        Copy(_Other);
    }

    int& operator[](int _Count)
    {
        return ArrPtr[_Count];
    }

    int& Test(int _Count)
    {
        return ArrPtr[_Count];
    }

    int Num()
    {
        return NumValue;
    }

    void Copy(const IntArray& _Other)
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
        int* CopyArrPtr = ArrPtr;
        ArrPtr = new int[_Size];
    

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
    int* ArrPtr = nullptr;
};

int main()
{
    LeakCheck;

    IntArray NewArray0 = IntArray(5);

    for (int i = 0; i < NewArray0.Num(); i++)
    {
        NewArray0[i] = i;
    }

    NewArray0.ReSize(3);

    for (int i = 0; i < NewArray0.Num(); i++)
    {
        std::cout << NewArray0[i] << std::endl;
    }

    NewArray0.ReSize(10);
    for (int i = 0; i < NewArray0.Num(); i++)
    {
        std::cout << NewArray0[i] << std::endl;
    }
}
